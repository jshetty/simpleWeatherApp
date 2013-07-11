  #include "applicationui.hpp"

    /*
     Constructs an RSSFeed object and connects the needed signals.
     */
    RSSFeed::RSSFeed(QObject *parent)
        : QObject(parent)
        , m_url("http://weather.yahooapis.com/forecastrss?w=22174742&u=c")
        , m_active(false)
        , m_currentReply(0)
    {
        // Invoke the finished() method whenever the download job has been finished
        connect(&m_manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(finished(QNetworkReply*)));
    }

    /*
     Starts the network request and connects the needed signals
     */
    void RSSFeed::get(const QUrl &url)
    {
        QNetworkRequest request(url);
        if (m_currentReply) {
            m_currentReply->disconnect(this);
            m_currentReply->deleteLater();
        }

        m_currentReply = m_manager.get(request);
        connect(m_currentReply, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(m_currentReply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(error(QNetworkReply::NetworkError)));

    }

    /*
     Starts fetching data from a weather source specified in m_url.

     The UI is made read only to prevent the user from modifying its
     contents during the fetch; this is only for cosmetic purposes.

     A URL is created with the raw contents of m_url and
     a get is initiated.
     */

    void RSSFeed::fetch()
    {
        m_active = true;
        emit activeChanged();

        m_xml.clear();

        const QUrl url(m_url);
        get(url);
    }

    /*
     Reads data received from the RDF source.
     We read all the available data, and pass it to the XML
     stream reader.
     */

    void RSSFeed::readyRead()
    {
        const int statusCode = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode >= 200 && statusCode < 300) {
            const QByteArray data = m_currentReply->readAll();
            m_xml.addData(data);
        }
    }

    /*
     Finishes processing an HTTP request.

     If an error has occurred, the user interface is made available
     to the user for further input, allowing a new fetch to be
     started.

     If the HTTP get request has finished, make the
     user interface available to the user for further input.
     */

    void RSSFeed::finished(QNetworkReply *reply)
    {
        Q_UNUSED(reply);

        parseXml();

        m_active = false;
        emit activeChanged();
    }

    void RSSFeed::setUrl(const QString &url)
    {
        if (m_url == url)
            return;

        m_url = url;
        emit urlChanged();
    }

    QString RSSFeed::url() const
    {
        return m_url;
    }

    QString RSSFeed::feeds() const
    {
        return m_feeds;
    }

    bool RSSFeed::active() const
    {
        return m_active;
    }

    /*
     Parses the XML data and fill feeds string accordingly.
     */
    void RSSFeed::parseXml()
    {
        m_feeds.clear();

        QString currentTag;
        QString descString;
        QString titleString;
        QStringList keyList;


        while (!m_xml.atEnd()) {
            m_xml.readNext();
            if (m_xml.isStartElement()) {
                if (m_xml.name() == "item")
                    descString = m_xml.attributes().value("rss:about").toString();
                currentTag = m_xml.name().toString();
            } else if (m_xml.isEndElement()) {
                if (m_xml.name() == "item") {

                    m_feeds.append(QString::fromLatin1("%1\n      %2\n\n").arg(titleString, descString));

                    titleString.clear();
                    descString.clear();
                }

            } else if (m_xml.isCharacters() && !m_xml.isWhitespace()) {
                if (currentTag == "title")
                   titleString += m_xml.text().toString();
                else if (currentTag == "description"){
                  descString += m_xml.text().toString();

                  keyList = descString.split(QRegExp("<[^>]*>"));
                  descString.clear();

                  foreach(QString itm, keyList) {
                	  if(itm.contains(QRegExp("[0-9]{1,2}$"))){
                	       int pos = itm.indexOf(QRegExp("[0-9]{1,2}"));
                	       itm.insert(pos+2, " ºC");
                	       descString += itm;
                	       pos = descString.lastIndexOf(QRegExp("[0-9]{1,2}"));
                	       descString.insert(pos+1," ºC");
                	   } else if(itm.contains(QRegExp("[0-9]{1,2} C"))){
               	       int pos = itm.lastIndexOf(QRegExp("[0-9]{1,2}"));
               	       itm.replace(pos+1,2," ºC");
               	       descString += itm;
               	       } else
                	  descString +=itm;
                  }
               }
            }
        }

        if (m_xml.error() && m_xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
            m_feeds.append(
                    QString::fromLatin1("XML ERROR: %1: %2").arg(m_xml.lineNumber()).arg(m_xml.errorString()));
        }

        emit feedsChanged();
    }

    void RSSFeed::error(QNetworkReply::NetworkError)
    {
        m_feeds = QLatin1String("error retrieving RSS feed");
        emit feedsChanged();

        m_currentReply->disconnect(this);
        m_currentReply->deleteLater();
        m_currentReply = 0;
    }

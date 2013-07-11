 #ifndef RSSFeed_HPP
    #define RSSFeed_HPP

    #include <QtCore/QBuffer>
    #include <QtCore/QUrl>
    #include <QtCore/QXmlStreamReader>
    #include <QtNetwork/QNetworkAccessManager>
    #include <QtNetwork/QNetworkReply>
	#include <QStringList>
	#include <QRegExp>
    #include <bb/cascades/ListView>

    /**
     * The RSSFeed class encapsulates the download and parsing of
     * the RSS feed. The feed URL and the extracted articles are available
     * to the UI via properties.
     */
    class RSSFeed : public QObject
    {
        Q_OBJECT

        // The URL where the RSS feed is downloaded from
        Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)

        // Makes the extracted articles available to the UI
        Q_PROPERTY(QString feeds READ feeds NOTIFY feedsChanged)

        // Makes the state of the RSSFeed available to the UI
        Q_PROPERTY(bool active READ active NOTIFY activeChanged)


    public:
        RSSFeed(QObject *object = 0);

    public Q_SLOTS:
        // This method is invoked from the UI to start the download of the RSS feed
        void fetch();

    Q_SIGNALS:
        // The change notification signals of the properties
        void urlChanged();
        void feedsChanged();
        void activeChanged();

    private Q_SLOTS:
        // This method is called when the feed has been downloaded
        void finished(QNetworkReply *reply);

        // This method is called whenever weather data from the feed have been received
        void readyRead();

        // This method is called if an network related error occurred
        void error(QNetworkReply::NetworkError);

    private:
        // The accessor methods of the properties
        void setUrl(const QString &url);
        QString url() const;

        QString feeds() const;

        bool active() const;

        // This method parses the RSS feed after it has been downloaded
        void parseXml();

        // This method triggers the actual download of the RSS feed
        void get(const QUrl &url);

        // The property values
        QString m_url;
        QString m_feeds;
        bool m_active;

        // The XML stream reader that is used to extract the articles from the RSS feed
        QXmlStreamReader m_xml;


        // The network manager that is used to download the RSS feed
        QNetworkAccessManager m_manager;

        // The network reply that represents the current download job
        QNetworkReply *m_currentReply;
    };

    #endif

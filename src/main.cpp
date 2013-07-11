    #include <bb/cascades/Application>
    #include <bb/cascades/Control>
    #include <bb/cascades/QmlDocument>
    #include <bb/cascades/Page>

    #include "applicationui.hpp"

    using namespace ::bb::cascades;

    /**
     * The user can define a feed URL in the UI and after clicking 'Fetch' button, the weather
     * will be shown.
     */
    Q_DECL_EXPORT int main(int argc, char **argv)
    {
        Application app(argc, argv);

        // Create the business logic object
       RSSFeed RSSFeed;

        QmlDocument *qml = QmlDocument::create("asset:///main.qml");
        if (!qml->hasErrors()) {

            qml->setContextProperty("_RSSFeed", &RSSFeed);
            Page *appPage = qml->createRootObject<Page>();

         if (appPage) {
                Application::instance()->setScene(appPage);
          }
        }

        return Application::exec();
    }

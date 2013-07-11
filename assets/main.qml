import bb.cascades 1.0

// Page to display Weather items
Page {
    //Page refresh action
    actions: [
        ActionItem {
            objectName: "refresh"
            title: "Refresh"
            onTriggered: _RSSFeed.fetch()
            ActionBar.placement: ActionBarPlacement.OnBar
            
        }
    ]
    actionBarVisibility: ChromeVisibility.Visible
    Container {
        
        layout: StackLayout {
            
        }

        topPadding: 50.0
        Label {
        	 id: weatherID
        	  text: "Weather Update"
            textFormat: TextFormat.Auto
            verticalAlignment: VerticalAlignment.Top
            horizontalAlignment: HorizontalAlignment.Center
            topMargin: 50.0
            layoutProperties: AbsoluteLayoutProperties {
                positionY: 0.3

            }
            textStyle.fontWeight: FontWeight.W600
            textStyle.lineHeight: 1.0
            textStyle.fontSizeValue: 1.0

        }

        Container {

            horizontalAlignment: HorizontalAlignment.Fill
            verticalAlignment: VerticalAlignment.Fill

            topPadding: 50

            // A standard TextArea for displaying items
            ImageView {

                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill

                imageSource: "asset:///images/1.png"

            }

            TextArea {
                editable: false

                text: _RSSFeed.feeds
                textStyle {
                    base: SystemDefaults.TextStyles.SmallText
                    color: Color.Black
                }
            }
        }

        Container {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Top

            leftPadding: 20
            rightPadding: 20
            topPadding: 20
            bottomPadding: 20

            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            

            // A standard Button
            Button {
                verticalAlignment: VerticalAlignment.Center
                leftMargin: 10

                layoutProperties: FlowListLayoutProperties {

                }

                enabled: ! _RSSFeed.active

                text: qsTr("Get Update")

                // Fetch weather items on click
                onClicked: _RSSFeed.fetch()
                horizontalAlignment: HorizontalAlignment.Center
            }
            
        }
        
    }
    
}
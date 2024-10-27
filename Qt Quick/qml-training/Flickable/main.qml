import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    visible: true
    width: 300
    height: 400
    title: "Flickable Example"

    Flickable {
        id: flickable
        width: parent.width
        height: parent.height
        contentWidth: parent.width
        contentHeight: contentColumn.height  // Allow scrolling if content exceeds visible area

        onFlickStarted: {
            console.log("Flick started")
        }
        onFlickEnded: {
            console.log("Flick ended")
        }

        rebound: Transition {
            NumberAnimation {
                properties: "x,y"
                duration: 500
                easing.type: Easing.OutBounce
            }
        }

        Rectangle {
            width: flickable.width
            height: flickable.contentHeight
            color: "green"
        }

        Column {
            id: contentColumn
            width: flickable.width
            spacing: 10
            padding: 10

            // Adding multiple items to demonstrate scrolling
            Repeater {
                model: 20  // Creates 20 items for demonstration
                Text {
                    text: "Item " + (index + 1)
                    font.pixelSize: 18
                    color: "black"
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}

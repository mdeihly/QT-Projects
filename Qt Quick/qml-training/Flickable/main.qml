import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Flickable")

    Flickable {
        id: flickable
        width: 400; height: 400
        contentWidth: 2000; contentHeight: 2000

        onFlickStarted: {
            rec.color = "cyan"
        }
        onFlickEnded: {
            rec.color = "red"
        }

        Rectangle {
            id: rec
            width: 100; height: 50
            color: "blue"
        }
    }
}

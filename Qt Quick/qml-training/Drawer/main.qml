import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

Window {
    width: 500
    height: 300
    visible: true
    title: qsTr("Simple Drawer")

    // Button to open/close the drawer
    Button {
        text: "Toggle Drawer"
        anchors.centerIn: parent
        onClicked: drawer.open()
    }

    // Drawer that slides up from the bottom
    Drawer {
        id: drawer
        width: parent.width
        height: parent.height * 0.3
        edge: Qt.BottomEdge

        // Background styling for the drawer
        background: Rectangle {
            color: "lightgrey"
            radius: 10
        }

        // Content inside the drawer
        Column {
            anchors.centerIn: parent
            spacing: 10

            Text {
                text: "This is a simple drawer"
                font.pixelSize: 18
                color: "black"
                horizontalAlignment: Text.AlignHCenter
            }

            Button {
                text: "Close Drawer"
                onClicked: drawer.close()
            }
        }
    }
}

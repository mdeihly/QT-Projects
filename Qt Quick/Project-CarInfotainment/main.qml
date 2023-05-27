import QtQuick 2.15
import QtQuick.Window 2.15
import "ui/BottomBar"
import "ui/RightScreen"
import "ui/LeftScreen"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Car Infotainment")

    Shortcut
    {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    BottomBar
    {
        id: bottomBar

        anchors
        {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        height: parent.height / 12
        color:"black"
    }

    RightScreen
    {
        id: rightScreen
        anchors
        {
            top: parent.top
            bottom: bottomBar.top
            right: parent.right
        }

        width: parent.width * 2/3
    }

    LeftScreen
    {
        id: leftScreen

        anchors
        {
            left: parent.left
            right: rightScreen.left
            bottom: bottomBar.top
            top: parent.top
        }

        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightblue" }
            GradientStop { position: 1.0; color: "blue" }
        }
    }
}

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
    }

    RightScreen
    {
        id: rightScreen
    }

    LeftScreen
    {
        id: leftScreen
    }
}

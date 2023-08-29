import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import "views"

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("StackView-App")

    // Use the readonly keyword to prevent a QML component to crush the stackView
    readonly property alias stack: stackView

    StackView
    {
        id: stackView
        anchors{left: parent.left; right: parent.right; top: parent.top; bottom: bottomBar.top}
        initialItem: InitialView{}
    }

    BottomBar
    {
        id: bottomBar
        anchors {left: parent.left; right: parent.right; bottom: parent.bottom}
        height: 50
    }
}

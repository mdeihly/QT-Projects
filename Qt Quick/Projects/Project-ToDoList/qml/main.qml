import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("To Do List")

    property int titleBarHeight: 70
    property color leftItemColor: "gray"

    TitleBar {
        id: titleBar
        anchors.top: root.top
        height: root.titleBarHeight
        width: root.width
    }

    LeftItem {
        id: leftItem
        anchors.left: parent.left
        anchors.top: titleBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width * 0.5
        color: root.leftItemColor
    }

    RightItem {
        id: rightIten
        anchors.right: parent.right
        anchors.top: titleBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width * 0.5

        onAddBtnClicked: function(title, description) {
            leftItem.listViewModel.append({"title": title, "description": description})
        }
    }
}

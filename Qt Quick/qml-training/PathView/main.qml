import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("PathView")

    ListModel {
        id: appModel
        ListElement { name: "Music";      icon: "qrc:/assets/AddressBook.png" }
        ListElement { name: "Camera";     icon: "qrc:/assets/Camera.png" }
        ListElement { name: "Messaging";  icon: "qrc:/assets/EMail.png" }
        ListElement { name: "Todo List";  icon: "qrc:/assets/TodoList.png" }
        ListElement { name: "Contacts";   icon: "qrc:/assets/AddressBook.png" }
    }

    Component {
        id: appDelegate
        Column {
            id: wrapper
            required property url icon
            required property string name

            opacity: PathView.isCurrentItem ? 1 : 0.5

            Image {
                anchors.horizontalCenter: delegateText.horizontalCenter
                source: icon; width: 40; height: 30; smooth: true
                fillMode: Image.PreserveAspectFit
            }
            Text {
                id: delegateText
                text: name; font.pixelSize: 15
            }
        }
    }


    Component {
        id: appHighlight
        Rectangle { width: 80; height: 80; color: "lightsteelblue" }
    }

    PathView {
        anchors.fill: parent
        model: appModel
        delegate: appDelegate
        highlight: appHighlight
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        focus: true

        path: Path {
            startX: 150; startY: 200
            PathCubic { x: 50; y: 100; control1X: 100; control1Y: 200
                control2X: 50; control2Y: 125 }
            PathCubic { x: 150; y: 50; control1X: 50; control1Y: 75
                control2X: 100; control2Y: 50 }
            PathCubic { x: 250; y: 100; control1X: 200; control1Y: 50
                control2X: 250; control2Y: 75 }
            PathCubic { x: 150; y: 200; control1X: 250; control1Y: 125
                control2X: 200; control2Y: 200 }
        }

        Keys.onRightPressed: if (!moving) incrementCurrentIndex()
        Keys.onLeftPressed: if (!moving) decrementCurrentIndex()
    }
}

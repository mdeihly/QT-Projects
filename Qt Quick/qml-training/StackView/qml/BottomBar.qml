import QtQuick 2.15
import QtQuick.Controls 2.0

Rectangle
{
    id: bottomBar
    color: Qt.lighter("green")

    property int __btnImplicitWidth : 100

    Row {
        spacing: 10
        anchors.centerIn: parent

        Button {
            id: popBtn
            text: "Pop"
            enabled: stack.depth > 1
            implicitWidth: __btnImplicitWidth
            onClicked:
                if(!stack.busy) {
                    stack.pop()
                }
        }
        Button {
            id: pushBtn
            text: "Push"
            implicitWidth: __btnImplicitWidth
            onClicked: stack.push("qrc:/qml/views/MainView.qml")
        }
        Text {
            text: stack.depth
            color: "yellow"
            font.bold: true
        }
    }
}

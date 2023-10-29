import QtQuick 2.15

Item {
    id: root

    property color rectColor: "#A81A1A"
    property color textColror: "#FFFFFF"
    property int textLeftMargin: 35
    property int fontPixelSize: 22

    Rectangle {
        id: rec
        anchors.fill: parent
        color: root.rectColor

        Text {
            id: text
            text: qsTr("My ToDo List")
            font {
                bold: true
                italic: true
                pixelSize: root.fontPixelSize
            }
            anchors {
                verticalCenter: rec.verticalCenter
                left: rec.left
                leftMargin: root.textLeftMargin
            }
            color: root.textColror
        }
    }
}

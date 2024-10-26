import QtQuick 2.15

Rectangle
{
    id: initialView
    color: "red"
    Text{
        id: text
        anchors.centerIn: parent
        text: "Main Item"
        color: "yellow"
        font.pixelSize: 30
    }
}

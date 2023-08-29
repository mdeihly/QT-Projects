import QtQuick 2.15

Rectangle
{
    id: initialView
    color: "red"
    Text{
        id: text
        anchors.centerIn: parent
        text: "Initial Item"
        color: "yellow"
        font.pixelSize: 30
    }
}

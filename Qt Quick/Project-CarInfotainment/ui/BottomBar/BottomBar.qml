import QtQuick 2.15

Rectangle
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

    AirConditionComponent
    {
        id: acComponent
        height: parent.height
        width: parent.width * 1/5
        anchors.centerIn: parent
    }

}

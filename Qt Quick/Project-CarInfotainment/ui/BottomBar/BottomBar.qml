import QtQuick 2.15

Rectangle
{
    id: bottomBar

    AirConditionComponent
    {
        id: acComponent
        height: parent.height
        width: parent.width * 1/5
        anchors.centerIn: parent
    }

}

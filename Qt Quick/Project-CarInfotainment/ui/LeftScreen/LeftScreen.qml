import QtQuick 2.15

Rectangle
{
    id: leftScreen

    SearchBox
    {
        id: searchBox
        anchors
        {
            top: parent.top
            left: parent.left
            margins: 20
        }

        width: parent.width * 2/3
        height: parent.height * 1/13
        color: "#888"

    }

    Image
    {
        id: carRender
        anchors.centerIn: parent
        width: parent.width * .75
        fillMode: Image.PreserveAspectFit
        source: "../Images/car.png"
    }

}

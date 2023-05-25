import QtQuick 2.15

Rectangle
{
    id: leftScreen
    anchors
    {
        left: parent.left
        right: rightScreen.left
        bottom: bottomBar.top
        top: parent.top
    }

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightblue" }
        GradientStop { position: 1.0; color: "blue" }
    }

    SearchBox
    {
        id: searchBox
        anchors
        {
            top: parent.top
            left: parent.left
            margins: 20
        }
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

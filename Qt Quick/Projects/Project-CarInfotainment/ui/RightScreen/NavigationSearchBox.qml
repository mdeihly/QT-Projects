import QtQuick 2.15

Rectangle
{
    id: navigator
    color: "red"
    radius: 5

    Image
    {
        id: searchIcon
        source: "../Images/searchIcon.png"

        anchors
        {
            left: parent.left
            leftMargin: 25
            verticalCenter: parent.verticalCenter
        }

        height: parent * .45
        fillMode: Image.PreserveAspectFit
    }
}

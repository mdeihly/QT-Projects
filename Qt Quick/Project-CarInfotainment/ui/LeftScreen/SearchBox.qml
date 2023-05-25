import QtQuick 2.15

Rectangle
{
    id: searchBox
    readonly property color __colorLightGrey: "#888"
    width: parent.width * 2/3
    height: parent.height * 1/13
    color:__colorLightGrey

    Image {
        id: searchIcon
        source: "../Images/searchIcon.png"
        anchors
        {
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: 10
        }
        fillMode: Image.PreserveAspectFit
    }
    Text
    {
        id: navigate

        readonly property string __placeholderText: "Navigate..."

        anchors
        {
            verticalCenter: parent.verticalCenter
            left: searchIcon.right
            leftMargin: 5
        }
        text: __placeholderText
        visible: !textInput.text
        color: "pink"
    }

    TextInput
    {
        id: textInput
        anchors
        {
            top: parent.top
            bottom: parent.bottom
            left: searchIcon.right
            right: parent.right
            leftMargin: 5
        }
        verticalAlignment: Text.AlignVCenter
        clip: true
        focus: true
        color: "darkblue"
        cursorDelegate: Rectangle {
            visible: textInput.cursorVisible
            color: "salmon"
            width: textInput.cursorRectangle.width
        }

    }
}



import QtQuick 2.15

Rectangle
{
    id: rightScreen

    Image {
        id: map
        source: "../Images/map.png"
        anchors
        {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }

    }

    Image
    {
        id: lockIcon
        anchors
        {
            margins: 10
            top: parent.top
            left: parent.left
        }
        width: parent.width / 30

        fillMode: Image.PreserveAspectFit
        source: (_systemHandler.carLocked) ? "../Images/lock.png" : "../Images/unlock.png"
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                _systemHandler.setCarLocked(!_systemHandler.carLocked)
            }
            cursorShape: Qt.PointingHandCursor
        }
    }

    Text
    {
        id: currentTime
        anchors
        {
            left: lockIcon.right
            top: parent.top
            margins: 10
        }
        font.pixelSize: 14
        font.bold: true
        color: "black"
        text: _systemHandler.currentTime
    }

    Text
    {
        id: outdoorTemp
        anchors
        {
            left: currentTime.right
            top: parent.top
            margins: 10
        }
        font.pixelSize: 14
        font.bold: true
        color: "black"
        text: qsTr("%1 °C").arg(_systemHandler.outdoorTemp)
    }
}

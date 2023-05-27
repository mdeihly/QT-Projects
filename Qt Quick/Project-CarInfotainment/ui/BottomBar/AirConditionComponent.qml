import QtQuick 2.15

Item {
    id: root

    readonly property color fontColor: "silver"
    readonly property color transparentBkg: "transparent"
    readonly property int fontSize: 26
    readonly property int margin: 10
    readonly property int incrementTemperature: 1
    readonly property int decrementTemperature: -1

    Rectangle
    {
        id: decrementButton
        anchors
        {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
        width: height / 2
        color: root.transparentBkg

        Text
        {
            text: "<"
            anchors.centerIn: parent
            color: root.fontColor
            font.pixelSize: root.fontSize

            MouseArea
            {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: _acHandler.updateTemperature(root.decrementTemperature)
            }
        }
    }

    Text
    {
        id: targetTempValue
        text: qsTr("%1").arg(_acHandler.targetTemperature)
        anchors
        {
            left: decrementButton.right
            verticalCenter: parent.verticalCenter
            leftMargin: root.margin
        }

        font.pixelSize: root.fontSize
        color:root.fontColor
    }

    Rectangle
    {
        id: incrementButton
        anchors
        {
            left: targetTempValue.right
            top: parent.top
            bottom: parent.bottom
            leftMargin: root.margin
        }
        width: height / 2
        color: root.transparentBkg

        Text
        {
            text: ">"
            anchors.centerIn: parent
            color: root.fontColor
            font.pixelSize: root.fontSize

            MouseArea
            {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: _acHandler.updateTemperature(root.incrementTemperature)
            }
        }
    }

}

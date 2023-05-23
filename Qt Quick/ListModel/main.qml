import QtQuick 2.15
import QtQuick.Window 2.15

import List.Model 1.0 as CustomModel

// ListView provides Scrolling
ListView
{
    id: root
    width: 300
    height: 400
    model: CustomModel.MyModel
    clip: true
    delegate: Rectangle
    {
        required property string display
        required property color decoration

        width: root.width
        height: 50
        color: decoration
        Text
        {
            text: parent.display
            color: Qt.colorEqual(parent.color, "black") ? "white" : "black"
            anchors.centerIn: parent
        }
    }
}

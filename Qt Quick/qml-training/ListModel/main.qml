import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import List.Model 1.0 as CustomModel

ListView
{
    id: root
    width: 300
    height: 400
    model: CustomModel.MyModel
    clip: true
    orientation: ListView.Vertical
    snapMode: ListView.NoSnap
    cacheBuffer: 0
    boundsBehavior: Flickable.StopAtBounds
    interactive: contentHeight > height
    delegate: Rectangle
    {
        required property string display
        required property color decoration

        anchors.left: parent.left
        anchors.leftMargin: (root.width - width) / 2
        width: 100
        height: 50
        color: decoration
        Text
        {
            text: parent.display
            color: Qt.colorEqual(parent.color, "black") ? "white" : "black"
            anchors.centerIn: parent
        }
    }

    ScrollBar.vertical: ScrollBar {
        active: true
        policy: ScrollBar.AsNeeded

    }

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: bkg
        z: -1
    }

    Component {
        id: bkg
        Rectangle {
            width: root.width; height: root.height
            gradient: Gradient {
                GradientStop { position: 0.0; color: "red" }
                GradientStop { position: 0.33; color: "yellow" }
                GradientStop { position: 1.0; color: "green" }
            }
        }
    }
}

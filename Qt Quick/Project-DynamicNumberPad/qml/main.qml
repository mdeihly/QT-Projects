import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Number Pad")

    NumberPad
    {
        id: pad
        width: 100; height: 100
        anchors.centerIn: parent
    }
}

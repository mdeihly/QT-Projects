import QtQuick 2.15

Rectangle {
    id: root
    implicitHeight: 48
    implicitWidth: 48
    radius: 8

    property alias iconSource: img.source

    signal clicked()

    Image {
        id: img
        property real __iconSize: 36
        width: __iconSize
        height: __iconSize
        anchors.centerIn: parent
        sourceSize.width: __iconSize
        sourceSize.height: __iconSize
        scale: ma.pressed ? 0.8 : 1
        opacity: ma.pressed ? 0.5 : 1
    }

    MouseArea {
        id: ma
        anchors.fill: parent
        onClicked: root.clicked()
    }
}


import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: root
    width: 600
    height: 500
    visible: true
    title: qsTr("GridView")

    property color gridColor

    Component.onCompleted:
    {
        var colors = ["orange", "blue", "red", "yellow", "brown", "pink"]
        for(var i = 0; i < colors.length; ++i)
        {
            gridView.model.append({gridColor: colors[i]})
        }
    }

    GridView
    {
        id: gridView
        anchors.fill: parent
        anchors.margins: 10
        model: ListModel{}
        clip: true
        cellWidth: root.width / 3
        cellHeight: root.height / 3
        boundsBehavior: GridView.StopAtBounds
        snapMode: GridView.SnapOneRow
        delegate: Rectangle {
            width: gridView.cellWidth * 0.9
            height: gridView.cellHeight * 0.9
            radius: 5
            color: gridColor
        }
    }
}

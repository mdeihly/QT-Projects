import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Window {
    width: 400
    height: 480
    visible: true
    title: qsTr("Customized ListView")

    ListModel {
        id: nameModel
        ListElement { name: "Alex" }
        ListElement { name: "John" }
        ListElement { name: "Nicola" }
        ListElement { name: "Victor" }
        ListElement { name: "Mario" }
    }

    Component {
        id: nameDelegate

        ItemDelegate {
            id: delegate

            readonly property ListView __lv: ListView.view
            implicitWidth: __lv.width * 0.5
            padding: 0
            background: null
            highlighted: ListView.isCurrentItem
            hoverEnabled: true
            onClicked : {
                nameModel.insert(index, {name: "Item #"+nameModel.count})
                __lv.currentIndex = model.index
            }

            contentItem: RowLayout {
                id: rowLayout
                spacing: 12
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                Text {
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    text: name
                    font.pixelSize: 18
                    color: highlighted ? "green" : "black"
                }

                Image {
                    visible: highlighted
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    source: "qrc:/icons/right-arrow.svg"
                    sourceSize: Qt.size(22,22)
                }
            }
        }
    }

    ListView {
        id: listView

        width: parent.width / 2
        height: parent.height / 2
        anchors.centerIn: parent

        model: nameModel
        delegate: nameDelegate
        focus: true // allows keyboard navigation
        clip: true
        spacing: 5
        currentIndex: 1
        highlightFollowsCurrentItem: true

        header: Rectangle {
            anchors { left: parent.left; right: parent.right }
            height: 10
            color: "pink"
        }
        footer: Rectangle {
            anchors { left: parent.left; right: parent.right }
            height: 10
            color: "lightblue"
        }
        highlight: Rectangle {
            anchors { left: parent.left; right: parent.right }
            color: "lightgray"
        }

        preferredHighlightBegin: 42
        preferredHighlightEnd: 150
        highlightRangeMode: ListView.StrictlyEnforceRange

        Rectangle {
            color: "red"
            x: 0; y: parent.preferredHighlightBegin
            width: parent.width; height: 1
        }

        Rectangle {
            color: "red"
            x: 0; y: parent.preferredHighlightEnd
            width: parent.width; height: 1

        }

        populate: Transition {
            NumberAnimation { properties: "x,y"; duration: 500 }
        }

        add: Transition {
            PropertyAction { property: "transformOrigin"; value: Item.TopLeft }
            NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 200}
            NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 200 }
        }

        displaced: Transition {
            PropertyAction { properties: "opacity, scale"; value: 1 }
            NumberAnimation { properties: "x,y"; duration: 300 }
        }
    }
}

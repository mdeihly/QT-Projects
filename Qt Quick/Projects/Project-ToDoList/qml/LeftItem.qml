import QtQuick 2.15

Rectangle {
    id: root

    property alias listViewModel: listView.model

    ListView {
        id: listView
        width: parent.width * 0.8
        height: parent.height * 0.8
        anchors.centerIn: parent
        model: ListModel{}
        spacing: 5
        clip: true

        delegate: Rectangle {
            required property string title
            required property string description
            required property int index

            width: listView.width
            height: 70
            color: "white"
            radius: 10

            Rectangle {
                id: deleteBtn

                width: 50
                height: parent.height
                anchors.right: parent.right
                color: "red"
                radius: 10
                opacity: mouseArea.pressed ? 0.5 : 1

                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text: "DELETE"
                    font {
                        bold: true
                        pixelSize: 12
                    }
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    // remove item
                    onClicked: listView.model.remove(index)
                }
            }

            Column {
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 50
                anchors.topMargin: 5
                anchors.bottomMargin: 5

                Text {
                    id: titleText
                    color: "black"
                    font {
                        bold: true
                        pixelSize: 18
                    }
                    text: title
                }

                Text {
                    id: descText
                    color: "black"
                    font.pixelSize: 16
                    text: description
                }
            }
        }
    }
}

import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    property color textFieldColor: "#A81A1A"
    property color addBtnColor: "#D83838"

    property int textFieldHeight: 50
    property int textAreaHeight: 100
    property int addBtnHeight: 50

    signal addBtnClicked(string title, string description)

    Column {

        anchors {
            fill: parent
            margins: 7
        }

        spacing: 15

        TextField {
            id: textField
            placeholderText: "Enter the title..."
            width: parent.width
            color: root.textFieldColor
            height: root.textFieldHeight
            focus: true
        }

        TextArea {
            id: textArea
            placeholderText: "Enter the ToDo item description..."
            width: parent.width
            height: root.textAreaHeight
        }

        Rectangle {
            id: addBtn
            width: parent.width
            height: root.addBtnHeight
            color: addBtn.enabled ? root.addBtnColor : "gray"
            radius: 10
            opacity: mouseArea.pressed ? 0.5 : 1
            enabled: textField.text.length !== 0 && textArea.text.length !== 0

            Text {
                id: btnText
                text: "Add to List"
                anchors.centerIn: parent
                color: "whitesmoke"
                font.pixelSize: 12
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked:  {
                    root.addBtnClicked(textField.text, textArea.text)
                    // reset fields
                    textField.text = textArea.text = ""
                }

            }
        }
    }
}

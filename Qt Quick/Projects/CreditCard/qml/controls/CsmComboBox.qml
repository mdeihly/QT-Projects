import QtQuick 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

ComboBox {
    id: comboBox

    implicitWidth: 100
    implicitHeight: 60

    background: Rectangle {
        implicitWidth: parent.width
        implicitHeight: parent.height
        radius: 5
        border.color: comboBox.focus | mouseArea.containsMouse ? '#3d9cff' : '#ced6e0'

        layer.enabled: true
        layer.effect: DropShadow {
            radius: 30
            samples: radius * 2 + 1
            color: comboBox.focus ? '#18203875' : 'transparent'
            verticalOffset: 10
        }

        MouseArea {
            id: mouseArea

            hoverEnabled: true
            acceptedButtons: Qt.NoButton
            anchors.fill: parent
        }
    }

    popup: Popup {
        width: comboBox.width
        //height: 300
        //y: -height

        y: comboBox.height + 2
        //width: control.implicitWidth * 1.26
        implicitHeight: contentItem.implicitHeight > 250 ? 250 : contentItem.implicitHeight
        padding: 4

        contentItem: ListView {
            spacing: 5
            clip: true
            model: comboBox.popup.visible ? comboBox.delegateModel : null
            ScrollIndicator.vertical: ScrollIndicator {}

            leftMargin: 5
            implicitHeight: contentHeight
            keyNavigationEnabled: true
            focus: true
            currentIndex: comboBox.highlightedIndex
        }

        background: Rectangle {
            anchors.fill: parent
            radius: 5
            border.color: '#ced6e0'
        }
    }

    delegate: ItemDelegate {
        id: delegate

        width: comboBox.width
        hoverEnabled: true
        focus: true

        contentItem: Text {
            text: modelData
            color: '#1a3b5d'
        }

        background: Rectangle {
            width: 115; height: 40
            radius: 5
            color: popUpMouseArea.containsMouse ? Qt.rgba(0, 0, 0, 0.1) : 'transparent'

            MouseArea {
                id: popUpMouseArea

                hoverEnabled: true
                anchors.fill: parent

                onClicked: {
                    comboBox.displayText = modelData
                    comboBox.popup.visible = false
                }
            }
        }
    }

    contentItem: Text {
        opacity: 0.9
        text: comboBox.displayText
        color: '#1a3b5d'
        leftPadding: 15
        font.pixelSize: 16
        verticalAlignment: Text.AlignVCenter
    }
}

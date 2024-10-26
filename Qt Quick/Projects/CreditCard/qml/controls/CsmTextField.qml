import QtQuick 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

TextField {
    id: textField

    activeFocusOnTab: true
    color: '#1a3b5d' // text color
    leftPadding: 12
    font {pixelSize: 18; weight: Font.Normal}

    background: Rectangle {
        implicitWidth: parent.width
        implicitHeight: parent.height
        radius: 5
        border.color: textField.focus | mouseArea.containsMouse ? '#3d9cff' : '#ced6e0'

        layer.enabled: true
        layer.effect: DropShadow {
            radius: 30
            samples: radius * 2 + 1
            color: textField.focus ? '#18203875' : 'transparent'
            verticalOffset: 10

            ColorAnimation on color {
                duration: 150
            }
        }

        ColorAnimation on border.color {
            duration: 150
        }

        MouseArea {
            id: mouseArea

            hoverEnabled: true
            acceptedButtons: Qt.NoButton
            cursorShape: Qt.IBeamCursor
            anchors.fill: parent
        }
    }
}

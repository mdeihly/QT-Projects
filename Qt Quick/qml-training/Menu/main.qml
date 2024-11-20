import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import "controls"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Menu")

    Button {
        id: btn
        text: "Open Menu"

        onClicked: menu.open()
    }


    CsmMenu {
        id: menu
        y: btn.height

        Repeater {
            id: repeater
            model: 3

            CsmMenuItem {
                text: "Option %1".arg(index)
                onClicked: console.log(text)
            }
        }
    }
}

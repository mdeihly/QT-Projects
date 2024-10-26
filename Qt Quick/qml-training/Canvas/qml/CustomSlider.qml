import QtQuick 2.15
import QtQuick.Controls 2.15

Slider {
    id: slider

    implicitWidth: 200
    implicitHeight: 4

    background: Rectangle {
        x: slider.leftPadding
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        implicitWidth: 200
        implicitHeight: 4
        width: slider.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
            width: slider.visualPosition * parent.width
            height: parent.height
            color: "#21be2b"
            radius: 2
        }
    }

    // Customize the handle
    handle: Rectangle {
        x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        width: 30
        height: 30
        radius: 15
        color: slider.pressed ? "gray" : "lightgray"
        border.color: "black"
        border.width: 1
    }
}

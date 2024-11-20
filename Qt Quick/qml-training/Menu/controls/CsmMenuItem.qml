import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Controls.impl 2.15 // to use ColorImage

MenuItem {
    id: control

    padding: 6
    horizontalPadding: 6
    spacing: 6

    arrow: ColorImage {
        x: control.mirrored ? control.padding : control.width - width - control.padding
        y: control.topPadding + (control.availableHeight - height) / 2

        visible: true
        mirror: control.mirrored
        color: !control.enabled ? "#A9A9A9"
                                : control.highlighted ? "#FFD700"
                                                      : "#333333"
        source: "qrc:/icons/caret-right.svg"
        width: 20
        height: 20
    }

    contentItem: IconLabel {
        readonly property real arrowPadding: control.subMenu && control.arrow ? control.arrow.width + control.spacing : 0
        readonly property real indicatorPadding: control.checkable && control.indicator ? control.indicator.width + control.spacing : 0
        leftPadding: !control.mirrored ? indicatorPadding : arrowPadding
        rightPadding: control.mirrored ? indicatorPadding : arrowPadding

        spacing: control.spacing
        mirrored: control.mirrored
        display: control.display
        alignment: Qt.AlignLeft
        icon: control.icon
        text: control.text
        font: control.font
        color: !control.enabled ? "#A9A9A9"
                                : control.highlighted ? "#FFD700"
                                                      : "#333333"

    }

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 32
        radius: 3
        color: !control.enabled ? "#F5F5F5"
                                : control.highlighted ? "#FFFAF0"
                                                      : "transparent"
    }
}

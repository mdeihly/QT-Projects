import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

Menu {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            contentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + topPadding + bottomPadding)

    margins: 0
    padding: 6

    transformOrigin: !cascade ? Item.Top : (mirrored ? Item.TopRight : Item.TopLeft)

    //delegate: MenuItem { }

    enter: Transition {
        // grow_fade_in
        NumberAnimation { property: "scale"; from: 0.9; to: 1.0; easing.type: Easing.OutQuint; duration: 250 }
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; easing.type: Easing.OutCubic; duration: 150 }
    }

    exit: Transition {
        // shrink_fade_out
        NumberAnimation { property: "scale"; from: 1.0; to: 0.9; easing.type: Easing.OutQuint; duration: 250 }
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; easing.type: Easing.OutCubic; duration: 150 }
    }

    contentItem: ListView {
        implicitHeight: contentHeight

        clip: true
        model: control.contentModel
        interactive: Window.window ? contentHeight > Window.window.height : false
        currentIndex: control.currentIndex

        ScrollIndicator.vertical: ScrollIndicator {}
    }

    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 32

        radius: 3
        color: Qt.lighter( "green" /*control.palette.active.window*/, 1.2 )
    }

    // Overlay.modal: Rectangle {
    //     color: control.palette.active.shadow
    //     Behavior on opacity { NumberAnimation { duration: 150 } }
    // }

    // Overlay.modeless: Rectangle {
    //     color: control.palette.active.shadow
    //     Behavior on opacity { NumberAnimation { duration: 150 } }
    // }
}

import QtQuick 2.15
import QtQuick.Controls 2.15

SplitView {
    id: splitView

    handle: Rectangle {
            id: handleDelegate

            implicitWidth: 4
            implicitHeight: 4
            color: SplitHandle.pressed ? "#81e889"
                : (SplitHandle.hovered ? Qt.lighter("#c2f4c6", 1.1) : "#c2f4c6")

            containmentMask: Item {
                x: (handleDelegate.width - width) / 2
                width: 64
                height: splitView.height
            }

            Image {
                anchors.centerIn: parent
                sourceSize: Qt.size(25,25)
                source: "qrc:/icons/splitter_handle.png"
            }
        }
}

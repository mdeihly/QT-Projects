import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("SplitView")


    CsmSplitView {
        anchors.fill: parent

        Rectangle {
            implicitWidth: 150
            color: "#444"
        }
        Rectangle {
            implicitWidth: 50
            color: "#666"
        }
    }
}

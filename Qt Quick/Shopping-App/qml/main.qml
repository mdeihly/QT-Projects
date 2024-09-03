import QtQuick
import QtQuick.Controls
import 'views'
import 'Components'

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Shopping App")

    readonly property alias stack: stackview

    Header {
        id: header
        anchors{left: parent.left; right: parent.right; top: parent.top}
        onBackClicked: stackview.pop()
    }

    StackView {
        id: stackview
        anchors{left: parent.left; right: parent.right; top: header.bottom; bottom: parent.bottom}
        initialItem: Dashboard{}
    }
}

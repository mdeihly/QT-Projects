import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.0

Window {
    id: window
    width: 640
    height: 280
    visible: true
    title: qsTr("Image Viewer")

    Component.onCompleted: {
        x = Screen.width / 2 - width / 2
        y = Screen.height / 2 - height / 2
    }

    Shortcut {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    Container {
        id: leftBar

        currentIndex: 1 // default

        Layout.fillWidth: false
        Layout.fillHeight: true

        ButtonGroup {
            buttons: columnLayout.children
        }

        contentItem: ColumnLayout {
            id: columnLayout
            spacing: 4
        }

        FeatureButton {
            id: lionFeatureButton
            text: qsTr("Lion")
            Layout.fillHeight: true
            onClicked: leftBar.setCurrentIndex(0)
        }

        FeatureButton {
            id: tigerFeatureButton
            text: qsTr("Tiger")
            checked: true
            Layout.fillHeight: true
            onClicked: leftBar.setCurrentIndex(1)

        }

        FeatureButton {
            id: fishFeatureButton
            text: qsTr("Fish")
            Layout.fillHeight: true
            onClicked: leftBar.setCurrentIndex(2)
        }
    }

    StackLayout {
        id: stack
        currentIndex: leftBar.currentIndex

        anchors.right: parent.right
        anchors.left: leftBar.right

        // index 0
        Item {
            id: firstIndex
            Image {
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "../images/lion.jpg"
            }
        }

        // index 1
        Item {
            Image {
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: "../images/tiger.png"
            }
        }

        // index 2
        Image {
            fillMode: Image.PreserveAspectFit
            source: "../images/fish.jpeg"
        }
    }

}

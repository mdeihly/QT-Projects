import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Canvas Element")

    Shortcut
    {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        CircularProgressBar {
            id: cirProgBar

            width: 200
            height: 200
            progress: customSlider.value/100

            Text {
                anchors.centerIn: parent
                text: parseInt(cirProgBar.progress * 100) + "%"
                font.pointSize: 25
                color: 'black'
            }
        }

        CustomSlider {
            id: customSlider
            from: 0
            to: 100
            value: 35 // initial value
        }
    }


}

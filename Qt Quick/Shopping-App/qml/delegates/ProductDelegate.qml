import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import '../theme'

Item {
    id: root
    width: gridView.cellWidth
    height: gridView.cellHeight

    property string shortName
    property string description
    property string longDescription
    property real rating
    property int numItemsSold
    property real price
    property int modelIndex

    signal clicked

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 2
        spacing: 4

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: AppTheme.primaryBg
            radius: 8

            Image {
                id: img
                source: `qrc:/Shopping-App/assets/products/im${modelIndex+1}.jpg`
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
                scale: mouseArea.pressed ? 0.9 : 1
            }
        }

        Column {
            Layout.preferredHeight: 50
            Layout.fillWidth: true
            Layout.leftMargin: 4
            Layout.rightMargin: 4
            spacing: 2
            clip: true

            Row {
                spacing: 2

                Label {
                    id: currencytxt
                    text: qsTr('USD')
                    font.pixelSize: 12
                    font.bold: true
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 2
                }

                Label {
                    id: pricetxt
                    text: price
                    font.pixelSize: 16
                    font.bold: true
                    anchors.bottom: parent.bottom
                    leftPadding: 4
                }

                Label {
                    id: decimaltxt
                    text: '.' + price
                    font.pixelSize: 12
                    font.bold: true
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 2
                }
            }

            Label {
                id: desctxt
                text: shortName + ' - ' + description
                font.pixelSize: 10
                wrapMode: Label.WrapAnywhere
                maximumLineCount: 2
                width: parent.width
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: root
        onClicked: root.clicked()
    }
}

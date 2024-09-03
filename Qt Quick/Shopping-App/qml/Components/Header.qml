import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import '../theme'

Item {
    id: root
    implicitHeight: 50

    signal backClicked()

    property bool backButtonShown: stack.depth > 1

    Rectangle {
        id: bkg
        color: AppTheme.primaryBg
        anchors.fill: parent
        anchors.bottomMargin: 3

        RowLayout {
            id: rowLayout
            anchors.fill: parent
            anchors.margins: 4

            IconButton {
                id: backBtn
                Layout.fillHeight: true
                Layout.preferredWidth: 42
                Layout.alignment: Qt.AlignVCenter
                iconSource: AppTheme.arrowLeftIcon
                onClicked: root.backClicked()
                visible: backButtonShown
            }

            TextField {
                id: textField
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: backButtonShown ? 0 : 10
                background: Rectangle {
                    radius: height / 2
                }
                placeholderText: qsTr('Search here ...')
                leftPadding: 10
                rightPadding: 10
                font.pixelSize: 14
            }

            IconButton {
                id: sharebtn
                Layout.fillHeight: true
                Layout.preferredWidth: 36
                iconSource: AppTheme.shareIcon
                Layout.alignment: Qt.AlignVCenter
            }

            IconButton {
                id: cartbtn
                Layout.fillHeight: true
                Layout.preferredWidth: 36
                iconSource: AppTheme.cartIcon
                Layout.alignment: Qt.AlignVCenter
            }

            IconButton {
                id: morebtn
                Layout.preferredWidth: 30
                Layout.fillHeight: true
                iconSource: AppTheme.moreIcon
                Layout.alignment: Qt.AlignVCenter
            }
        }
    }
}

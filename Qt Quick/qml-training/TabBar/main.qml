import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import "Components"

ApplicationWindow  {
    width: 850
    height: 300
    visible: true
    title: qsTr("TabBar")
    color: "black"

    footer: CsmFooter {
        id: footer

        width: parent.width
        height: 100
    }

}

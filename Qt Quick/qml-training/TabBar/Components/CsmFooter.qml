import QtQuick 2.15
import QtQuick.Controls 2.0
import "../Controls"

TabBar {
    id: tabBar

    spacing: 0
    width: parent.width
    currentIndex: 0
    background: null

    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/dashboard.svg"
        text: qsTr("Dashboard")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/fan.svg"
        text: qsTr("Air Conditioning")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/lamp.svg"
        text: qsTr("Lighting")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/refrigerator.svg"
        text: qsTr("Appliances")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/communications.svg"
        text: qsTr("Communications")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/security.svg"
        text: qsTr("Security")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/cctv.svg"
        text: qsTr("CCTV")
    }
    CsmTabButton {
        implicitHeight: parent.height
        icon.source: "qrc:/icons/settings.svg"
        text: qsTr("Settings")
    }
}

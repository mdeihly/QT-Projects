import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: root
    property string image

    Image {
        id: productImg
        anchors.fill: parent
        source: image
        fillMode: Image.PreserveAspectFit
    }
}

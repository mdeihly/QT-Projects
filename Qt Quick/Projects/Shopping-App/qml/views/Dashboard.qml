import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import '../theme'
import '../models'
import '../delegates'

Rectangle {
    id: root

    readonly property alias gridView: gv

    ScrollView
    {
        anchors.fill: parent

        GridView {
            id: gv
            anchors.fill: parent
            model: ProductsModel{}
            clip: true
            flow: GridView.FlowLeftToRight
            cellWidth: root.width / 3
            cellHeight: root.height / 3

            delegate: ProductDelegate {
                modelIndex: index
                shortName: model.shortName
                description: model.description
                longDescription: model.longDescription
                rating: model.rating
                numItemsSold: model.numItemsSold
                price: model.price

                onClicked: stack.push("qrc:/Shopping-App/qml/views/ProductsView.qml", {image: `qrc:/Shopping-App/assets/products/im${index+1}.jpg`})
            }
        }
    }
}

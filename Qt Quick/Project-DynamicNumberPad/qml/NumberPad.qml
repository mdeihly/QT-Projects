import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    signal clicked(int value)

    Column {
        id: column

        Grid {
            id: grid
            spacing: 5
            rows: 4
            columns: 3
        }
    }

    function doClicked(value) {
        console.log(value)
        root.clicked(value)
    }

    Component.onCompleted:
    {
        console.log("Creating Buttons...")
        var num = 0
        for(var i = 0; i < 10; ++i)
        {
            if(i === 0) num = 7; // First row
            if(i === 3) num = 4; // Second row
            if(i === 6) num = 1; // Third row
            if(i === 9) num = 0; // Bottom row

            var qml = ''
            qml += 'import QtQuick 2.15\n'
            qml += 'import QtQuick.Controls 2.15\n'
            qml += 'Button {\n'
            qml += 'id: btn' + i +'\n'
            qml += 'onClicked: {\n'
            qml += 'doClicked('+num+')\n'
            qml += '}\n'
            qml += '}\n'

            var btn = Qt.createQmlObject(qml, grid,"myDynamicSnippet");
            btn.text = num
            btn.width = 40
            btn.height = 40
            num++;
        }

        // Set the last button at the bottom
        var obj = grid.children[grid.children.length -1]
        obj.parent = column
        obj.width = (40 * grid.columns) + 10
    }

}


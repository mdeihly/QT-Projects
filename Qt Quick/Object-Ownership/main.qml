import QtQuick 2.15
import QtQuick.Window 2.15

Item {
    width: 400
    height: 400

    Column {
        anchors {
            fill: parent
            margins: 5
        }

        spacing: 5

        Repeater {
            id: repeater

            //  clicking the mouse area will destroy and recreate all delegates
            model: mouseArea.pressed ? 0 : _studentList.count

            delegate: Rectangle {
                width: parent.width
                height: 40
                color: "blue"

                Text {
                    // invokable method
                    text: _studentList.studentAtIndex(model.index).name
                    font.pixelSize: 15
                    font.bold: true
                    color: "yellow"
                }
            }
        }
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        onPressed: {
            // trigger garbage collector to clean up all unused JavaScript objects
            gc();
        }
    }
}

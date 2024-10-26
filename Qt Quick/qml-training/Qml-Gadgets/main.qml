import QtQuick 2.15
import QtQuick.Window 2.15

Item {
    width: text.width + 20
    height: text.height + 20

    Text {
        id: text
        anchors.centerIn: parent
        text: "Press Me Then Check Console Log!"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                // Accessing a global gadget
                console.log("Global gadget: ", _player);

                // Updating a gadget
                var person = _player;
                person.age = 44;
                person.name = "New Name";
                console.log("Updating the gadget on the QML side: ", person)
            }
        }
    }
}

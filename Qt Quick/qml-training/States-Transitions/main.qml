import QtQuick

Item {
    id: root
    width: 600
    height: 600

    property color hoverColor: "blue"
    property color pressColor: "orange"

    Rectangle {
        id: rectangle
        width: root.width / 2
        height: root.height / 2
        anchors.centerIn: parent
        radius: 10
        color: "red"

        Text {
            id: innerText
            font.pointSize: 16
            anchors.centerIn: parent
        }
    }

    states: [
        State {
            name: "Hovering"
            PropertyChanges {target: rectangle; color: hoverColor}
        },
        State {
            name: "Pressed"
            PropertyChanges {target: rectangle; color: pressColor}
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "Hovering"
            ColorAnimation {duration: 200}
        },
        Transition {
            from: "*"
            to: "Pressed"
            ColorAnimation {duration: 200}
        }
    ]

    //Mouse area to react on click events
    MouseArea {
        hoverEnabled: true
        anchors.fill: rectangle
        onEntered: { root.state='Hovering'}
        onExited: { root.state=''}
        onPressed: { root.state="Pressed" }
        onReleased: {
            if (containsMouse)
                root.state="Hovering";
            else
                root.state="";
        }
    }
}

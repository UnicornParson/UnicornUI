import QtQuick 2.0

Item {
    id: root

    property string itemName: ""
    property alias label: sizeLabel

    visible: globals ? globals.debugGridEnabled : false

    Rectangle {
        id: sizeLabelBackground
        anchors {
            top: root.top
            left: root.left
        }
        width: sizeLabel.width
        height: sizeLabel.height
        color: "black"
        opacity: 0.5
        visible: globals ? globals.debugGridEnabled : false
    }

    Text {
        id: sizeLabel
        anchors {
            top: root.top
            left: root.left
        }
        text: itemName + ".(" + root.x + ":" + root.y + ")(" + root.width + "." + root.height + ")"
        color: "white"
        minimumPointSize: 6
        font.pointSize: 8
        fontSizeMode: Text.Fit
        visible: globals ? globals.debugGridEnabled : false
    }
}

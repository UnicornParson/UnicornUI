import QtQuick 2.0

UBaseItem {
    id: root

    property int pointSize: 12
    property int minimumPointSize: 10
    property color textColor: "black"
    property color backgroundColor: "transparent"
    property int marginTop: 0
    property int marginBottom: 0
    property int marginLeft: 0
    property int marginRight: 0

    Rectangle {

        id: background
        anchors.fill: parent
        color: root.backgroundColor
        anchors.margins: skin.defaultMargin
    }


    Text {
        id: label
        anchors.left: root.left
        anchors.top: root.top
        width: background.width - (2 * margin)
        text: "no text"
        color: root.textColor
        minimumPointSize: root.minimumPointSize
        font.pointSize: root.pointSize
        fontSizeMode: Text.Fit
        anchors.margins: root.margins
    }
}

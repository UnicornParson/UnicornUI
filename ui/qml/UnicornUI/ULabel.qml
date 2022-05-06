import QtQuick 2.0
import TemplatesTypes 1.0

UBaseItem {
    id: root

    property int pointSize: 12
    property int minimumPointSize: 10
    property color textColor: "black"
    property color backgroundColor: "transparent"
    property int marginTop: skin.defaultMargin
    property int marginBottom: skin.defaultMargin
    property int marginLeft: skin.defaultMargin
    property int marginRight: skin.defaultMargin

    property alias text: label.text
    property alias textitem: label
    property alias font: label.font
    property alias backgroundItem: background

    property int style: TextType.Custom

    anchors {
        topMargin: marginTop
        bottomMargin: marginBottom
        leftMargin: marginLeft
        rightMargin: marginRight
    }


    Rectangle {
        id: background
        anchors.fill: parent
        color: root.backgroundColor
    }


    Text {
        id: label
        anchors.left: root.left
        anchors.top: root.top
        width: background.width - (2 * skin.defaultMargin)
        text: "no text"
        color: root.textColor
        minimumPointSize: root.minimumPointSize
        font: (root.style === TextType.Custom) ? Qt.font({pointSize: 10}) : fontmanager.get(root.style)
        fontSizeMode: Text.Fit
    }

    Connections {
        target: fontmanager
        function onFontsChanged() {
            label.font = (root.style === TextType.Custom) ? Qt.font({pointSize: 10}) : fontmanager.get(root.style)
        }
    }
}

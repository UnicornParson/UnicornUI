import QtQuick 2.0

Item {
    id: root

    property alias background: backgroundItem

    UBackgroundElement {
        id: backgroundItem
        anchors.fill: root
        color: skin.secondBackgroundColor
    }
    Rectangle {
        id: border

        anchors.fill: parent
        border.color: skin.secondBorderColor
        border.width: skin.defaultBorderSize
        anchors.margins: 0
        radius: 0
    }
}

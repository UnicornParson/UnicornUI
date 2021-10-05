import QtQuick 2.0

Item {
    id: root

    property string icon: ""
    property alias color: bgRect.color
    property alias nativeRect: bgRect
    property alias nativeImage: bgImg

    Rectangle {
        id: bgRect
        color: "black"
        anchors.fill: root
        visible: !icon
    }

    UImage {
        id: bgImg
        anchors.fill: root
        source: icon
        visible: !!icon
    }
}

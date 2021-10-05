import QtQuick 2.0

UBaseItem {
    id: root
    property string source: ""
    property alias placeholderColor: placeholder.color
    property alias sourceSize: img.sourceSize
    property alias nativeImage: img
    Image {
        id: img
        visible: !!root.source
        source: root.source
    }

    Rectangle {
        id: placeholder

        visible: !root.source
        color: "#535c68"
    }
}

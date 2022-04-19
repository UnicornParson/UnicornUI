import QtQuick 2.12
import QtQuick.Controls 2.12

UBaseItem {
    id: root

    property alias backgroundColor: backgroundItem.color
    property string source: "qrc:/qml/UnicornUI/internal/empty.qml"

    Rectangle {
        id: backgroundItem

        anchors.fill: parent
        color: skin.backgroundColor
    }



    Loader {
        source: root.source
        anchors.fill: parent
        onSourceChanged: {
            console.log("new source", source)
        }
    }


}

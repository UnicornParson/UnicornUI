import QtQuick 2.0

Item {
    id: root

    property string itemName: ""

    UDebugOverlay {
        anchors.fill: root
        itemName: "BaseItem"
    }
}

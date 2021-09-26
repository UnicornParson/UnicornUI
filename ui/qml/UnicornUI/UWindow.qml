import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow
{
    id: root

    width: wininfo.Width
    height: wininfo.Height
    color: skin.backgroundColor
    title: wininfo.Title
    visible: true
    flags: Qt.Window | Qt.WindowFullscreenButtonHint

    onWidthChanged: {
        wininfo.setWidth(root.width)
    }

    onHeightChanged: {
        wininfo.setHeight(root.height)
    }

    onTitleChanged: {
        wininfo.setTitle(root.title)
    }

    UDebugOverlay {
        anchors.fill: parent
        itemName: "UWindow"
    }
}

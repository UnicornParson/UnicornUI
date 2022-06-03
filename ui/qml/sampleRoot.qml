import QtQuick 2.12
import QtQuick.Controls 2.12
import UnicornUI 1.0

UWindow
{
    id: root
    backgroundElement.color: skin.backgroundColor

    ListModel {
        id: menuModel
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "Elements"; name: "page1"; entryEnabled: true }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 2"; name: "page2"; entryEnabled: true }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 3"; name: "page3"; entryEnabled: true }
    }
    UMenuPanel
    {
        id: menuPanel

        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom

        }
        width: 200
        model: menuModel
        onCurrentItemChanged: {
            // qrc:/qml/page1.qml
            content.source = "qrc:/qml/" + name + ".qml"

        }
    }

    UContentBox {
        id: content
        source: "qrc:/qml/page1.qml"
        anchors {
            left: menuPanel.right
            top: parent.top
            bottom: parent.bottom
            right: parent.right
        }
    }



Component.onCompleted: {
    if(!globals)
    {
        console.error("no globals")
        return
    }
    globals.setFpsIndicatorEnabled(false)
    globals.setDebugGridEnabled(true)
    globals.setPropertyLoggingEnabled(true)
    globals.setFpsBoosterEnabled(false)

    console.warn("1 width:", width)
    console.warn("1 height:", height)
}

}

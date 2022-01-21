import QtQuick 2.12
import QtQuick.Controls 2.12
import UnicornUI 1.0

UWindow
{
    id: root
    backgroundElement.color: skin.backgroundColor

    UPanel {
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom

        }
        width: 200
    }

    UTextButton {
        text: qsTr("Hello World")
        anchors.centerIn: parent
        width: 200
        height: 100
        anchors.top: parent.top
        anchors.left: parent.left

        onClicked: {
            console.warn("onClicked")
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

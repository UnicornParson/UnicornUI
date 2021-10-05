import QtQuick 2.12
import QtQuick.Controls 2.12
import UnicornUI 1.0

UWindow
{

    backgroundElement.color: skin.backgroundColor

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




}

import QtQuick
import QtQuick.Controls
import UnicornUI

ApplicationWindow
{

        width: wininfo.Width
        height:wininfo.Height
        color: skin.backgroundColor
        title: wininfo.Title
        visible: true
        flags: Qt.Window | Qt.WindowFullscreenButtonHint
        Rectangle {
            anchors.fill: parent
            anchors.margins: 0
            color: skin.backgroundColor

        }


        TextButton {
            //text: qsTr("Hello World")
            //anchors.centerIn: parent
            width: 200
            height: 100
            anchors.top: parent.top
            anchors.left: parent.left
        }

    }

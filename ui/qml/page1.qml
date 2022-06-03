import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
import UnicornUI 1.0

Item {
    id: root

    GridLayout {
        id: grid
        columns: 3
        anchors.fill: parent
        UTextButton {
            text: qsTr("UTextButton")
            Layout.column: 0
            Layout.row: 0

            Layout.fillHeight: true
            Layout.fillWidth: true

            onClicked: {
                backgroundColor = UColorConstants.w3.randomColor()
                borderColor = UColorConstants.w3.randomColor()
                textColor = UColorConstants.w3.randomColor()
                console.warn("onClicked")
            }
        }

        Item {
            Layout.column: 1
            Layout.row: 0

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Item {
            Layout.column: 2
            Layout.row: 0

            Layout.fillHeight: true
            Layout.fillWidth: true
        }


        Item {
            Layout.column: 0
            Layout.row: 1

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Item {
            Layout.column: 1
            Layout.row: 1

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Item {
            Layout.column: 2
            Layout.row: 1

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}

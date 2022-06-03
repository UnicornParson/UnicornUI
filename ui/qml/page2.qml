import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
import UnicornUI 1.0
Item {
    id: root
    GridLayout {
        id: grid
        columns: 3
        rows: 3
        anchors.fill: parent
        Rectangle {
            Layout.column: 0
            Layout.row: 0

            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "red"

            ShaderEffect {
                anchors.fill: parent
                property variant src: parent
                fragmentShader: "qrc:/qml/shaders/test1.frag.qsb"
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

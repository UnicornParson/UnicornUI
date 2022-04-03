import QtQuick
import Qt5Compat.GraphicalEffects

UPanel {
    id: root

    property bool interactive: false
    property alias model: list.model
    property alias listview: list

    signal currentItemChanged(string name, int index, string text)

    ListModel {
        id: placeholderModel
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 1" }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 2" }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 3" }
    }

    ListView {
        id: list
        anchors.fill: parent
        model: placeholderModel
        delegate: Rectangle {
            property string rowicon: icon
            property string rowtext: text

            property int pointSize: 12
            property int minimumPointSize: 10
            property color textColor: skin.mainFontColor
            property color backgroundColor: "transparent"
            property int marginTop: 0
            property int marginBottom: 0
            property int marginLeft: 0
            property int marginRight: 0
            property int spacing: 6
            height: 40
            width: ListView.view.width
            anchors.bottomMargin: 4
            color: backgroundColor

            Image {
                id: iconComponent
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: spacing
                height: 16
                width: 16
                source: parent.rowicon
                visible: !!parent.rowicon
            }


            Text {
                id: labelComponent
                anchors.left: iconComponent.visible ? iconComponent.right : parent.left
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: parent.rowtext
                color: parent.textColor
                minimumPointSize: parent.minimumPointSize
                font.pointSize: parent.pointSize
                fontSizeMode: Text.Fit
                anchors.leftMargin: spacing

            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    list.currentIndex = index
                }
            }
        }
        highlight: Rectangle {
            color: skin.backgroundColor
            opacity: 0.8
            Rectangle {
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                }
                width: 4
                color: skin.accentColor
            }
        }
        onCurrentItemChanged: {
            root.currentItemChanged(model.get(list.currentIndex).name, model.get(list.currentIndex).index, model.get(list.currentIndex).text)
        }
        focus: true
        interactive: root.interactive
    }
}

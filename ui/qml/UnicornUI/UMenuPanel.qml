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
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 1"; name: "n1"; entryEnabled: true }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 2"; name: "n2"; entryEnabled: false }
        ListElement { icon: "qrc:/qml/img/bullet_black.png"; text: "menu item 3"; name: "n3"; entryEnabled: true }
    }

    ListView {
        id: list
        anchors.fill: parent
        model: placeholderModel
        delegate: Rectangle {

            property string rowicon: icon
            property string rowtext: text
            property bool rowenabled: entryEnabled

            property int pointSize: 12
            property int minimumPointSize: 10
            property color textColor: (rowenabled) ? skin.mainFontColor : skin.mainDisabledFontColor
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
            opacity: (rowenabled) ? 1.0 : 0.6
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
                enabled: rowenabled
                onClicked: {
                    console.log("rowenabled", rowenabled)
                    if(rowenabled)
                    {
                        list.currentIndex = index
                        console.log("list.currentIndex", list.currentIndex)
                    }
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

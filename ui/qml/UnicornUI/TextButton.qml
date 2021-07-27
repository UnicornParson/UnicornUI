import QtQuick
import TemplatesTypes 1.0
Item {
    id: root

    property alias text: label.text
    property alias textFormat: label.textFormat
    property alias textColor: label.color

    property alias borderColor: border.color
    property alias backgroundColor: background.color

    property int borderSize : skin.defaultBorderSize
    property int borderRadius : skin.defaultBorderRadius
    property int margin: skin.defaultMargin

    property int state: ButtonState.Normal
    property bool isPressed: false

    signal clicked()
    signal pressed()
    signal released()


    Rectangle {
        id: border

        anchors.fill: parent
        color: skin.buttonBorderColor
        anchors.margins: margin
        radius: borderRadius
    }

    Rectangle {

        id: background
        anchors.fill: parent
        color: skin.buttonBackgroundColor
        anchors.margins: borderSize + margin
        radius: borderRadius
    }


    Text {
        id: label
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: background.width - (2 * margin)
        text: "no text"
        color: skin.buttonFontColor
        minimumPointSize: 10
        font.pointSize: 60
        fontSizeMode: Text.Fit
    }

    MouseArea {
        id: mouceArea
        anchors.fill: parent
        hoverEnabled: true
        enabled: root.state !== ButtonState.Disabled
        preventStealing: root.grabMouse
        onContainsMouseChanged:
        {
            if(root.state !== ButtonState.Disabled)
            {
                root.state = containsMouse ? ButtonState.Hovered : ButtonState.Normal
            }
        }


        onPressed: {
            root.isPressed = true
            root.pre
        }

        onReleased:
        {
            root.isPressed = false
        }

    }
    states: [
        State {
            name: "normal"
            when: root.state === ButtonState.Normal
            PropertyChanges {
                target: root
                layer.enabled: false
                layer.effect: null
            }
        }
    ]
}

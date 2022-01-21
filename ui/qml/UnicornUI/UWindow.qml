import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow
{
    id: root

    property alias backgroundElement: bgElement
    property alias itemName: dOverlay.itemName

    function showDialog(src)
    {
        dialogLoader.dialogSource = src
        dialogLoader.visible = true
    }

    function hideDialog()
    {
        dialogLoader.visible = false
        dialogLoader.dialogSource = ""
    }

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

    onFrameSwapped: {
        fpsItem.frameSwappedHandler()
    }

    UBackgroundElement {
        id: bgElement

        anchors.left: root.left
        anchors.top: root.top
        anchors.margins: 0
        width: root.width
        height: root.height
    }

    Rectangle {
        id: fpsBooster
        anchors.top: root.top
        anchors.left: root.left
        width: 1
        height: 1
        color: "red"
        visible: globals ? globals.fpsBoosterEnabled : false
    }

    Timer {
        id: updateTimer
        running: globals ? globals.fpsBoosterEnabled : false
        repeat: globals ? globals.fpsBoosterEnabled : false
        interval: 0
        onTriggered: {
            fpsBooster.color = Qt.rgba(Math.random(),Math.random(),Math.random(),1)
        }
        property int previousValue: 99
    }

    Component.onCompleted: {
        updateTimer.start()
    }

    UDebugOverlay {
        id: dOverlay
        anchors.left: root.left
        anchors.top: root.top
        //anchors.fill: parent
        itemName: "UWindow"
    }

    UFPSLabel {
        id: fpsItem
        anchors.top: dOverlay.visible ? dOverlay.bottom : root.top
        anchors.left: root.left
        anchors.topMargin: 16//dOverlay.visible ? dOverlay.label.height : 0
        anchors.leftMargin: 24
        textColor: "#6ab04c"
        bgColor: "#3d3d3d"
        spinerVisible: false
        spinerSource: "qrc:/qml/img/bullet-green.png"
        coloredImage: false
        Component.onCompleted: {
            console.log(anchors.topMargin)
        }
    }

    UModalDialog {
        id: dialogLoader

        anchors.fill: parent
        dialogWidth: root.width - 100
        dialogHeight: root.height - 100
        bgImageColor: "black"
        blurEffect: true
        /*    property int dialogWidth: 800
    property int dialogHeight: 600
    property alias dialogSource: dialogLoader.source
    property alias bgImageSource: bgImage.source
    property alias bgImageColor: bgImage.placeholderColor
    property bool blurEffect: true
    property bool blurEffectRadius: 100
    property bool blurEffectTransparentBorder : true*/
    }

    UGridLines {
        id: debugGrid

        visible: globals ? globals.fpsIndicatorEnabled : false
        gridColor: "#3E005D"
        gridOpacity: 0.5
        anchors.fill: parent
    }
}

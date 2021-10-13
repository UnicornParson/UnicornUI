import QtQuick 2.0
import QtGraphicalEffects 1.0

UBaseItem {
    id: root
    property int dialogWidth: 800
    property int dialogHeight: 600
    property alias dialogSource: dialogLoader.source
    property alias bgImageSource: bgImage.source
    property alias bgImageColor: bgImage.placeholderColor
    property bool blurEffect: true
    property int blurEffectRadius: 100
    property bool blurEffectTransparentBorder : true

    UImage
    {
        id: bgImage
        placeholderColor: "white"
        anchors.fill: root
    }
    ShaderEffectSource {
        id: effectSource


        sourceItem: bgImage
        anchors.fill: bgImage
        sourceRect: Qt.rect(x, y, width, height)
    }

    FastBlur{
        id: blur
        anchors.fill: effectSource

        source: effectSource
        radius: root.blurEffect ? root.blurEffectRadius : 0
        transparentBorder: root.blurEffectTransparentBorder
    }
    Loader {
        id: dialogLoader

        anchors.centerIn: root
        width: dialogWidth
        height: dialogHeight
        clip: true
    }
}

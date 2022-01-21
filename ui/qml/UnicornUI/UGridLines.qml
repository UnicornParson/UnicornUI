import QtQuick 2.0

Item {
    id: root

    property var sprites:[]
    property int stepx: 100
    property int stepy: 100
    property color gridColor: "black"
    property real gridOpacity: 1.0
    property real borderWidth: 0.5

    Item {
        id: container
        width: 300; height: 300
    }

    function recreate() {
        for(var child in root.sprites) {
            if(root.sprites[child]){root.sprites[child].destroy()}
        }
        root.sprites = []
        if (!root.visible)
            return

        for(var x = 0; x < root.width; x += root.stepx)
        {
            for(var y = 0; y < root.height; y += root.stepy)
            {
                var item = Qt.createQmlObject('import QtQuick 2.0; Rectangle {
                                                width: 100
                                                height: 100
                                                color: "transparent"
                                                border.color: "black"
                                                border.width: 1
                                                opacity: 1.0
                                                radius: 0
                                            }',root, ("dynamicSnippet_" + x + "_" + y) );

                item.x = x
                item.y = y
                item.width = root.stepx
                item.height = root.stepy
                item.opacity = root.gridOpacity / 2
                item.visible = true
                item.border.color = root.gridColor
                item.border.width = root.borderWidth
                root.sprites.push(item)
            }
        }
    }

    onWidthChanged: {
        recreate()
    }

    onHeightChanged: {
        recreate()
    }

    onVisibleChanged: {
        recreate()
    }
    Component.onCompleted: {
        recreate()
    }
}

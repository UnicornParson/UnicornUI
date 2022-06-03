pragma Singleton
import QtQuick 2.12

QtObject {
    id: root
    property var w3: QtObject
    {
        id: w3_
        readonly property color w3_flat_turquoise: "#1abc9c"
        readonly property color w3_flat_emerald: "#2ecc71"
        readonly property color w3_flat_peter_river: "#3498db"
        readonly property color w3_flat_amethyst: "#9b59b6"
        readonly property color w3_flat_wet_asphalt: "#34495e"
        readonly property color w3_flat_green_sea: "#16a085"
        readonly property color w3_flat_nephritis: "#27ae60"
        readonly property color w3_flat_belize_hole: "#2980b9"
        readonly property color w3_flat_wisteria: "#8e44ad"
        readonly property color w3_flat_midnight_blue: "#2c3e50"
        readonly property color w3_flat_sun_flower: "#f1c40f"
        readonly property color w3_flat_carrot: "#e67e22"
        readonly property color w3_flat_alizarin: "#e74c3c"
        readonly property color w3_flat_clouds: "#ecf0f1"
        readonly property color w3_flat_concrete: "#95a5a6"
        readonly property color w3_flat_orange: "#f39c12"
        readonly property color w3_flat_pumpkin: "#d35400"
        readonly property color w3_flat_pomegranate: "#c0392b"
        readonly property color w3_flat_silver: "#bdc3c7"
        readonly property color w3_flat_asbestos: "#7f8c8d"

        function getList() {
            return [
                        w3_flat_turquoise,
                        w3_flat_emerald,
                        w3_flat_peter_river,
                        w3_flat_amethyst,
                        w3_flat_wet_asphalt,
                        w3_flat_green_sea,
                        w3_flat_nephritis,
                        w3_flat_belize_hole,
                        w3_flat_wisteria,
                        w3_flat_midnight_blue,
                        w3_flat_sun_flower,
                        w3_flat_carrot,
                        w3_flat_alizarin,
                        w3_flat_clouds,
                        w3_flat_concrete,
                        w3_flat_orange,
                        w3_flat_pumpkin,
                        w3_flat_pomegranate,
                        w3_flat_silver,
                        w3_flat_asbestos
                    ]
        }
        function randomColor() {
            var list = getList();
            return list[Math.floor(Math.random() * (list.length - 1))]
        }
    }

    function randomColor() {
        return Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
    }
}

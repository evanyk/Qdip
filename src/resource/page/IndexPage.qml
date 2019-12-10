import QtQuick 2.12
import "../component"

Item{
    property list <ItemRect> items: [
        ItemRect {
            title: qsTr("Gray Image")
            summary: qsTr("Convert a color image to gray.")
        }
    ]
    anchors {
        fill: parent
    }

    Grid {
        id: gridBox
        anchors.fill: parent
        children: parent.items
    }
}

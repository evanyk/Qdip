import QtQuick 2.12

Rectangle {
    id: itemRectBox

    property var title: ""
    property var summary: ""

    width: 180
    height: 50
    radius: 5
    color: "#009999"

    Column {
        anchors {
            fill: parent
            margins: 2
        }
        Row {
            width: parent.width
            height: 23

            Text {
                font {
                    pointSize: 18
                    bold: true
                }
                color: "white"
                text: itemRectBox.title
            }
        }
        Row {
            width: parent.width
            height: 23

            Text {
                font {
                    pointSize: 14
                }
                color: "white"
                text: itemRectBox.summary
            }
        }
    }
}

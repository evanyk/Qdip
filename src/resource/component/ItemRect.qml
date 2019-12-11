import QtQuick 2.12
import QtQuick.Dialogs 1.2

Rectangle {
    id: itemRectBox

    property var title: ""
    property var summary: ""

    width: 220
    height: 50
    radius: 5
    color: "#009999"

    Column {
        anchors {
            fill: parent
            margins: 2
        }

        Rectangle {
            id: titleRow
            width: parent.width
            height: 23
            color: "#009999"
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }

            Text {
                font {
                    pointSize: 18
                    bold: true
                }
                color: "white"
                text: itemRectBox.title
            }
        }
        Rectangle {
            id: summaryRow
            width: parent.width
            height: 23
            color: "#009999"
            anchors {
                top: titleRow.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            Text {
                font {
                    pointSize: 14
                }
                color: "white"
                text: itemRectBox.summary
            }
        }

        FileDialog {
            id: fileDialog
            title: qsTr("Please choose a image file")
            nameFilters: ["Image Files (*.jpg *.jpeg *.png *.tif)", "All files (*)"]
            folder: shortcuts.pictures
            onRejected: {
                console.log("Canceled")
            }
            onAccepted: {
                console.log("File Url: " + fileDialog.fileUrl)
                ConvertToGrayImage.openImage(fileDialog.fileUrl)
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                fileDialog.open()
            }
        }
    }
}

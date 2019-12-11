import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import "./page"

Window {
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    title: qsTr("Digital Image Processing")

    // Outline box
    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            id: mainLayout
            Layout.fillWidth: parent
            Layout.fillHeight: parent
            color: "#efefef"

            Column {
                anchors.fill: parent

                Row {

                    width: parent.width
                    anchors{
                        top: parent.top
                        left: parent.left
                        right: parent.right
                    }

                    IndexPage {
                        id: btnItem
                    }
                }
                Row {
                    width: parent.width
                    anchors {
                        top: btnItem.bottom
                        left: parent.left
                        right: parent.right
                        bottom: parent.bottom
                        topMargin: 2
                    }

                    Image {
                        id: placeholderImage
                        source: ""

                        Connections {
                            target: ConvertToGrayImage
                            onCallQmlLoadImage: {
                                placeholderImage.source = "image://ImageProvider/" + Math.random()
                            }
                        }
                    }
                }
            }
        }
    }


}

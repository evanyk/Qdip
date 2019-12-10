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
            anchors.fill: parent
            anchors.margins: 1
            color: "#efefef"

            IndexPage {}
        }
    }


}

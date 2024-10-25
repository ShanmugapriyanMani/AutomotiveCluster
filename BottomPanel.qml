import QtQuick
import QtQuick.Layouts

RowLayout{
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    spacing: 50

    ColumnLayout {
        Text {
            text: "TOTAL"
            color: "#A0A0A0"
            font.family: "Helvetica Neue"
            font.pixelSize: 14
            font.weight: Font.Normal
            Layout.alignment : Text.AlignHCenter

        }

        RowLayout {
            Text {
                text: qsTr(totalKm)
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 18
                font.weight: Font.Normal

            }

            Text {
                text: "Km"
                color: "#424141"
                font.family: "Helvetica Neue"
                font.pixelSize: 18
                font.weight: Font.Normal
            }
        }
    }

    Rectangle {
        id: dividerId
        width: 2.5
        height: 70
        color: "transparent"
        border.width: 1
        border.color: "#2E2E2E"
    }

    ColumnLayout {
        Text {
            text: "TIME"
            color: "#A0A0A0"
            font.family: "Helvetica Neue"
            font.pixelSize: 14
            font.weight: Font.Normal
            Layout.alignment : Text.AlignHCenter
        }
        RowLayout {
            Text {
                text: currentTime
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 18
                font.weight: Font.Normal
            }

            Text {
                text: currentAP
                color: "#424141"
                font.family: "Helvetica Neue"
                font.pixelSize: 18
                font.weight: Font.Normal
            }
        }
    }
}


import QtQuick
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import experion.server.dbus


RowLayout {
    id: iconLayoutId
    spacing: 30
    anchors.centerIn: topRectId
    function restartSeatBeltBlink()
    {
        seatBeltAnimation.restart();
    }


    Image {
        id: oilCanId
        source: "qrc:/images/head/icons/off/la_oil-can.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: oilCanSourceForOverlay
            source: oilCanId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: oilCanId
            source: oilCanSourceForOverlay
            color: "orange"
            opacity: MyDBusServer.isOilCanWarning ? 1.0 : 0.0
        }


    }


    Image {
        id: carBatteryId
        source: "qrc:/images/head/icons/off/mdi_car-battery.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: carBatterySourceForOverlay
            source: carBatteryId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: carBatteryId
            source: carBatterySourceForOverlay
            color: "green"
            opacity: MyDBusServer.isCarBatteryWarning ? 1.0 : 0.0
        }
    }

    Image {
        id: carTireAlertId
        source: "qrc:/images/head/icons/off/mdi_car-tire-alert.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: carTireAlertSourceForOverlay
            source: carTireAlertId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: carTireAlertId
            source: carTireAlertSourceForOverlay
            color: "yellow"
            opacity: MyDBusServer.isCarPressureWarning ? 1.0 : 0.0
        }
    }

    Image {
        id: carChildSeatId
        source: "qrc:/images/head/icons/off/mdi_car-child-seat.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: carChildSeatSourceForOverlay
            source: carChildSeatId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: carChildSeatId
            source: carChildSeatSourceForOverlay
            color: "lightblue"
            opacity: MyDBusServer.isCarChildSeatWarning ? 1.0 : 0.0
        }
    }

    Image {
        id: carTractionControlId
        source: "qrc:/images/head/icons/off/mdi_car-traction-control.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: carTractionControlSourceForOverlay
            source: carTractionControlId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: carTractionControlId
            source: carTractionControlSourceForOverlay
            color: "green"
            opacity: MyDBusServer.isCarTractionControlWarning ? 1.0 : 0.0
        }
    }

    Image {
        id: seatBeltId
        source: "qrc:/images/head/icons/off/mdi_seatbelt.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: seatBeltSourceForOverlay
            source: seatBeltId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: seatBeltId
            source: seatBeltSourceForOverlay
            color: "red"
            id: redOverlay
            opacity: MyDBusServer.isSeatBeltWarning ? 1.0 : 0.0
        }

        SequentialAnimation {
            id: seatBeltAnimation
            loops: Animation.Infinite
            running: MyDBusServer.isSeatBeltWarning ? true : false

            PropertyAnimation {
                target: redOverlay
                property: "opacity"
                from: 1
                to: 0
                duration: 500
            }
            PropertyAnimation {
                target: redOverlay
                property: "opacity"
                from: 0
                to: 1
                duration: 500
            }
        }
    }

    Image {
        id: highBeamId
        source: "qrc:/images/head/icons/off/high-beam-2 1.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: highBeamSourceForOverlay
            source: highBeamId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: highBeamId
            source: highBeamSourceForOverlay
            color: "#0075FF"
            opacity: MyDBusServer.isHighBeamOn ? 1.0 : 0.0
        }
    }

    Image {
        id: carBrakeParkingId
        source: "qrc:/images/head/icons/off/mdi_car-brake-parking.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: carBrakeParkingIdSourceForOverlay
            source: carBrakeParkingId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: carBrakeParkingId
            source: carBrakeParkingIdSourceForOverlay
            color: "green"
            opacity: MyDBusServer.isCarBrakeParkingOn ? 1.0 : 0.0
        }
    }

    Image {
        id: absId
        source: "qrc:/images/head/icons/off/mdi_car-brake-parking-1.svg"
        Layout.preferredWidth: iconWidth
        Layout.preferredHeight: iconHeight
        fillMode: Image.PreserveAspectFit

        Image {
            id: absSourceForOverlay
            source: absId.source
            visible: false
        }

        ColorOverlay {
            anchors.fill: absId
            source: absSourceForOverlay
            color: "orange"
            opacity: MyDBusServer.isAbsOn ? 1.0 : 0.0
        }

    }

    Component.onCompleted:
    {


    }

}

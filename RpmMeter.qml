import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import experion.server.dbus

Item {
    id: rpmPanelId

    Image {
        id: rpmMeterId
        width: 450
        height: 450
        x: rootId.width - rpmMeterId.width - 10
        y: speedoMeterYAxis
        source: "qrc:/images/rpmmeter/rpmMeter.svg"

        layer.enabled: true
        layer.smooth: true

        layer.effect: DropShadow {
            radius: 10
            samples: 20
            horizontalOffset: 0
            verticalOffset: 0
            spread: 0
            color: "#2B2B2B"
        }

        Image {
            id: rpmNeedleCircleId
            anchors.centerIn: rpmMeterId
            scale: 0.9
            source: "qrc:/images/rpmmeter/rpmNeedleCircle.svg"

            layer.enabled: true
            layer.smooth: true
            layer.effect: DropShadow {
                radius: 14
                samples: 28
                horizontalOffset: 0
                verticalOffset: 0
                spread: 0
                color: "#272626"
            }
        }

        Image {
            id: rpmNeedleId
            scale: 0.725
            source: "qrc:/images/rpmmeter/rpmNeedle.svg"
            anchors.horizontalCenter: rpmNeedleCircleWhiteId.horizontalCenter
            anchors.verticalCenter: rpmNeedleCircleWhiteId.verticalCenter
            transformOrigin: Item.Right


            anchors.horizontalCenterOffset: -width/2


            rotation: -40

            layer.enabled: true
            layer.smooth: true
            layer.effect: DropShadow {
                radius: 14
                samples: 20
                horizontalOffset: -8
                verticalOffset: 10
                spread: 0
                color: "#E6135F"
                opacity: 0.85
            }


            SequentialAnimation {
                id: needleRotationSeqId
                NumberAnimation {
                    id: needleRotateForwardId
                    target: rpmNeedleId
                    property: "rotation"
                    from: rpmNeedleStartingAngle
                    to: rpmNeedleEndingAngle
                    duration: 1000
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    id: needleRotateBackId
                    target: rpmNeedleId
                    property: "rotation"
                    from: rpmNeedleEndingAngle
                    to: rpmNeedleStartingAngle
                    duration: 1000
                    easing.type: Easing.InOutQuad
                }

                onRunningChanged: {
                    MyDBusServer.setEngineTemperatureRange(0);
                }

            }

            Behavior on rotation {
                    SequentialAnimation {
                        NumberAnimation {
                            target: rpmNeedleId
                            property: "rotation"
                            duration: 2000
                            easing.type: Easing.InOutQuad
                        }
                        ScriptAction {
                            script: MyDBusServer.generateRPM()
                        }
                    }
                }

            Connections {
                target: MyDBusServer
                function onRpmChanged() {
                    rpmNeedleId.rotation = MyDBusServer.rpm;
                }
            }

           /* SequentialAnimation{
                id:needleRotationSeqId2
                NumberAnimation {
                    id: needleStart
                    target: rpmNeedleId
                    property: "rotation"
                    from: MyDBusServer.startingRPM
                    to: MyDBusServer.rpm
                    duration: 2000
                    easing.type: Easing.InOutQuad
                }
                onStopped: {
                        MyDBusServer.generateRPM()
                    }

            }


            Connections {
                target: MyDBusServer
                function onRpmChanged() {
                    // console.log("rpm starting range changed:", MyDBusServer.rpm);
                    needleRotationSeqId2.start();
                }
            }
            */

            Component.onCompleted: {
                needleRotationSeqId.running = true
            }
        }

        Image {
            id: rpmNeedleCircleRedId
            anchors.centerIn: parent
            scale: 0.9
            source: "qrc:/images/rpmmeter/rpmNeedleCircleRed.svg"

            layer.enabled: true
            layer.smooth: true
            layer.effect: DropShadow {
                radius: 14
                samples: 20
                horizontalOffset: 0
                verticalOffset: 0
                spread: 0
                color: "#E6135F"
            }
        }

        Image {
            id: rpmNeedleCircleWhiteId
            scale: 0.8
            anchors.horizontalCenter: rpmNeedleCircleRedId.horizontalCenter
            anchors.verticalCenter: rpmNeedleCircleRedId.verticalCenter
            source: "qrc:/images/rpmmeter/rpmNeedleCircleWhite.svg"
        }

    }

    Shape {
        id: tempRangeId
        anchors.horizontalCenter: rpmMeterId.horizontalCenter
        anchors.verticalCenter: rpmMeterId.verticalCenter

        width: 380
        height: 380
        layer.enabled: true
        layer.samples: 4

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#242A46"
            strokeWidth: 4
            capStyle: ShapePath.RoundCap
            PathAngleArc {
                centerX: 190; centerY: 190
                radiusX: 180; radiusY: 180
                startAngle: 120
                sweepAngle: -60
            }
        }

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#17C5FC"
            strokeWidth: 4.5
            capStyle: ShapePath.RoundCap
            PathAngleArc {
                centerX: 190; centerY: 190
                radiusX: 180; radiusY: 180
                startAngle: 120  //120
                sweepAngle: -(MyDBusServer.engineTemperatureRange)  //-45
            }
        }
    }

    RowLayout {
        anchors.bottomMargin: 40
        anchors.bottom: tempRangeId.bottom
        anchors.horizontalCenter: tempRangeId.horizontalCenter
        spacing: 10

        Image {
            id: tempIconId
            source: "qrc:/images/rpmmeter/temp-icon.svg"
        }

        RowLayout {
            Text {
                // text: "18.0"
                text: MyDBusServer.engineTemperature
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 16
                font.weight: Font.Normal
            }

            Text {
                text: "\u00B0C"
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 16
                font.weight: Font.Normal
            }
        }
    }
}

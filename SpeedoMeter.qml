import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import experion.server.dbus

Item {
    id: speedoPanelId
    Image {
        id: speedoMeterId
        x: 10
        y: speedoMeterYAxis
        width: 450
        height: 450
        source: "qrc:/images/speedometer/speedoMeter.svg"

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
            id: speedoNeedleCircleId
            anchors.centerIn: parent
            scale: 0.9
            source: "qrc:/images/speedometer/speedoNeedleCircle.svg"

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
            id: speedoNeedleId
            // ---------------------added---------------------------------
            scale: 0.725
            source: "qrc:/images/speedometer/speedoNeedle.svg"
            anchors.horizontalCenter: speedoNeedleCircleWhiteId.horizontalCenter
            anchors.verticalCenter: speedoNeedleCircleWhiteId.verticalCenter
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
                id: needleRotationSeq

                NumberAnimation {
                    id: needleRotateForward
                    target: speedoNeedleId
                    property: "rotation"
                    from: speedoNeedleStartingAngle
                    to: speedoNeedleEndingAngle
                    duration: 1000
                    easing.type: Easing.InOutQuad
                }

                NumberAnimation {
                    id: needleRotateBack
                    target: speedoNeedleId
                    property: "rotation"
                    from: speedoNeedleEndingAngle
                    to: speedoNeedleStartingAngle
                    duration: 1000
                    easing.type: Easing.InOutQuad
                }
            }


            Behavior on rotation {
                    SequentialAnimation {
                        NumberAnimation {
                            id:speedoAnimation
                            target: speedoNeedleId
                            property: "rotation"
                            easing.type: Easing.InOutQuad
                        }
                        ScriptAction {
                            script: MyDBusServer.generateSpeed()
                        }
                    }
                }

            Connections {
                target: MyDBusServer
                function onSpeedChanged() {
                    speedoAnimation.duration = Math.max(Math.abs(MyDBusServer.startingSpeed - MyDBusServer.speed) * 70, 500);
                    speedoNeedleId.rotation = MyDBusServer.speed;
                }
            }

            // SequentialAnimation {
            //     id: needleRotationSeq2

            //     NumberAnimation {
            //         id: needleStartId
            //         target: speedoNeedleId
            //         property: "rotation"
            //         from: MyDBusServer.startingSpeed
            //         to: MyDBusServer.speed
            //         duration: 2000
            //         easing.type: Easing.InOutQuad
            //     }

            //     onStopped: {
            //             MyDBusServer.generateSpeed()
            //         }

            // }



            Connections {
                target: MyDBusServer
                function onSpeedChanged() {
                    console.log("Speed angle changed:", MyDBusServer.speed);
                    // needleRotationSeq2.start();
                }
            }

            Component.onCompleted: {
                needleRotationSeq.running = true
            }
        }


        Image {
            id: speedoNeedleCircleRedId
            anchors.centerIn: parent
            scale: 0.9
            source: "qrc:/images/speedometer/speedoNeedleCircleRed.svg"

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
            id: speedoNeedleCircleWhiteId
            scale: 0.8
            anchors.horizontalCenter: speedoNeedleCircleRedId.horizontalCenter
            anchors.verticalCenter: speedoNeedleCircleRedId.verticalCenter
            source: "qrc:/images/speedometer/speedoNeedleCircleWhite.svg"
        }

    }

    Shape {
        id: fuelRangeId
        anchors.horizontalCenter: speedoMeterId.horizontalCenter
        anchors.verticalCenter: speedoMeterId.verticalCenter

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
                startAngle: 120
                sweepAngle: -(MyDBusServer.FuelRange)
            }
        }
    }

    RowLayout {
        anchors.bottomMargin: 40
        anchors.bottom: fuelRangeId.bottom
        anchors.horizontalCenter: fuelRangeId.horizontalCenter
        spacing: 10

        Image {
            id: fuelIconId
            source: "qrc:/images/speedometer/fuel.svg"
        }

        RowLayout {
            Text {
                text: speedoBalanceFuel
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 16
                font.weight: Font.Normal
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text: "Km"
                color: "#E7E8FF"
                font.family: "Helvetica Neue"
                font.pixelSize: 16
                font.weight: Font.Normal
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

}





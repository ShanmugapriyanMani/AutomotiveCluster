import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
import experion.server.dbus

RowLayout {
    id: centerRowId
    anchors.horizontalCenter: parent.horizontalCenter
    y: gearRectangleYAxis
    spacing: 100

    function rightIndicatorRestartBlink() {
        console.log("Restarting right blink animation");
        rightBlinkAnimation.restart();
    }

    function leftIndicatorRestartBlink() {
        console.log("Restarting left blink animation");
        leftBlinkAnimation.restart();
    }

    // Timer for synchronization
    // Timer {
    //     id: syncTimer
    //     interval: 1000
    //     repeat: true
    //     running: MyDBusServer.isLeftIndicatorOn && MyDBusServer.isRightIndicatorOn
    //     onTriggered: {
    //         leftBlinkAnimation.restart();
    //         rightBlinkAnimation.restart();
    //     }
    // }

    Image {
        id: leftIndicatorId
        source: "qrc:/images/indicator/arrow-left.svg"

        Image {
            id: leftIndicatorSourceForOverlay
            source: leftIndicatorId.source
            visible: false
        }

        ColorOverlay {
            id: leftIndicatorOverlay
            anchors.fill: leftIndicatorId
            source: leftIndicatorSourceForOverlay
            color: "green"
            opacity: MyDBusServer.isLeftIndicatorOn ? 1.0 : 0.0
        }

        SequentialAnimation {
            id: leftBlinkAnimation
            loops: Animation.Infinite
            running: MyDBusServer.isLeftIndicatorOn ? true : false

            PropertyAnimation {
                target: leftIndicatorOverlay
                property: "opacity"
                from: 1
                to: 0
                duration: 500
            }
            PropertyAnimation {
                target: leftIndicatorOverlay
                property: "opacity"
                from: 0
                to: 1
                duration: 500
            }
        }
    }

    Rectangle {
        width: 80
        height: 80
        radius: 20
        border.width: 0.9
        border.color: "#2B2B2B"

        gradient: Gradient {
            GradientStop { position: 0.0; color: "#1A1A1A" }
            GradientStop { position: 1.0; color: "#070707" }
        }

        layer.enabled: true
        layer.effect: DropShadow {
            horizontalOffset: -36
            verticalOffset: -10.36
            radius: 80
            color: Qt.rgba(1, 1, 1, 0.04)
        }

        SwipeView {
            id: view

            currentIndex: MyDBusServer.driveMode
            anchors.fill: parent
            orientation: Qt.Vertical
            interactive: false

            Item {
                id: firstPage
                Image {
                    id: im1
                    anchors.centerIn: parent
                    source: "qrc:/images/driving-mode/R.svg"
                }
            }
            Item {
                id: secondPage
                Image {
                    id: im2
                    anchors.centerIn: parent
                    source: "qrc:/images/driving-mode/P.svg"
                }
            }
            Item {
                id: thirdPage
                Image {
                    id: im3
                    anchors.centerIn: parent
                    source: "qrc:/images/driving-mode/D.svg"
                }
            }
        }

    }


    Image {
        id: rightIndicatorId
        source: "qrc:/images/indicator/arrow-right.svg"

        Image {
            id: rightIndicatorSourceForOverlay
            source: rightIndicatorId.source
            visible: false
        }

        ColorOverlay {
            id: rightIndicatorOverlay
            anchors.fill: rightIndicatorId
            source: rightIndicatorSourceForOverlay
            color: "green"
            opacity: MyDBusServer.isRightIndicatorOn ? 1.0 : 0.0
        }


        SequentialAnimation {
            id: rightBlinkAnimation
            loops: Animation.Infinite
            running: MyDBusServer.isRightIndicatorOn ? true : false

             PropertyAnimation {
                 target: rightIndicatorOverlay
                 property: "opacity"
                 from: 1
                 to: 0
                 duration: 500
             }
             PropertyAnimation {
                 target: rightIndicatorOverlay
                 property: "opacity"
                 from: 0
                 to: 1
                 duration: 500
             }
         }
    }
}

import QtQuick
import QtQuick.Controls
import experion.server.dbus

Window {
    id: rootId
    width: 1280
    height: 800
    minimumWidth: 1280
    minimumHeight: 800
    visible: true
    title: qsTr("Instrument Cluster")
    color: colorBackground

    // flags: Qt.FramelessWindowHint


    readonly property color colorBackground: "#000"
    readonly property color circleInnerColor: "#0A0A0A"
    readonly property color circleBorderColor: "#2B2B2B"
    readonly property color defaultColor: Qt.rgba(0,0,0,0)
    readonly property int iconWidth: 30
    readonly property int iconHeight: 30
    readonly property int gearRectangleYAxis: 120
    readonly property int speedoMeterYAxis: 150


    // Driving Mode
    enum VehicleState{
        None,
        Park,
        Drive,
        Reverse
    }

    // readonly property int currentVehicleState: VehicleState.Park

    //Speedometer
    readonly property int speedoNeedleStartingAngle: -40
    readonly property int speedoNeedleEndingAngle: 220

    readonly property int speedoBalanceFuel: 482

    //Rpmmeter
    readonly property int rpmNeedleStartingAngle: -40
    readonly property int rpmNeedleEndingAngle: 220
    // property int speedStartingValue: -40

    readonly property int rpmTemperature: 18



    // Bottom panel
    readonly property string totalKm: "20853.5 "

    // Current Time
    property string currentTime: currentTime//"--:--:--"
    property string currentAP: currentAP//"--"


    Timer {
        id: timer
        interval: 1
        running: true
        repeat: true
        onTriggered: {
            var time = new Date();
            var hours = time.getHours();
            var minutes = time.getMinutes();
            var seconds = time.getSeconds();
            var period = (hours < 12) ? "AM" : "PM";
            hours = (hours > 12) ? hours - 12 : hours;
            hours = (hours === 0) ? 12 : hours;
            currentTime = hours + ":" + minutes + ":" + seconds + " "
            currentAP = period
        }
    }

    Image {
        id: topRectId
        width: 1100
        height: 80
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        source: "qrc:/images/head/topRectangle.svg"

        TopPanel {
        id:topPanelId
        }
    }


    DrivingModeAndIndicator {
    id:indicatorId
    }

    SpeedoMeter {}

    Navigator {
        anchors.horizontalCenter:  parent.horizontalCenter
        anchors.bottom: parent.bottom
    }

    RpmMeter {}

    Image {
        id: btmRectImageId
        width: 900
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        source: "qrc:/images/bottom/bottomrectangle.svg"

        BottomPanel {}
    }

    BlinkController {
        indicator:indicatorId
        topPanel:topPanelId
    }

    Component.onCompleted: {
        MyDBusServer.onLoad();
    }

}

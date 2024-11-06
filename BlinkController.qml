import QtQuick
import experion.server.dbus

Item {
    id: blinkController
    signal leftIndicatorRestart();
    signal rightIndicatorRestart();

    signal seatBeltRestart();

    required property DrivingModeAndIndicator indicator
    required property TopPanel topPanel

    onIndicatorChanged: {
        leftIndicatorRestart.connect(indicator.leftIndicatorRestartBlink)
        rightIndicatorRestart.connect(indicator.rightIndicatorRestartBlink)
    }

    onTopPanelChanged: {
        seatBeltRestart.connect(topPanel.restartSeatBeltBlink)
    }

    Timer
    {
        id: syncTimer
        interval: 1000
        repeat: false
        running: false
        onTriggered: {
            if(MyDBusServer.isLeftIndicatorOn)
            {
                leftIndicatorRestart();
            }
            if(MyDBusServer.isRightIndicatorOn)
            {
                rightIndicatorRestart();
            }
            if(MyDBusServer.isSeatBeltWarning)
            {
                seatBeltRestart();
            }
        }
    }

    function handleBlinking()
    {
        syncTimer.running = MyDBusServer.isLeftIndicatorOn || MyDBusServer.isRightIndicatorOn || MyDBusServer.isSeatBeltWarning

    }
    Connections {
            target: MyDBusServer

            function onIsLeftIndicatorOnChanged() {
                handleBlinking();
            }

            function onIsRightIndicatorOnChanged() {
                handleBlinking();
            }

            function onIsSeatBeltWarningChanged() {
                handleBlinking();
            }
        }

}

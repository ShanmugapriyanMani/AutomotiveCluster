#include "dbusserver.h"

DBusServer::DBusServer(QObject *parent)
    : QObject{parent}
{
    setIsOilCanWarning(true);
}

bool DBusServer::isOilCanWarning() const
{
    qDebug() << "Oil warning: " << m_isOilCanWarning;
    return m_isOilCanWarning;
}

void DBusServer::setIsOilCanWarning(bool newIsOilCanWarning)
{
    qDebug() << "Set Oil warning: " << newIsOilCanWarning;
    if (m_isOilCanWarning == newIsOilCanWarning)
        return;
    m_isOilCanWarning = newIsOilCanWarning;
    emit isOilCanWarningChanged();
}

bool DBusServer::isCarBatteryWarning() const
{
    qDebug() << "Battery Warning: " << m_isCarBatteryWarning;
    return m_isCarBatteryWarning;
}

void DBusServer::setIsCarBatteryWarning(bool newIsCarBatteryWarning)
{
    qDebug() << "Set Car Battery Warning: " << newIsCarBatteryWarning;
    if (m_isCarBatteryWarning == newIsCarBatteryWarning)
        return;
    m_isCarBatteryWarning = newIsCarBatteryWarning;
    emit isCarBatteryWarningChanged();
}

bool DBusServer::isCarPressureWarning() const
{
    qDebug() << "Pressure Warning: " << m_isCarPressureWarning;
    return m_isCarPressureWarning;
}

void DBusServer::setIsCarPressureWarning(bool newIsCarPressureWarning)
{
    qDebug() << "Set Car Pressure Warning: " << newIsCarPressureWarning;
    if (m_isCarPressureWarning == newIsCarPressureWarning)
        return;
    m_isCarPressureWarning = newIsCarPressureWarning;
    emit isCarPressureWarningChanged();
}

bool DBusServer::isCarChildSeatWarning() const
{
    qDebug() << "Child seat Warning: " << m_isCarChildSeatWarning;
    return m_isCarChildSeatWarning;
}

void DBusServer::setIsCarChildSeatWarning(bool newIsCarChildSeatWarning)
{
    qDebug() << "Set Car Child Seat Warning: " << newIsCarChildSeatWarning;
    if (m_isCarChildSeatWarning == newIsCarChildSeatWarning)
        return;
    m_isCarChildSeatWarning = newIsCarChildSeatWarning;
    emit isCarChildSeatWarningChanged();
}

bool DBusServer::isCarTractionControlWarning() const
{
    qDebug() << "Traction Control Warning: " << m_isCarTractionControlWarning;
    return m_isCarTractionControlWarning;
}

void DBusServer::setIsCarTractionControlWarning(bool newIsCarTractionControlWarning)
{
    qDebug() << "Set Car Traction Control Warning: " << newIsCarTractionControlWarning;
    if (m_isCarTractionControlWarning == newIsCarTractionControlWarning)
        return;
    m_isCarTractionControlWarning = newIsCarTractionControlWarning;
    emit isCarTractionControlWarningChanged();
}

bool DBusServer::isSeatBeltWarning() const
{
    qDebug() << "Seat Bealt Warning: " << m_isSeatBeltWarning;
    return m_isSeatBeltWarning;
}

void DBusServer::setIsSeatBeltWarning(bool newIsSeatBeltWarning)
{
    qDebug() << "Set Seat Belt warning: " << newIsSeatBeltWarning;
    if (m_isSeatBeltWarning == newIsSeatBeltWarning)
        return;
    m_isSeatBeltWarning = newIsSeatBeltWarning;
    emit isSeatBeltWarningChanged();
}

bool DBusServer::isHighBeamOn() const
{
    qDebug() << "High Bean On: " << m_isHighBeamOn;
    return m_isHighBeamOn;
}

void DBusServer::setIsHighBeamOn(bool newIsHighBeamOn)
{
    qDebug() << "Set High Beam: " << newIsHighBeamOn;
    if (m_isHighBeamOn == newIsHighBeamOn)
        return;
    m_isHighBeamOn = newIsHighBeamOn;
    emit isHighBeamOnChanged();
}

bool DBusServer::isAbsOn() const
{
    qDebug() << "Anti Breaking System On: " << m_isAbsOn;
    return m_isAbsOn;
}

void DBusServer::setIsAbsOn(bool newIsAbsOn)
{
    qDebug() << "Set ABS: " << newIsAbsOn;
    if (m_isAbsOn == newIsAbsOn)
        return;
    m_isAbsOn = newIsAbsOn;
    emit isAbsOnChanged();
}

bool DBusServer::isCarBrakeParkingOn() const
{
    qDebug() << "Car Break Parking On: " << m_isCarBrakeParkingOn;
    return m_isCarBrakeParkingOn;
}

void DBusServer::onLoad()
{
    qDebug() << "Inside onLoad function: ";
    this->setIsCarBrakeParkingOn(true);
    this->setIsAbsOn(true);
    this->setIsCarBatteryWarning(true);
    this->setIsCarChildSeatWarning(true);
    this->setIsSeatBeltWarning(true);
    this->setIsCarPressureWarning(true);
    this->setIsCarTractionControlWarning(true);
    this->setIsOilCanWarning(true);
    this->setIsHighBeamOn(true);
    this->setIsLeftIndicatorOn(true);
    this->setIsRightIndicatorOn(true);
    QTimer::singleShot(2000, this, [this](){
        this->setIsCarBrakeParkingOn(false);
        // this->setIsCarBatteryWarning(false);
        this->setIsCarChildSeatWarning(false);
        this->setIsCarPressureWarning(false);
        this->setIsCarTractionControlWarning(false);
        // this->setIsOilCanWarning(false);
        // this->setIsHighBeamOn(false);
        this->setDriveMode(2);
        this->setIsLeftIndicatorOn(false);
        this->setIsRightIndicatorOn(false);
    });

}

void DBusServer::setIsCarBrakeParkingOn(bool newIsCarBrakeParkingOn)
{
    qDebug() << "Set Car Parking: " << newIsCarBrakeParkingOn;
    if (m_isCarBrakeParkingOn == newIsCarBrakeParkingOn)
        return;
    m_isCarBrakeParkingOn = newIsCarBrakeParkingOn;
    emit isCarBrakeParkingOnChanged();
}

bool DBusServer::isLeftIndicatorOn() const
{
    return m_isLeftIndicatorOn;
}

void DBusServer::setIsLeftIndicatorOn(bool newIsLeftIndicatorOn)
{
    qDebug() << "Set Left Indicator On: " << newIsLeftIndicatorOn;
    if (m_isLeftIndicatorOn == newIsLeftIndicatorOn)
        return;
    m_isLeftIndicatorOn = newIsLeftIndicatorOn;
    emit isLeftIndicatorOnChanged();
}

bool DBusServer::isRightIndicatorOn() const
{
    return m_isRightIndicatorOn;
}

void DBusServer::setIsRightIndicatorOn(bool newIsRightIndicatorOn)
{
    qDebug() << "Set Right Indicator On: " << newIsRightIndicatorOn;
    if (m_isRightIndicatorOn == newIsRightIndicatorOn)
        return;
    m_isRightIndicatorOn = newIsRightIndicatorOn;
    emit isRightIndicatorOnChanged();
}


int DBusServer::driveMode() const
{
    return m_driveMode;
}

void DBusServer::setDriveMode(int newDriveMode)
{
    qDebug() << "Set Drive mode: " << newDriveMode;
    if (m_driveMode == newDriveMode)
        return;
    m_driveMode = newDriveMode;
    emit driveModeChanged();
}

// int DBusServer::speedStartingRange() const
// {
//     return m_speedStartingRange;
// }

// void DBusServer::setSpeedStartingRange(int newSpeedStartingRange)
// {
//     qDebug() << "setSpeedStartRange: " << newSpeedStartingRange;
//     if (m_speedStartingRange == newSpeedStartingRange)
//         return;
//     m_speedStartingRange = newSpeedStartingRange;
//     emit speedStartingRangeChanged();
// }

// int DBusServer::speedStopRange() const
// {
//     return m_speedStopRange;
// }

// void DBusServer::setSpeedStopRange(int newSpeedStopRange)
// {
//     qDebug() << "setSpeedStopRange: " << newSpeedStopRange;
//     if (m_speedStopRange == newSpeedStopRange)
//         return;
//     m_speedStopRange = newSpeedStopRange;
//     emit speedStopRangeChanged();
// }

// void DBusServer::setSpeedoMeterRange(int speedStartingRange, int speedStopingRange)
// {
//     qDebug() << "Changed: " ;
//     setSpeedStopRange(speedStopingRange - 40);
//     setSpeedStartingRange(speedStartingRange - 40);
// }

// -----------------------------------------SpeedoMeter----------------------------------------------------
int DBusServer::speed() const
{
    return m_speed;
}

void DBusServer::setSpeed(int newSpeed)
{
    setStartingSpeed(speed());
    qDebug() << "new Speed is :" << newSpeed;
    if (m_speed == newSpeed)
        return;
    m_speed = newSpeed - 40;
    emit speedChanged();
}

int DBusServer::startingSpeed() const
{
    return m_startingSpeed;
}

void DBusServer::setStartingSpeed(int newStartingSpeed)
{
    qDebug() << "Starting speed updated to : " << newStartingSpeed;
    if (m_startingSpeed == newStartingSpeed)
        return;
    m_startingSpeed = newStartingSpeed;
    emit startingSpeedChanged();
}

// --------------------------------------------RPM Meter------------------------------------------------------

int DBusServer::startingRPM() const
{
    return m_startingRPM;
}

void DBusServer::setStartingRPM(int newStartingRPM)
{
    if (m_startingRPM == newStartingRPM)
        return;
    m_startingRPM = newStartingRPM;
    emit startingRPMChanged();
}

int DBusServer::rpm() const
{
    return m_rpm;
}

void DBusServer::setRpm(int newRpm)
{
    setStartingRPM(rpm());
    // m_rpm = ((newRpm / 1000) * 40) -40;
    qDebug() << "rpm updated to : " << newRpm;
    if (m_rpm == newRpm)
        return;
    m_rpm = newRpm;
    qDebug() << "new angle :" << m_rpm;
    emit rpmChanged();
}

// int DBusServer::RPMvalue() const
// {
//     return m_RPMvalue;
// }

// void DBusServer::setRPMvalue(int newRPMvalue)
// {
//     setStartingRPM(RPMvalue());
//     qDebug() << "Starting speed updated to : " << newRPMvalue;

//     if (m_RPMvalue == newRPMvalue)
//         return;
//     m_RPMvalue = ((newRPMvalue/1000) * 40) - 40;
//     emit RPMvalueChanged();
// }


// int DBusServer::rpmStartingRange() const
// {
//     return m_rpmStartingRange;
// }

// void DBusServer::setRpmStartingRange(int newRpmStartingRange)
// {
//     qDebug() << "setRpmStartingRange: " << newRpmStartingRange;
//     if (m_rpmStartingRange == newRpmStartingRange)
//         return;
//     m_rpmStartingRange = newRpmStartingRange;
//     emit rpmStartingRangeChanged();
// }

// int DBusServer::rpmStopingRange() const
// {
//     return m_rpmStopingRange;
// }

// void DBusServer::setRpmStopingRange(int newRpmStopingRange)
// {
//     qDebug() << "setRpmStopingRange: " << newRpmStopingRange;
//     if (m_rpmStopingRange == newRpmStopingRange)
//         return;
//     m_rpmStopingRange = newRpmStopingRange;
//     emit rpmStopingRangeChanged();
// }

// void DBusServer::setRPMMeterRange(int rpmStartingRange, int rpmStopingRange)
// {
//     qDebug() << "Changed: " ;
//     setRpmStopingRange((rpmStopingRange * 40) - 40);
//     setRpmStartingRange((rpmStartingRange * 40) - 40);
// }

int DBusServer::FuelRange() const
{
    return m_FuelRange;
}

void DBusServer::setFuelRange(int newFuelRange)
{
    qDebug() << "Fuel Range Changed: " << newFuelRange;
    if (m_FuelRange == newFuelRange)
        return;
    m_FuelRange = newFuelRange;
    emit FuelRangeChanged();
}

int DBusServer::engineTemperatureRange() const
{
    return m_engineTemperatureRange;
}

void DBusServer::setEngineTemperatureRange(int newEngineTemperatureRange)
{
    int rpmInPercentage = static_cast<int>(((newEngineTemperatureRange + 40)/260.0f) * 100.0f);
    qDebug() << "rpm in percentage: " << rpmInPercentage;

    newEngineTemperatureRange = (rpmInPercentage * 60)/100;

    qDebug() << "new Temperature: " << newEngineTemperatureRange;
    if (m_engineTemperatureRange == newEngineTemperatureRange)
        return;
    m_engineTemperatureRange = newEngineTemperatureRange;
    emit engineTemperatureChangedRange();
}

int DBusServer::engineTemperature() const
{
    return m_engineTemperature;
}

void DBusServer::setEngineTemperature(int newEngineTemperature)
{

    int rpmInPercentage = static_cast<int>(((newEngineTemperature + 40)/260.0f) * 100.0f);
    qDebug() << "rpm in percentage: " << rpmInPercentage;

    newEngineTemperature = (rpmInPercentage * 60)/100;

    if (m_engineStarted)
    {
        newEngineTemperature += 18;
    }


    if (m_engineTemperature == newEngineTemperature)
        return;
    m_engineTemperature = newEngineTemperature;
    emit engineTemperatureChanged();
}

bool DBusServer::engineStarted() const
{
    return m_engineStarted;
}

void DBusServer::setEngineStarted(bool newEngineStarted)
{
    if (m_engineStarted == newEngineStarted)
        return;
    m_engineStarted = newEngineStarted;
    emit engineStartedChanged();
}

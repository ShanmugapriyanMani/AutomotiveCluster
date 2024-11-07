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
    // qDebug() << "Set Seat Belt warning: " << newIsSeatBeltWarning;
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

// -----------------------------------------SpeedoMeter----------------------------------------------------

int DBusServer::startingSpeedRange() const
{
    return m_startingSpeedRange;
}

void DBusServer::setStartingSpeedRange(int newStartingSpeedRange)
{
    qDebug() << "from function  setStartingstarting range" << newStartingSpeedRange ;
    if (m_startingSpeedRange == newStartingSpeedRange)
        return;
    m_startingSpeedRange = newStartingSpeedRange;
    emit startingSpeedRangeChanged();
}

int DBusServer::endingSpeedRange() const
{
    return m_endingSpeedRange;
}

void DBusServer::setEndingSpeedRange(int newEndingSpeedRange)
{
    if (m_endingSpeedRange == newEndingSpeedRange)
        return;
    m_endingSpeedRange = newEndingSpeedRange;
    emit endingSpeedRangeChanged();
}

void DBusServer::setSpeedStartingAndEndingRange(int newStartingSpeedRange, int newEndingSpeedRange)
{
    qDebug() << "from function starting range" << newStartingSpeedRange << "from function ending " << newEndingSpeedRange ;
    setStartingSpeedRange(newStartingSpeedRange);
    setEndingSpeedRange(newEndingSpeedRange);

    generateSpeed();

}

void DBusServer::generateSpeed()
{
    static int previousSpeed = -1;
    int speedGenerated;

    qDebug() << "starting range" << m_startingSpeedRange << "ending range " << m_endingSpeedRange ;

    do{

        speedGenerated = QRandomGenerator::global()->bounded(m_startingSpeedRange, m_endingSpeedRange);
    }while(previousSpeed == speedGenerated);

    qDebug() << "Speed Generated" << speedGenerated << "Previous" << previousSpeed;

    previousSpeed = speedGenerated;

    setSpeed(speedGenerated);
}

int DBusServer::speed() const
{
    return m_speed;
}

void DBusServer::setSpeed(int newSpeed)
{
    setStartingSpeed(m_speed);
    // if (m_speed == newSpeed){
    //     qDebug() << "Set Speed is same fromsetSpeed";
    //     return;
    // }
    m_speed = newSpeed - 40;
    qDebug() << "new Speed is :" << m_speed ;
    emit speedChanged();
}

int DBusServer::startingSpeed() const
{
    return m_startingSpeed;
}

void DBusServer::setStartingSpeed(int newStartingSpeed)
{

    // qDebug() << "Starting speed updated to : " << newStartingSpeed;
    if (m_startingSpeed == newStartingSpeed){
        qDebug() << "Starting Speed is same";
        return;
    }
    m_startingSpeed = newStartingSpeed;
    emit startingSpeedChanged();
}

// --------------------------------------------RPM Meter------------------------------------------------------
int DBusServer::startingRPMRange() const
{
    return m_startingRPMRange;
}

void DBusServer::setStartingRPMRange(int newStartingRPMRange)
{
    if (m_startingRPMRange == newStartingRPMRange)
        return;
    m_startingRPMRange = newStartingRPMRange;
    emit startingRPMRangeChanged();
}

int DBusServer::endingRPMRange() const
{
    return m_endingRPMRange;
}

void DBusServer::setEndingRPMRange(int newEndingRPMRange)
{
    // if (m_endingRPMRange == newEndingRPMRange)
    //     return;
    m_endingRPMRange = newEndingRPMRange;
    emit endingRPMRangeChanged();
}


void DBusServer::setRpmStartingAndEndingRange(int rpmStartingRange, int rpmStopingRange)
{
    setStartingRPMRange(rpmStartingRange);
    setEndingRPMRange(rpmStopingRange);
    generateRPM();

}

void DBusServer::generateRPM()
{
    static int previousRpm = -1;
    int rpmGenerated;

    do{
        rpmGenerated = QRandomGenerator::global()->bounded(m_startingRPMRange, m_endingRPMRange);
    }while(previousRpm == rpmGenerated);

    qDebug() << "Rpm generated" << rpmGenerated;

    QVector<int> rpmLimits = {0, 2000, 4000, 6000}; // RPM thresholds
    QVector<float> multipliers = {0.04, 0.05, 0.04}; // Multipliers for each range

    int rpmAngleGeneratedInFloat = 0;

    for (int i = 0; i < rpmLimits.size() - 1; i++) {
        if (rpmGenerated > rpmLimits[i] && rpmGenerated <= rpmLimits[i + 1]) {
            rpmAngleGeneratedInFloat += (rpmGenerated - rpmLimits[i]) * multipliers[i];

            for (int j = 0; j < i; j++) {
                rpmAngleGeneratedInFloat += (rpmLimits[j + 1] - rpmLimits[j]) * multipliers[j];
            }
            break;
        }
    }
    int rpmAngle = static_cast<int>((rpmAngleGeneratedInFloat) - 40 );

    setRpm(rpmAngle);
}


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
    setEngineTemperature(newEngineTemperatureRange);
    newEngineTemperatureRange = (newEngineTemperatureRange * 60)/100;

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

void DBusServer::setEngineTemperature(int newEngineTempeInPercentage)
{
    float minTemp = 20 ; // Minimum temperature (0% corresponds to 20°C)
    float maxTemp = 120;  // Maximum temperature (100% corresponds to 120°C)
    float newEngineTemperature = 20;

    if (newEngineTempeInPercentage < 0)
    {
        newEngineTemperature =  minTemp;
    }
     // If percentage is negative, return minimum temperature
    else if (newEngineTempeInPercentage > 100)
    {
        newEngineTemperature = maxTemp;
    }
    else if(newEngineTempeInPercentage <= 50)
    {
        newEngineTemperature =  minTemp + (newEngineTempeInPercentage / 50.0f) * (90 - minTemp);
    }
    else if(newEngineTempeInPercentage > 50)
    {
        newEngineTemperature =  90 + ((newEngineTempeInPercentage - 50) / 50.0f) * (maxTemp - 90);
    }
    // int finalEngineTemperature = static_cast<int>(newEngineTemperature);

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

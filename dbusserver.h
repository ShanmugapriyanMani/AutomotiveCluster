#ifndef DBUSSERVER_H
#define DBUSSERVER_H

#include <QObject>
#include <QtQml>

class DBusServer : public QObject
{

    Q_OBJECT

    Q_PROPERTY(bool isOilCanWarning READ isOilCanWarning WRITE setIsOilCanWarning NOTIFY isOilCanWarningChanged FINAL)
    Q_PROPERTY(bool isCarBatteryWarning READ isCarBatteryWarning WRITE setIsCarBatteryWarning NOTIFY isCarBatteryWarningChanged FINAL)
    Q_PROPERTY(bool isCarPressureWarning READ isCarPressureWarning WRITE setIsCarPressureWarning NOTIFY isCarPressureWarningChanged FINAL)
    Q_PROPERTY(bool isCarChildSeatWarning READ isCarChildSeatWarning WRITE setIsCarChildSeatWarning NOTIFY isCarChildSeatWarningChanged FINAL)
    Q_PROPERTY(bool isCarTractionControlWarning READ isCarTractionControlWarning WRITE setIsCarTractionControlWarning NOTIFY isCarTractionControlWarningChanged FINAL)
    Q_PROPERTY(bool isSeatBeltWarning READ isSeatBeltWarning WRITE setIsSeatBeltWarning NOTIFY isSeatBeltWarningChanged FINAL)
    Q_PROPERTY(bool isHighBeamOn READ isHighBeamOn WRITE setIsHighBeamOn NOTIFY isHighBeamOnChanged FINAL)
    Q_PROPERTY(bool isCarBrakeParkingOn READ isCarBrakeParkingOn WRITE setIsCarBrakeParkingOn NOTIFY isCarBrakeParkingOnChanged FINAL)
    Q_PROPERTY(bool isAbsOn READ isAbsOn WRITE setIsAbsOn NOTIFY isAbsOnChanged FINAL)
    Q_PROPERTY(bool isLeftIndicatorOn READ isLeftIndicatorOn WRITE setIsLeftIndicatorOn NOTIFY isLeftIndicatorOnChanged FINAL)
    Q_PROPERTY(bool isRightIndicatorOn READ isRightIndicatorOn WRITE setIsRightIndicatorOn NOTIFY isRightIndicatorOnChanged FINAL)
    Q_PROPERTY(int driveMode READ driveMode WRITE setDriveMode NOTIFY driveModeChanged FINAL)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged FINAL)
    Q_PROPERTY(int startingSpeed READ startingSpeed WRITE setStartingSpeed NOTIFY startingSpeedChanged FINAL)
    Q_PROPERTY(int startingRPM READ startingRPM WRITE setStartingRPM NOTIFY startingRPMChanged FINAL)
    Q_PROPERTY(int startingSpeedRange READ startingSpeedRange WRITE setStartingSpeedRange NOTIFY startingSpeedRangeChanged FINAL)
    Q_PROPERTY(int endingSpeedRange READ endingSpeedRange WRITE setEndingSpeedRange NOTIFY endingSpeedRangeChanged FINAL)
    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged FINAL)
    Q_PROPERTY(int endingRPMRange READ endingRPMRange WRITE setEndingRPMRange NOTIFY endingRPMRangeChanged FINAL)
    Q_PROPERTY(int startingRPMRange READ startingRPMRange WRITE setStartingRPMRange NOTIFY startingRPMRangeChanged FINAL)
    Q_PROPERTY(int FuelRange READ FuelRange WRITE setFuelRange NOTIFY FuelRangeChanged FINAL)
    Q_PROPERTY(int engineTemperatureRange READ engineTemperatureRange WRITE setEngineTemperatureRange NOTIFY engineTemperatureChangedRange FINAL)
    Q_PROPERTY(int engineTemperature READ engineTemperature WRITE setEngineTemperature NOTIFY engineTemperatureChanged FINAL)
    Q_PROPERTY(bool engineStarted READ engineStarted WRITE setEngineStarted NOTIFY engineStartedChanged FINAL)

public:
    explicit DBusServer(QObject *parent = nullptr);

    bool isOilCanWarning() const;
    bool isCarBatteryWarning() const;
    bool isCarPressureWarning() const;
    bool isCarChildSeatWarning() const;
    bool isCarTractionControlWarning() const;
    bool isSeatBeltWarning() const;
    bool isHighBeamOn() const;
    bool isAbsOn() const;
    bool isCarBrakeParkingOn() const;

    Q_INVOKABLE void onLoad();


    bool isLeftIndicatorOn() const;
    bool isRightIndicatorOn() const;


    int driveMode() const;

    // int rpmStartingRange() const;
    // void setRpmStartingRange(int newRpmStartingRange);

    // int rpmStopingRange() const;
    // void setRpmStopingRange(int newRpmStopingRange);

    int FuelRange() const;
    int speed() const;
    int startingSpeed() const;
    void setStartingSpeed(int newStartingSpeed);

    int startingRPM() const;
    void setStartingRPM(int newStartingRPM);
    int rpm() const;
    int engineTemperatureRange() const;
    int engineTemperature() const;


    bool engineStarted() const;


    int startingSpeedRange() const;


    int endingSpeedRange() const;



    int startingRPMRange() const;
    void setStartingRPMRange(int newStartingRPMRange);

    int endingRPMRange() const;
    void setEndingRPMRange(int newEndingRPMRange);

public slots:
    void setIsOilCanWarning(bool newIsOilCanWarning);
    void setIsCarBatteryWarning(bool newIsCarBatteryWarning);
    void setIsCarPressureWarning(bool newIsCarPressureWarning);
    void setIsCarChildSeatWarning(bool newIsCarChildSeatWarning);
    void setIsCarTractionControlWarning(bool newIsCarTractionControlWarning);
    void setIsSeatBeltWarning(bool newIsSeatBeltWarning);
    void setIsHighBeamOn(bool newIsHighBeamOn);
    void setIsAbsOn(bool newIsAbsOn);
    void setIsCarBrakeParkingOn(bool newIsCarBrakeParkingOn);
    void setIsRightIndicatorOn(bool newIsRightIndicatorOn);
    void setIsLeftIndicatorOn(bool newIsLeftIndicatorOn);
    void setDriveMode(int newDriveMode);
    void setRpmStartingAndEndingRange(int rpmStartingRange, int rpmStopingRange);
    void setFuelRange(int newFuelRange);
    void setSpeed(int newSpeed);
    void setRpm(int newRpm);
    void setEngineTemperatureRange(int newEngineTemperatureRange);
    void setEngineTemperature(int newEngineTemperature);
    void setEngineStarted(bool newEngineStarted);
    void setSpeedStartingAndEndingRange(int newStartingSpeedRange, int newEndingSpeedRange);
    void setEndingSpeedRange(int newEndingSpeedRange);
    void setStartingSpeedRange(int newStartingSpeedRange);
    void generateSpeed();
    void generateRPM();

signals:
    void isOilCanWarningChanged();
    void isCarBatteryWarningChanged();
    void isCarPressureWarningChanged();
    void isCarChildSeatWarningChanged();
    void isCarTractionControlWarningChanged();
    void isSeatBeltWarningChanged();
    void isHighBeamOnChanged();
    void isAbsOnChanged();
    void isCarBrakeParkingOnChanged();
    void isLeftIndicatorOnChanged();
    void isRightIndicatorOnChanged();
    void driveModeChanged();
    // void rpmStartingRangeChanged();
    // void rpmStopingRangeChanged();
    void FuelRangeChanged();
    void speedChanged();
    void startingSpeedChanged();
    void startingRPMChanged();
    void rpmChanged();
    void engineTemperatureChangedRange();
    void engineTemperatureChanged();

    void engineStartedChanged();

    void startingSpeedRangeChanged();

    void endingSpeedRangeChanged();

    void startingRPMRangeChanged();

    void endingRPMRangeChanged();

private:
    bool m_isOilCanWarning = false;
    bool m_isCarBatteryWarning;
    bool m_isCarPressureWarning;
    bool m_isCarChildSeatWarning;
    bool m_isCarTractionControlWarning;
    bool m_isSeatBeltWarning;
    bool m_isHighBeamOn;
    bool m_isAbsOn;
    bool m_isCarBrakeParkingOn;
    bool m_isLeftIndicatorOn = true;
    bool m_isRightIndicatorOn = true;
    int m_driveMode = 1; //Parking Mode
    // int m_rpmStartingRange = -40;
    // int m_rpmStopingRange = -40;
    int m_FuelRange = 30;
    int m_speed = -40;
    int m_startingSpeed = -40;
    int m_startingRPM = -40;
    int m_rpm = -40;
    int m_engineTemperatureRange = 0;
    int m_engineTemperature = 0;
    bool m_engineStarted = false;
    int m_startingSpeedRange = 0;
    int m_endingSpeedRange = 260;
    int m_startingRPMRange = 0;
    int m_endingRPMRange = 6;
    int previousSpeed = -1;
};

#endif // DBUSSERVER_H

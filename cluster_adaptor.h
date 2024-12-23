/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -m -a cluster_adaptor /home/sruthisathyan/Documents/AutomotiveCluster/myservice.xml
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd and other contributors.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CLUSTER_ADAPTOR_H
#define CLUSTER_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include <QtCore/qcontainerfwd.h>

/*
 * Adaptor class for interface experion.server.dbus
 */
class DbusAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "experion.server.dbus")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"experion.server.dbus\">\n"
"    <method name=\"setIsOilCanWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsOilCanWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsCarBatteryWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsCarBatteryWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsCarChildSeatWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsCarChildSeatWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsCarTractionControlWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsCarTractionControlWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsSeatBeltWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsSeatBeltWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsCarPressureWarning\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsCarPressureWarning\"/>\n"
"    </method>\n"
"    <method name=\"setIsHighBeamOn\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsHighBeamOn\"/>\n"
"    </method>\n"
"    <method name=\"setIsAbsOn\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsAbsOn\"/>\n"
"    </method>\n"
"    <method name=\"setIsCarBrakeParkingOn\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsCarBrakeParkingOn\"/>\n"
"    </method>\n"
"    <method name=\"setIsRightIndicatorOn\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsRightIndicatorOn\"/>\n"
"    </method>\n"
"    <method name=\"setIsLeftIndicatorOn\">\n"
"      <arg direction=\"in\" type=\"b\" name=\"newIsLeftIndicatorOn\"/>\n"
"    </method>\n"
"    <method name=\"setDriveMode\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"newDriveMode\"/>\n"
"    </method>\n"
"    <method name=\"setSpeedStartingAndEndingRange\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"speedStartingRange\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"speedEndingRange\"/>\n"
"    </method>\n"
"    <method name=\"setRpmStartingAndEndingRange\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"rpmStartingRange\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"rpmEndingRange\"/>\n"
"    </method>\n"
"    <method name=\"setFuelRange\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"fuelRange\"/>\n"
"    </method>\n"
"    <method name=\"setEngineTemperatureRange\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"tempRange\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    DbusAdaptor(QObject *parent);
    virtual ~DbusAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void setDriveMode(int newDriveMode);
    void setEngineTemperatureRange(int tempRange);
    void setFuelRange(int fuelRange);
    void setIsAbsOn(bool newIsAbsOn);
    void setIsCarBatteryWarning(bool newIsCarBatteryWarning);
    void setIsCarBrakeParkingOn(bool newIsCarBrakeParkingOn);
    void setIsCarChildSeatWarning(bool newIsCarChildSeatWarning);
    void setIsCarPressureWarning(bool newIsCarPressureWarning);
    void setIsCarTractionControlWarning(bool newIsCarTractionControlWarning);
    void setIsHighBeamOn(bool newIsHighBeamOn);
    void setIsLeftIndicatorOn(bool newIsLeftIndicatorOn);
    void setIsOilCanWarning(bool newIsOilCanWarning);
    void setIsRightIndicatorOn(bool newIsRightIndicatorOn);
    void setIsSeatBeltWarning(bool newIsSeatBeltWarning);
    void setRpmStartingAndEndingRange(int rpmStartingRange, int rpmEndingRange);
    void setSpeedStartingAndEndingRange(int speedStartingRange, int speedEndingRange);
Q_SIGNALS: // SIGNALS
};

#endif

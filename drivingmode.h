#ifndef DRIVINGMODE_H
#define DRIVINGMODE_H

#include <QtQml>

class DrivingMode
{
    QML_UNCREATABLE("Can't do this")
    Q_GADGET

public:
    DrivingMode();

    enum DrivingModeList {
        REVERSE,
        PARKING,
        DRIVE
    };

    Q_ENUM(DrivingModeList)
};

#endif // DRIVINGMODE_H

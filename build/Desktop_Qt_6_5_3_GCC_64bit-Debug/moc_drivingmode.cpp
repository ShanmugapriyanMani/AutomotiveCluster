/****************************************************************************
** Meta object code from reading C++ file 'drivingmode.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drivingmode.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drivingmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDrivingModeENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDrivingModeENDCLASS = QtMocHelpers::stringData(
    "DrivingMode",
    "QML.Creatable",
    "false",
    "QML.UncreatableReason",
    "Can't do this",
    "DrivingModeList",
    "REVERSE",
    "PARKING",
    "DRIVE"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDrivingModeENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[14];
    char stringdata2[6];
    char stringdata3[22];
    char stringdata4[14];
    char stringdata5[16];
    char stringdata6[8];
    char stringdata7[8];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDrivingModeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDrivingModeENDCLASS_t qt_meta_stringdata_CLASSDrivingModeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "DrivingMode"
        QT_MOC_LITERAL(12, 13),  // "QML.Creatable"
        QT_MOC_LITERAL(26, 5),  // "false"
        QT_MOC_LITERAL(32, 21),  // "QML.UncreatableReason"
        QT_MOC_LITERAL(54, 13),  // "Can't do this"
        QT_MOC_LITERAL(68, 15),  // "DrivingModeList"
        QT_MOC_LITERAL(84, 7),  // "REVERSE"
        QT_MOC_LITERAL(92, 7),  // "PARKING"
        QT_MOC_LITERAL(100, 5)   // "DRIVE"
    },
    "DrivingMode",
    "QML.Creatable",
    "false",
    "QML.UncreatableReason",
    "Can't do this",
    "DrivingModeList",
    "REVERSE",
    "PARKING",
    "DRIVE"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDrivingModeENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       2,   14, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   18, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // enums: name, alias, flags, count, data
       5,    5, 0x0,    3,   23,

 // enum data: key, value
       6, uint(DrivingMode::REVERSE),
       7, uint(DrivingMode::PARKING),
       8, uint(DrivingMode::DRIVE),

       0        // eod
};

Q_CONSTINIT const QMetaObject DrivingMode::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_CLASSDrivingModeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDrivingModeENDCLASS,
    nullptr,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        DrivingMode
    >,
    nullptr
} };

QT_WARNING_POP

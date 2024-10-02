/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../1/os1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "GETICONMETRICS"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "DRAGFULLWINDOWS"
QT_MOC_LITERAL(4, 43, 13), // "SETLANGTOGGLE"
QT_MOC_LITERAL(5, 57, 13), // "ACTIVECAPTION"
QT_MOC_LITERAL(6, 71, 8), // "MENUTEXT"
QT_MOC_LITERAL(7, 80, 7), // "BTNFACE"
QT_MOC_LITERAL(8, 88, 6), // "CARETS"
QT_MOC_LITERAL(9, 95, 14), // "GETMOUSETRAILS"
QT_MOC_LITERAL(10, 110, 11), // "GETWORKAREA"
QT_MOC_LITERAL(11, 122, 9), // "LOCALTIME"
QT_MOC_LITERAL(12, 132, 8), // "TIMEZONE"
QT_MOC_LITERAL(13, 141, 13), // "KEYBOARDSTATE"
QT_MOC_LITERAL(14, 155, 10), // "USERLANGID"
QT_MOC_LITERAL(15, 166, 16), // "SystemPowerState"
QT_MOC_LITERAL(16, 183, 10) // "SLocalTime"

    },
    "MainWindow\0GETICONMETRICS\0\0DRAGFULLWINDOWS\0"
    "SETLANGTOGGLE\0ACTIVECAPTION\0MENUTEXT\0"
    "BTNFACE\0CARETS\0GETMOUSETRAILS\0GETWORKAREA\0"
    "LOCALTIME\0TIMEZONE\0KEYBOARDSTATE\0"
    "USERLANGID\0SystemPowerState\0SLocalTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GETICONMETRICS(); break;
        case 1: _t->DRAGFULLWINDOWS(); break;
        case 2: _t->SETLANGTOGGLE(); break;
        case 3: _t->ACTIVECAPTION(); break;
        case 4: _t->MENUTEXT(); break;
        case 5: _t->BTNFACE(); break;
        case 6: _t->CARETS(); break;
        case 7: _t->GETMOUSETRAILS(); break;
        case 8: _t->GETWORKAREA(); break;
        case 9: _t->LOCALTIME(); break;
        case 10: _t->TIMEZONE(); break;
        case 11: _t->KEYBOARDSTATE(); break;
        case 12: _t->USERLANGID(); break;
        case 13: _t->SystemPowerState(); break;
        case 14: _t->SLocalTime(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

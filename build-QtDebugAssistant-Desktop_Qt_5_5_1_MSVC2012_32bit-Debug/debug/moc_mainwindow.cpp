/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serialAssistant1.2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_openSerial_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "on_clearCount_clicked"
QT_MOC_LITERAL(4, 56, 19), // "on_sendData_clicked"
QT_MOC_LITERAL(5, 76, 20), // "on_clearData_clicked"
QT_MOC_LITERAL(6, 97, 19), // "on_saveData_clicked"
QT_MOC_LITERAL(7, 117, 22), // "on_serialAdd_triggered"
QT_MOC_LITERAL(8, 140, 20), // "on_addBaud_triggered"
QT_MOC_LITERAL(9, 161, 18), // "on_about_triggered"
QT_MOC_LITERAL(10, 180, 24), // "on_label_9_linkActivated"
QT_MOC_LITERAL(11, 205, 4), // "link"
QT_MOC_LITERAL(12, 210, 28), // "on_changeMode_currentChanged"
QT_MOC_LITERAL(13, 239, 5), // "index"
QT_MOC_LITERAL(14, 245, 23), // "on_serverCreate_clicked"
QT_MOC_LITERAL(15, 269, 7), // "checked"
QT_MOC_LITERAL(16, 277, 23), // "on_clientCreate_clicked"
QT_MOC_LITERAL(17, 301, 14), // "disconnectHost"
QT_MOC_LITERAL(18, 316, 11), // "connectHost"
QT_MOC_LITERAL(19, 328, 12), // "updateMyData"
QT_MOC_LITERAL(20, 341, 9), // "newListen"
QT_MOC_LITERAL(21, 351, 17) // "acceptConnections"

    },
    "MainWindow\0on_openSerial_clicked\0\0"
    "on_clearCount_clicked\0on_sendData_clicked\0"
    "on_clearData_clicked\0on_saveData_clicked\0"
    "on_serialAdd_triggered\0on_addBaud_triggered\0"
    "on_about_triggered\0on_label_9_linkActivated\0"
    "link\0on_changeMode_currentChanged\0"
    "index\0on_serverCreate_clicked\0checked\0"
    "on_clientCreate_clicked\0disconnectHost\0"
    "connectHost\0updateMyData\0newListen\0"
    "acceptConnections"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    1,  107,    2, 0x08 /* Private */,
      12,    1,  110,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      16,    1,  116,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
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
        case 0: _t->on_openSerial_clicked(); break;
        case 1: _t->on_clearCount_clicked(); break;
        case 2: _t->on_sendData_clicked(); break;
        case 3: _t->on_clearData_clicked(); break;
        case 4: _t->on_saveData_clicked(); break;
        case 5: _t->on_serialAdd_triggered(); break;
        case 6: _t->on_addBaud_triggered(); break;
        case 7: _t->on_about_triggered(); break;
        case 8: _t->on_label_9_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_changeMode_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_serverCreate_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_clientCreate_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->disconnectHost(); break;
        case 13: _t->connectHost(); break;
        case 14: _t->updateMyData(); break;
        case 15: _t->newListen(); break;
        case 16: _t->acceptConnections(); break;
        default: ;
        }
    }
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

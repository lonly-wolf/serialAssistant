/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtImageAssistant/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_imageRotate_sliderMoved"
QT_MOC_LITERAL(4, 63, 8), // "position"
QT_MOC_LITERAL(5, 72, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 94, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 118, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(8, 150, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(9, 174, 20), // "on_penButton_clicked"
QT_MOC_LITERAL(10, 195, 23), // "on_grayAction_triggered"
QT_MOC_LITERAL(11, 219, 23), // "on_lightAdd15_triggered"
QT_MOC_LITERAL(12, 243, 23), // "on_lightAdd30_triggered"
QT_MOC_LITERAL(13, 267, 23), // "on_lightAdd45_triggered"
QT_MOC_LITERAL(14, 291, 23), // "on_lightAdd65_triggered"
QT_MOC_LITERAL(15, 315, 23), // "on_lightAdd85_triggered"
QT_MOC_LITERAL(16, 339, 24), // "on_lightAdd100_triggered"
QT_MOC_LITERAL(17, 364, 24), // "on_warmAction2_triggered"
QT_MOC_LITERAL(18, 389, 23), // "on_mohuAction_triggered"
QT_MOC_LITERAL(19, 413, 24) // "on_sharpAction_triggered"

    },
    "MainWindow\0on_actionOpen_triggered\0\0"
    "on_imageRotate_sliderMoved\0position\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_horizontalSlider_sliderMoved\0"
    "on_actionSave_triggered\0on_penButton_clicked\0"
    "on_grayAction_triggered\0on_lightAdd15_triggered\0"
    "on_lightAdd30_triggered\0on_lightAdd45_triggered\0"
    "on_lightAdd65_triggered\0on_lightAdd85_triggered\0"
    "on_lightAdd100_triggered\0"
    "on_warmAction2_triggered\0"
    "on_mohuAction_triggered\0"
    "on_sharpAction_triggered"
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
       3,    1,  100,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    1,  105,    2, 0x08 /* Private */,
       8,    0,  108,    2, 0x08 /* Private */,
       9,    0,  109,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    0,  111,    2, 0x08 /* Private */,
      12,    0,  112,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
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
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_imageRotate_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: _t->on_penButton_clicked(); break;
        case 7: _t->on_grayAction_triggered(); break;
        case 8: _t->on_lightAdd15_triggered(); break;
        case 9: _t->on_lightAdd30_triggered(); break;
        case 10: _t->on_lightAdd45_triggered(); break;
        case 11: _t->on_lightAdd65_triggered(); break;
        case 12: _t->on_lightAdd85_triggered(); break;
        case 13: _t->on_lightAdd100_triggered(); break;
        case 14: _t->on_warmAction2_triggered(); break;
        case 15: _t->on_mohuAction_triggered(); break;
        case 16: _t->on_sharpAction_triggered(); break;
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

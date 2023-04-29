/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SPATIAL_COORDINATION_Type2_Sb2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_doubleSpinBox_2_valueChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "arg1"
QT_MOC_LITERAL(4, 49, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 71, 28), // "on_tableWidget_2_cellChanged"
QT_MOC_LITERAL(6, 100, 3), // "row"
QT_MOC_LITERAL(7, 104, 6), // "column"
QT_MOC_LITERAL(8, 111, 26), // "on_tableWidget_cellChanged"
QT_MOC_LITERAL(9, 138, 26), // "on_checkBox_4_stateChanged"
QT_MOC_LITERAL(10, 165, 34), // "on_doubleSpinBox_2_editingFin..."
QT_MOC_LITERAL(11, 200, 31), // "on_doubleSpinBox_3_valueChanged"
QT_MOC_LITERAL(12, 232, 31), // "on_doubleSpinBox_4_valueChanged"
QT_MOC_LITERAL(13, 264, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(14, 289, 26), // "on_checkBox_5_stateChanged"
QT_MOC_LITERAL(15, 316, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(16, 343, 8) // "checkObj"

    },
    "MainWindow\0on_doubleSpinBox_2_valueChanged\0"
    "\0arg1\0on_pushButton_clicked\0"
    "on_tableWidget_2_cellChanged\0row\0"
    "column\0on_tableWidget_cellChanged\0"
    "on_checkBox_4_stateChanged\0"
    "on_doubleSpinBox_2_editingFinished\0"
    "on_doubleSpinBox_3_valueChanged\0"
    "on_doubleSpinBox_4_valueChanged\0"
    "on_checkBox_stateChanged\0"
    "on_checkBox_5_stateChanged\0"
    "on_checkBox_2_stateChanged\0checkObj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    2,   83,    2, 0x08 /* Private */,
       8,    2,   88,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
       1,    1,   96,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      14,    1,  109,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Bool,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_doubleSpinBox_2_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_tableWidget_2_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_tableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_checkBox_4_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_2_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_2_editingFinished(); break;
        case 7: _t->on_doubleSpinBox_3_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_doubleSpinBox_4_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_checkBox_5_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { bool _r = _t->checkObj();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

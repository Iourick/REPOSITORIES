/****************************************************************************
** Meta object code from reading C++ file 'mythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SOLVER_POSM_v9/mythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThread_t {
    QByteArrayData data[16];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThread_t qt_meta_stringdata_MyThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyThread"
QT_MOC_LITERAL(1, 9, 8), // "progress"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "numIter"
QT_MOC_LITERAL(4, 27, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 43, 12), // "vctNevSquare"
QT_MOC_LITERAL(6, 56, 7), // "vctMean"
QT_MOC_LITERAL(7, 64, 7), // "vctDisp"
QT_MOC_LITERAL(8, 72, 7), // "numpart"
QT_MOC_LITERAL(9, 80, 8), // "bEndPart"
QT_MOC_LITERAL(10, 89, 5), // "vctX0"
QT_MOC_LITERAL(11, 95, 12), // "calcfinished"
QT_MOC_LITERAL(12, 108, 6), // "result"
QT_MOC_LITERAL(13, 115, 13), // "kleaningEnded"
QT_MOC_LITERAL(14, 129, 12), // "QVector<int>"
QT_MOC_LITERAL(15, 142, 16) // "vctGoodZamersNum"

    },
    "MyThread\0progress\0\0numIter\0QVector<double>\0"
    "vctNevSquare\0vctMean\0vctDisp\0numpart\0"
    "bEndPart\0vctX0\0calcfinished\0result\0"
    "kleaningEnded\0QVector<int>\0vctGoodZamersNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   29,    2, 0x06 /* Public */,
      11,    1,   44,    2, 0x06 /* Public */,
      13,    4,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Bool, 0x80000000 | 4,    3,    5,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14, 0x80000000 | 4, 0x80000000 | 4,    8,   15,    6,    7,

       0        // eod
};

void MyThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyThread *_t = static_cast<MyThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QVector<double>(*)>(_a[7]))); break;
        case 1: _t->calcfinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->kleaningEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
            case 3:
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyThread::*)(int , QVector<double> , QVector<double> , QVector<double> , int , bool , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThread::progress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThread::calcfinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyThread::*)(int , QVector<int> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThread::kleaningEnded)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_MyThread.data,
    qt_meta_data_MyThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyThread::progress(int _t1, QVector<double> _t2, QVector<double> _t3, QVector<double> _t4, int _t5, bool _t6, QVector<double> _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyThread::calcfinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyThread::kleaningEnded(int _t1, QVector<int> _t2, QVector<double> _t3, QVector<double> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

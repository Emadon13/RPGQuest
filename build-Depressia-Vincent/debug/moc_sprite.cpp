/****************************************************************************
** Meta object code from reading C++ file 'sprite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Depressia/gui/sprite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sprite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sprite_t {
    QByteArrayData data[13];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sprite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sprite_t qt_meta_stringdata_Sprite = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Sprite"
QT_MOC_LITERAL(1, 7, 7), // "clicked"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "Sprite*"
QT_MOC_LITERAL(4, 24, 6), // "killed"
QT_MOC_LITERAL(5, 31, 4), // "kill"
QT_MOC_LITERAL(6, 36, 6), // "damage"
QT_MOC_LITERAL(7, 43, 6), // "attack"
QT_MOC_LITERAL(8, 50, 6), // "normal"
QT_MOC_LITERAL(9, 57, 9), // "nextFrame"
QT_MOC_LITERAL(10, 67, 15), // "nextAttackFrame"
QT_MOC_LITERAL(11, 83, 13), // "nextKillFrame"
QT_MOC_LITERAL(12, 97, 15) // "nextDamageFrame"

    },
    "Sprite\0clicked\0\0Sprite*\0killed\0kill\0"
    "damage\0attack\0normal\0nextFrame\0"
    "nextAttackFrame\0nextKillFrame\0"
    "nextDamageFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sprite[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
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

void Sprite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sprite *_t = static_cast<Sprite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 1: _t->killed((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 2: _t->kill(); break;
        case 3: _t->damage(); break;
        case 4: _t->attack(); break;
        case 5: _t->normal(); break;
        case 6: _t->nextFrame(); break;
        case 7: _t->nextAttackFrame(); break;
        case 8: _t->nextKillFrame(); break;
        case 9: _t->nextDamageFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sprite* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sprite* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sprite::*)(Sprite * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Sprite::*)(Sprite * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sprite::killed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sprite::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sprite.data,
      qt_meta_data_Sprite,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sprite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sprite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sprite.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Sprite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Sprite::clicked(Sprite * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Sprite::killed(Sprite * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

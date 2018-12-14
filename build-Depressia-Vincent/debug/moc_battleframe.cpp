/****************************************************************************
** Meta object code from reading C++ file 'battleframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Depressia/gui/frame/battleframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battleframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BattleFrame_t {
    QByteArrayData data[23];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BattleFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BattleFrame_t qt_meta_stringdata_BattleFrame = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BattleFrame"
QT_MOC_LITERAL(1, 12, 10), // "killEntity"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "Sprite*"
QT_MOC_LITERAL(4, 32, 6), // "sprite"
QT_MOC_LITERAL(5, 39, 12), // "damageEntity"
QT_MOC_LITERAL(6, 52, 12), // "deleteEntity"
QT_MOC_LITERAL(7, 65, 12), // "attackEntity"
QT_MOC_LITERAL(8, 78, 11), // "skillEntity"
QT_MOC_LITERAL(9, 90, 8), // "nextTurn"
QT_MOC_LITERAL(10, 99, 19), // "updateCurrentPlayer"
QT_MOC_LITERAL(11, 119, 14), // "updateTurnInfo"
QT_MOC_LITERAL(12, 134, 13), // "showSelection"
QT_MOC_LITERAL(13, 148, 8), // "playTurn"
QT_MOC_LITERAL(14, 157, 8), // "updateUI"
QT_MOC_LITERAL(15, 166, 9), // "callSkill"
QT_MOC_LITERAL(16, 176, 10), // "playDamage"
QT_MOC_LITERAL(17, 187, 10), // "callAttack"
QT_MOC_LITERAL(18, 198, 11), // "choixEntity"
QT_MOC_LITERAL(19, 210, 1), // "i"
QT_MOC_LITERAL(20, 212, 10), // "choixSkill"
QT_MOC_LITERAL(21, 223, 9), // "showObjet"
QT_MOC_LITERAL(22, 233, 9) // "showSkill"

    },
    "BattleFrame\0killEntity\0\0Sprite*\0sprite\0"
    "damageEntity\0deleteEntity\0attackEntity\0"
    "skillEntity\0nextTurn\0updateCurrentPlayer\0"
    "updateTurnInfo\0showSelection\0playTurn\0"
    "updateUI\0callSkill\0playDamage\0callAttack\0"
    "choixEntity\0i\0choixSkill\0showObjet\0"
    "showSkill"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x0a /* Public */,
       5,    1,  107,    2, 0x0a /* Public */,
       6,    1,  110,    2, 0x0a /* Public */,
       7,    1,  113,    2, 0x0a /* Public */,
       8,    1,  116,    2, 0x0a /* Public */,
       9,    0,  119,    2, 0x0a /* Public */,
      10,    0,  120,    2, 0x0a /* Public */,
      11,    0,  121,    2, 0x0a /* Public */,
      12,    0,  122,    2, 0x0a /* Public */,
      13,    0,  123,    2, 0x0a /* Public */,
      14,    0,  124,    2, 0x0a /* Public */,
      15,    0,  125,    2, 0x0a /* Public */,
      16,    0,  126,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x0a /* Public */,
      18,    1,  128,    2, 0x0a /* Public */,
      20,    1,  131,    2, 0x0a /* Public */,
      21,    0,  134,    2, 0x0a /* Public */,
      22,    0,  135,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BattleFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BattleFrame *_t = static_cast<BattleFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->killEntity((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 1: _t->damageEntity((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 2: _t->deleteEntity((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 3: _t->attackEntity((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 4: _t->skillEntity((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 5: _t->nextTurn(); break;
        case 6: _t->updateCurrentPlayer(); break;
        case 7: _t->updateTurnInfo(); break;
        case 8: _t->showSelection(); break;
        case 9: _t->playTurn(); break;
        case 10: _t->updateUI(); break;
        case 11: _t->callSkill(); break;
        case 12: _t->playDamage(); break;
        case 13: _t->callAttack(); break;
        case 14: _t->choixEntity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->choixSkill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->showObjet(); break;
        case 17: _t->showSkill(); break;
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
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sprite* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sprite* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Sprite* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BattleFrame::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BattleFrame.data,
      qt_meta_data_BattleFrame,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BattleFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BattleFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BattleFrame.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BattleFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

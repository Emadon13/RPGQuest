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
    QByteArrayData data[24];
    char stringdata0[260];
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
QT_MOC_LITERAL(3, 24, 7), // "Entity*"
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
QT_MOC_LITERAL(17, 187, 16), // "setCorrectSprite"
QT_MOC_LITERAL(18, 204, 10), // "callAttack"
QT_MOC_LITERAL(19, 215, 11), // "choixEntity"
QT_MOC_LITERAL(20, 227, 1), // "i"
QT_MOC_LITERAL(21, 229, 10), // "choixSkill"
QT_MOC_LITERAL(22, 240, 9), // "showObjet"
QT_MOC_LITERAL(23, 250, 9) // "showSkill"

    },
    "BattleFrame\0killEntity\0\0Entity*\0sprite\0"
    "damageEntity\0deleteEntity\0attackEntity\0"
    "skillEntity\0nextTurn\0updateCurrentPlayer\0"
    "updateTurnInfo\0showSelection\0playTurn\0"
    "updateUI\0callSkill\0playDamage\0"
    "setCorrectSprite\0callAttack\0choixEntity\0"
    "i\0choixSkill\0showObjet\0showSkill"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x0a /* Public */,
       5,    1,  112,    2, 0x0a /* Public */,
       6,    1,  115,    2, 0x0a /* Public */,
       7,    1,  118,    2, 0x0a /* Public */,
       8,    1,  121,    2, 0x0a /* Public */,
       9,    0,  124,    2, 0x0a /* Public */,
      10,    0,  125,    2, 0x0a /* Public */,
      11,    0,  126,    2, 0x0a /* Public */,
      12,    0,  127,    2, 0x0a /* Public */,
      13,    0,  128,    2, 0x0a /* Public */,
      14,    0,  129,    2, 0x0a /* Public */,
      15,    0,  130,    2, 0x0a /* Public */,
      16,    0,  131,    2, 0x0a /* Public */,
      17,    0,  132,    2, 0x0a /* Public */,
      18,    0,  133,    2, 0x0a /* Public */,
      19,    1,  134,    2, 0x0a /* Public */,
      21,    1,  137,    2, 0x0a /* Public */,
      22,    0,  140,    2, 0x0a /* Public */,
      23,    0,  141,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
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
        case 0: _t->killEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: _t->damageEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 2: _t->deleteEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 3: _t->attackEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 4: _t->skillEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 5: _t->nextTurn(); break;
        case 6: _t->updateCurrentPlayer(); break;
        case 7: _t->updateTurnInfo(); break;
        case 8: _t->showSelection(); break;
        case 9: _t->playTurn(); break;
        case 10: _t->updateUI(); break;
        case 11: _t->callSkill(); break;
        case 12: _t->playDamage(); break;
        case 13: _t->setCorrectSprite(); break;
        case 14: _t->callAttack(); break;
        case 15: _t->choixEntity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->choixSkill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->showObjet(); break;
        case 18: _t->showSkill(); break;
        default: ;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

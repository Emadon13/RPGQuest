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
    QByteArrayData data[34];
    char stringdata0[390];
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
QT_MOC_LITERAL(6, 52, 1), // "i"
QT_MOC_LITERAL(7, 54, 12), // "effectEntity"
QT_MOC_LITERAL(8, 67, 12), // "deleteEntity"
QT_MOC_LITERAL(9, 80, 12), // "attackEntity"
QT_MOC_LITERAL(10, 93, 11), // "skillEntity"
QT_MOC_LITERAL(11, 105, 8), // "nextTurn"
QT_MOC_LITERAL(12, 114, 19), // "updateCurrentPlayer"
QT_MOC_LITERAL(13, 134, 14), // "updateTurnInfo"
QT_MOC_LITERAL(14, 149, 13), // "showSelection"
QT_MOC_LITERAL(15, 163, 8), // "playTurn"
QT_MOC_LITERAL(16, 172, 14), // "playTurnObject"
QT_MOC_LITERAL(17, 187, 7), // "summary"
QT_MOC_LITERAL(18, 195, 8), // "updateUI"
QT_MOC_LITERAL(19, 204, 9), // "callSkill"
QT_MOC_LITERAL(20, 214, 10), // "playDamage"
QT_MOC_LITERAL(21, 225, 15), // "playSkillEffect"
QT_MOC_LITERAL(22, 241, 18), // "resetCurrentSprite"
QT_MOC_LITERAL(23, 260, 16), // "resetHitedSprite"
QT_MOC_LITERAL(24, 277, 10), // "hideSprite"
QT_MOC_LITERAL(25, 288, 10), // "stopEffect"
QT_MOC_LITERAL(26, 299, 8), // "useObjet"
QT_MOC_LITERAL(27, 308, 10), // "callAttack"
QT_MOC_LITERAL(28, 319, 11), // "choixEntity"
QT_MOC_LITERAL(29, 331, 16), // "choixEntityObjet"
QT_MOC_LITERAL(30, 348, 10), // "choixSkill"
QT_MOC_LITERAL(31, 359, 10), // "choixObjet"
QT_MOC_LITERAL(32, 370, 9), // "showObjet"
QT_MOC_LITERAL(33, 380, 9) // "showSkill"

    },
    "BattleFrame\0killEntity\0\0Entity*\0sprite\0"
    "damageEntity\0i\0effectEntity\0deleteEntity\0"
    "attackEntity\0skillEntity\0nextTurn\0"
    "updateCurrentPlayer\0updateTurnInfo\0"
    "showSelection\0playTurn\0playTurnObject\0"
    "summary\0updateUI\0callSkill\0playDamage\0"
    "playSkillEffect\0resetCurrentSprite\0"
    "resetHitedSprite\0hideSprite\0stopEffect\0"
    "useObjet\0callAttack\0choixEntity\0"
    "choixEntityObjet\0choixSkill\0choixObjet\0"
    "showObjet\0showSkill"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x0a /* Public */,
       5,    2,  157,    2, 0x0a /* Public */,
       7,    2,  162,    2, 0x0a /* Public */,
       8,    1,  167,    2, 0x0a /* Public */,
       9,    1,  170,    2, 0x0a /* Public */,
      10,    1,  173,    2, 0x0a /* Public */,
      11,    0,  176,    2, 0x0a /* Public */,
      12,    0,  177,    2, 0x0a /* Public */,
      13,    0,  178,    2, 0x0a /* Public */,
      14,    0,  179,    2, 0x0a /* Public */,
      15,    0,  180,    2, 0x0a /* Public */,
      16,    1,  181,    2, 0x0a /* Public */,
      18,    0,  184,    2, 0x0a /* Public */,
      19,    0,  185,    2, 0x0a /* Public */,
      20,    0,  186,    2, 0x0a /* Public */,
      21,    0,  187,    2, 0x0a /* Public */,
      22,    0,  188,    2, 0x0a /* Public */,
      23,    1,  189,    2, 0x0a /* Public */,
      24,    1,  192,    2, 0x0a /* Public */,
      25,    1,  195,    2, 0x0a /* Public */,
      26,    0,  198,    2, 0x0a /* Public */,
      27,    0,  199,    2, 0x0a /* Public */,
      28,    1,  200,    2, 0x0a /* Public */,
      29,    1,  203,    2, 0x0a /* Public */,
      30,    1,  206,    2, 0x0a /* Public */,
      31,    1,  209,    2, 0x0a /* Public */,
      32,    0,  212,    2, 0x0a /* Public */,
      33,    0,  213,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::ULongLong,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::ULongLong,    4,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
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
        case 1: _t->damageEntity((*reinterpret_cast< Entity*(*)>(_a[1])),(*reinterpret_cast< unsigned long long(*)>(_a[2]))); break;
        case 2: _t->effectEntity((*reinterpret_cast< Entity*(*)>(_a[1])),(*reinterpret_cast< unsigned long long(*)>(_a[2]))); break;
        case 3: _t->deleteEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 4: _t->attackEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 5: _t->skillEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 6: _t->nextTurn(); break;
        case 7: _t->updateCurrentPlayer(); break;
        case 8: _t->updateTurnInfo(); break;
        case 9: _t->showSelection(); break;
        case 10: _t->playTurn(); break;
        case 11: _t->playTurnObject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateUI(); break;
        case 13: _t->callSkill(); break;
        case 14: _t->playDamage(); break;
        case 15: _t->playSkillEffect(); break;
        case 16: _t->resetCurrentSprite(); break;
        case 17: _t->resetHitedSprite((*reinterpret_cast< unsigned long long(*)>(_a[1]))); break;
        case 18: _t->hideSprite((*reinterpret_cast< unsigned long long(*)>(_a[1]))); break;
        case 19: _t->stopEffect((*reinterpret_cast< unsigned long long(*)>(_a[1]))); break;
        case 20: _t->useObjet(); break;
        case 21: _t->callAttack(); break;
        case 22: _t->choixEntity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->choixEntityObjet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->choixSkill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->choixObjet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->showObjet(); break;
        case 27: _t->showSkill(); break;
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
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

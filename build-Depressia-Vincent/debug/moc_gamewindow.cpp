/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Depressia/gui/window/gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWindow_t {
    QByteArrayData data[18];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWindow_t qt_meta_stringdata_GameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWindow"
QT_MOC_LITERAL(1, 11, 9), // "ShowFrame"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "CreateBattleFrame"
QT_MOC_LITERAL(4, 40, 15), // "CreateGameFrame"
QT_MOC_LITERAL(5, 56, 17), // "CreateDialogFrame"
QT_MOC_LITERAL(6, 74, 16), // "CreateVideoFrame"
QT_MOC_LITERAL(7, 91, 16), // "CreateFinalFrame"
QT_MOC_LITERAL(8, 108, 19), // "CreateGameOverFrame"
QT_MOC_LITERAL(9, 128, 15), // "CreateItemFrame"
QT_MOC_LITERAL(10, 144, 4), // "GoUp"
QT_MOC_LITERAL(11, 149, 6), // "GoDown"
QT_MOC_LITERAL(12, 156, 7), // "GoRight"
QT_MOC_LITERAL(13, 164, 6), // "GoLeft"
QT_MOC_LITERAL(14, 171, 11), // "afficheItem"
QT_MOC_LITERAL(15, 183, 16), // "afficheParametre"
QT_MOC_LITERAL(16, 200, 10), // "resetFocus"
QT_MOC_LITERAL(17, 211, 21) // "setPositionAfterLoose"

    },
    "GameWindow\0ShowFrame\0\0CreateBattleFrame\0"
    "CreateGameFrame\0CreateDialogFrame\0"
    "CreateVideoFrame\0CreateFinalFrame\0"
    "CreateGameOverFrame\0CreateItemFrame\0"
    "GoUp\0GoDown\0GoRight\0GoLeft\0afficheItem\0"
    "afficheParametre\0resetFocus\0"
    "setPositionAfterLoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWindow *_t = static_cast<GameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowFrame(); break;
        case 1: _t->CreateBattleFrame(); break;
        case 2: _t->CreateGameFrame(); break;
        case 3: _t->CreateDialogFrame(); break;
        case 4: _t->CreateVideoFrame(); break;
        case 5: _t->CreateFinalFrame(); break;
        case 6: _t->CreateGameOverFrame(); break;
        case 7: _t->CreateItemFrame(); break;
        case 8: _t->GoUp(); break;
        case 9: _t->GoDown(); break;
        case 10: _t->GoRight(); break;
        case 11: _t->GoLeft(); break;
        case 12: _t->afficheItem(); break;
        case 13: _t->afficheParametre(); break;
        case 14: _t->resetFocus(); break;
        case 15: _t->setPositionAfterLoose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GameWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameWindow.data,
      qt_meta_data_GameWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

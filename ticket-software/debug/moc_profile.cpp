/****************************************************************************
** Meta object code from reading C++ file 'profile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../profile.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Profile_t {
    const uint offsetsAndSize[30];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Profile_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Profile_t qt_meta_stringdata_Profile = {
    {
QT_MOC_LITERAL(0, 7), // "Profile"
QT_MOC_LITERAL(8, 22), // "on_EditDetails_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 7), // "checked"
QT_MOC_LITERAL(40, 25), // "on_changePassword_clicked"
QT_MOC_LITERAL(66, 25), // "on_EditProfilePic_clicked"
QT_MOC_LITERAL(92, 21), // "on_ProfileOp1_clicked"
QT_MOC_LITERAL(114, 21), // "on_ProfileOp2_clicked"
QT_MOC_LITERAL(136, 21), // "on_ProfileOp3_clicked"
QT_MOC_LITERAL(158, 21), // "on_ProfileOp4_clicked"
QT_MOC_LITERAL(180, 21), // "on_ProfileOp5_clicked"
QT_MOC_LITERAL(202, 21), // "on_ProfileOp6_clicked"
QT_MOC_LITERAL(224, 21), // "on_ProfileOp7_clicked"
QT_MOC_LITERAL(246, 21), // "on_ProfileOp8_clicked"
QT_MOC_LITERAL(268, 21) // "on_ProfileOp9_clicked"

    },
    "Profile\0on_EditDetails_clicked\0\0checked\0"
    "on_changePassword_clicked\0"
    "on_EditProfilePic_clicked\0"
    "on_ProfileOp1_clicked\0on_ProfileOp2_clicked\0"
    "on_ProfileOp3_clicked\0on_ProfileOp4_clicked\0"
    "on_ProfileOp5_clicked\0on_ProfileOp6_clicked\0"
    "on_ProfileOp7_clicked\0on_ProfileOp8_clicked\0"
    "on_ProfileOp9_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Profile[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       4,    0,   89,    2, 0x08,    3 /* Private */,
       5,    1,   90,    2, 0x08,    4 /* Private */,
       6,    0,   93,    2, 0x08,    6 /* Private */,
       7,    0,   94,    2, 0x08,    7 /* Private */,
       8,    0,   95,    2, 0x08,    8 /* Private */,
       9,    0,   96,    2, 0x08,    9 /* Private */,
      10,    0,   97,    2, 0x08,   10 /* Private */,
      11,    0,   98,    2, 0x08,   11 /* Private */,
      12,    0,   99,    2, 0x08,   12 /* Private */,
      13,    0,  100,    2, 0x08,   13 /* Private */,
      14,    0,  101,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
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

void Profile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Profile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_EditDetails_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_changePassword_clicked(); break;
        case 2: _t->on_EditProfilePic_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_ProfileOp1_clicked(); break;
        case 4: _t->on_ProfileOp2_clicked(); break;
        case 5: _t->on_ProfileOp3_clicked(); break;
        case 6: _t->on_ProfileOp4_clicked(); break;
        case 7: _t->on_ProfileOp5_clicked(); break;
        case 8: _t->on_ProfileOp6_clicked(); break;
        case 9: _t->on_ProfileOp7_clicked(); break;
        case 10: _t->on_ProfileOp8_clicked(); break;
        case 11: _t->on_ProfileOp9_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Profile::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Profile.offsetsAndSize,
    qt_meta_data_Profile,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Profile_t
, QtPrivate::TypeAndForceComplete<Profile, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Profile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Profile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Profile.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Profile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

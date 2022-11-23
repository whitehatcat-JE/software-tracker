/****************************************************************************
** Meta object code from reading C++ file 'assignments.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ticket-software/assignments.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assignments.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Assignments_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[24];
    char stringdata5[26];
    char stringdata6[24];
    char stringdata7[28];
    char stringdata8[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Assignments_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Assignments_t qt_meta_stringdata_Assignments = {
    {
        QT_MOC_LITERAL(0, 11),  // "Assignments"
        QT_MOC_LITERAL(12, 24),  // "on_ticketsButton_toggled"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 7),  // "checked"
        QT_MOC_LITERAL(46, 23),  // "on_groupsButton_toggled"
        QT_MOC_LITERAL(70, 25),  // "on_projectsButton_toggled"
        QT_MOC_LITERAL(96, 23),  // "on_logoutButton_clicked"
        QT_MOC_LITERAL(120, 27),  // "on_managementButton_clicked"
        QT_MOC_LITERAL(148, 24)   // "on_profileButton_clicked"
    },
    "Assignments",
    "on_ticketsButton_toggled",
    "",
    "checked",
    "on_groupsButton_toggled",
    "on_projectsButton_toggled",
    "on_logoutButton_clicked",
    "on_managementButton_clicked",
    "on_profileButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Assignments[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       4,    1,   53,    2, 0x08,    3 /* Private */,
       5,    1,   56,    2, 0x08,    5 /* Private */,
       6,    0,   59,    2, 0x08,    7 /* Private */,
       7,    0,   60,    2, 0x08,    8 /* Private */,
       8,    0,   61,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Assignments::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Assignments.offsetsAndSizes,
    qt_meta_data_Assignments,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Assignments_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Assignments, std::true_type>,
        // method 'on_ticketsButton_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_groupsButton_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_projectsButton_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_logoutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_managementButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_profileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Assignments::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Assignments *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ticketsButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->on_groupsButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_projectsButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_logoutButton_clicked(); break;
        case 4: _t->on_managementButton_clicked(); break;
        case 5: _t->on_profileButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Assignments::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assignments::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Assignments.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Assignments::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

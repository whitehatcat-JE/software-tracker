/****************************************************************************
** Meta object code from reading C++ file 'projectmanagement.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../Music/ticket-software/projectmanagement.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projectmanagement.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ProjectManagement_t {
    uint offsetsAndSizes[14];
    char stringdata0[18];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[24];
    char stringdata5[28];
    char stringdata6[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ProjectManagement_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ProjectManagement_t qt_meta_stringdata_ProjectManagement = {
    {
        QT_MOC_LITERAL(0, 17),  // "ProjectManagement"
        QT_MOC_LITERAL(18, 30),  // "on_createProjectButton_clicked"
        QT_MOC_LITERAL(49, 0),  // ""
        QT_MOC_LITERAL(50, 24),  // "on_profileButton_clicked"
        QT_MOC_LITERAL(75, 23),  // "on_assignButton_clicked"
        QT_MOC_LITERAL(99, 27),  // "on_managementButton_clicked"
        QT_MOC_LITERAL(127, 23)   // "on_logoutButton_clicked"
    },
    "ProjectManagement",
    "on_createProjectButton_clicked",
    "",
    "on_profileButton_clicked",
    "on_assignButton_clicked",
    "on_managementButton_clicked",
    "on_logoutButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ProjectManagement[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ProjectManagement::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProjectManagement.offsetsAndSizes,
    qt_meta_data_ProjectManagement,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ProjectManagement_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ProjectManagement, std::true_type>,
        // method 'on_createProjectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_profileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_assignButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_managementButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_logoutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ProjectManagement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProjectManagement *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_createProjectButton_clicked(); break;
        case 1: _t->on_profileButton_clicked(); break;
        case 2: _t->on_assignButton_clicked(); break;
        case 3: _t->on_managementButton_clicked(); break;
        case 4: _t->on_logoutButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ProjectManagement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProjectManagement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProjectManagement.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProjectManagement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

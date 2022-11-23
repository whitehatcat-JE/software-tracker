/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ticket-software/project.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Project_t {
    uint offsetsAndSizes[26];
    char stringdata0[8];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[25];
    char stringdata5[8];
    char stringdata6[27];
    char stringdata7[24];
    char stringdata8[25];
    char stringdata9[28];
    char stringdata10[24];
    char stringdata11[30];
    char stringdata12[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Project_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Project_t qt_meta_stringdata_Project = {
    {
        QT_MOC_LITERAL(0, 7),  // "Project"
        QT_MOC_LITERAL(8, 31),  // "on_lineEditPassword_textChanged"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 5),  // "query"
        QT_MOC_LITERAL(47, 24),  // "on_detailsButton_toggled"
        QT_MOC_LITERAL(72, 7),  // "checked"
        QT_MOC_LITERAL(80, 26),  // "on_detailsButton_2_toggled"
        QT_MOC_LITERAL(107, 23),  // "on_assignButton_clicked"
        QT_MOC_LITERAL(131, 24),  // "on_profileButton_clicked"
        QT_MOC_LITERAL(156, 27),  // "on_managementButton_clicked"
        QT_MOC_LITERAL(184, 23),  // "on_logoutButton_clicked"
        QT_MOC_LITERAL(208, 29),  // "on_createTicketButton_clicked"
        QT_MOC_LITERAL(238, 24)   // "on_archiveButton_clicked"
    },
    "Project",
    "on_lineEditPassword_textChanged",
    "",
    "query",
    "on_detailsButton_toggled",
    "checked",
    "on_detailsButton_2_toggled",
    "on_assignButton_clicked",
    "on_profileButton_clicked",
    "on_managementButton_clicked",
    "on_logoutButton_clicked",
    "on_createTicketButton_clicked",
    "on_archiveButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Project[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       4,    1,   71,    2, 0x08,    3 /* Private */,
       6,    1,   74,    2, 0x08,    5 /* Private */,
       7,    0,   77,    2, 0x08,    7 /* Private */,
       8,    0,   78,    2, 0x08,    8 /* Private */,
       9,    0,   79,    2, 0x08,    9 /* Private */,
      10,    0,   80,    2, 0x08,   10 /* Private */,
      11,    0,   81,    2, 0x08,   11 /* Private */,
      12,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Project::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Project.offsetsAndSizes,
    qt_meta_data_Project,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Project_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Project, std::true_type>,
        // method 'on_lineEditPassword_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_detailsButton_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_detailsButton_2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_assignButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_profileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_managementButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_logoutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_createTicketButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_archiveButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Project::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Project *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_lineEditPassword_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_detailsButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_detailsButton_2_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_assignButton_clicked(); break;
        case 4: _t->on_profileButton_clicked(); break;
        case 5: _t->on_managementButton_clicked(); break;
        case 6: _t->on_logoutButton_clicked(); break;
        case 7: _t->on_createTicketButton_clicked(); break;
        case 8: _t->on_archiveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Project::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Project.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

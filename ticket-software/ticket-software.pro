QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SHA256.cpp \
    addticket.cpp \
    archive.cpp \
    assignments.cpp \
    filemanager.cpp \
    groupmanagement.cpp \
    main.cpp \
    login.cpp \
    management.cpp \
    managementselection.cpp \
    navbar.cpp \
    profile.cpp \
    project.cpp \
    projectmanagement.cpp \
    ticket.cpp \
    usermanagement.cpp

HEADERS += \
    SHA256.h \
    addticket.h \
    archive.h \
    assignments.h \
    filemanager.h \
    groupmanagement.h \
    login.h \
    management.h \
    managementselection.h \
    navbar.h \
    profile.h \
    project.h \
    projectmanagement.h \
    ticket.h \
    usermanagement.h

FORMS += \
    addticket.ui \
    archive.ui \
    assignments.ui \
    groupmanagement.ui \
    login.ui \
    management.ui \
    managementselection.ui \
    navbar.ui \
    profile.ui \
    project.ui \
    projectmanagement.ui \
    ticket.ui \
    usermanagement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

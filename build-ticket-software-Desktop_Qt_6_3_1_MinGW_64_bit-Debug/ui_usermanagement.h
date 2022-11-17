/********************************************************************************
** Form generated from reading UI file 'usermanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENT_H
#define UI_USERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManagement
{
public:

    void setupUi(QWidget *UserManagement)
    {
        if (UserManagement->objectName().isEmpty())
            UserManagement->setObjectName(QString::fromUtf8("UserManagement"));
        UserManagement->resize(400, 300);

        retranslateUi(UserManagement);

        QMetaObject::connectSlotsByName(UserManagement);
    } // setupUi

    void retranslateUi(QWidget *UserManagement)
    {
        UserManagement->setWindowTitle(QCoreApplication::translate("UserManagement", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManagement: public Ui_UserManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENT_H

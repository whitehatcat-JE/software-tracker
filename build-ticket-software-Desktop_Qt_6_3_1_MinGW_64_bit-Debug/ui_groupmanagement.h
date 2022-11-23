/********************************************************************************
** Form generated from reading UI file 'groupmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMANAGEMENT_H
#define UI_GROUPMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupManagement
{
public:

    void setupUi(QWidget *GroupManagement)
    {
        if (GroupManagement->objectName().isEmpty())
            GroupManagement->setObjectName(QString::fromUtf8("GroupManagement"));
        GroupManagement->resize(400, 300);

        retranslateUi(GroupManagement);

        QMetaObject::connectSlotsByName(GroupManagement);
    } // setupUi

    void retranslateUi(QWidget *GroupManagement)
    {
        GroupManagement->setWindowTitle(QCoreApplication::translate("GroupManagement", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupManagement: public Ui_GroupManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMANAGEMENT_H

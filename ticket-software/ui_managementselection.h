/********************************************************************************
** Form generated from reading UI file 'managementselection.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTSELECTION_H
#define UI_MANAGEMENTSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagementSelection
{
public:

    void setupUi(QWidget *ManagementSelection)
    {
        if (ManagementSelection->objectName().isEmpty())
            ManagementSelection->setObjectName(QString::fromUtf8("ManagementSelection"));
        ManagementSelection->resize(400, 300);

        retranslateUi(ManagementSelection);

        QMetaObject::connectSlotsByName(ManagementSelection);
    } // setupUi

    void retranslateUi(QWidget *ManagementSelection)
    {
        ManagementSelection->setWindowTitle(QCoreApplication::translate("ManagementSelection", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagementSelection: public Ui_ManagementSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTSELECTION_H

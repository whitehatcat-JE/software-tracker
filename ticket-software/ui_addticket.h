/********************************************************************************
** Form generated from reading UI file 'addticket.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTICKET_H
#define UI_ADDTICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTicket
{
public:

    void setupUi(QWidget *AddTicket)
    {
        if (AddTicket->objectName().isEmpty())
            AddTicket->setObjectName(QString::fromUtf8("AddTicket"));
        AddTicket->resize(400, 300);

        retranslateUi(AddTicket);

        QMetaObject::connectSlotsByName(AddTicket);
    } // setupUi

    void retranslateUi(QWidget *AddTicket)
    {
        AddTicket->setWindowTitle(QCoreApplication::translate("AddTicket", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTicket: public Ui_AddTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTICKET_H

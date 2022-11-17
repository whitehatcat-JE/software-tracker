/********************************************************************************
** Form generated from reading UI file 'assignments.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENTS_H
#define UI_ASSIGNMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignments
{
public:

    void setupUi(QWidget *Assignments)
    {
        if (Assignments->objectName().isEmpty())
            Assignments->setObjectName(QString::fromUtf8("Assignments"));
        Assignments->resize(400, 300);

        retranslateUi(Assignments);

        QMetaObject::connectSlotsByName(Assignments);
    } // setupUi

    void retranslateUi(QWidget *Assignments)
    {
        Assignments->setWindowTitle(QCoreApplication::translate("Assignments", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignments: public Ui_Assignments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENTS_H

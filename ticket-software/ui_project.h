/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Project
{
public:

    void setupUi(QWidget *Project)
    {
        if (Project->objectName().isEmpty())
            Project->setObjectName(QString::fromUtf8("Project"));
        Project->resize(400, 300);

        retranslateUi(Project);

        QMetaObject::connectSlotsByName(Project);
    } // setupUi

    void retranslateUi(QWidget *Project)
    {
        Project->setWindowTitle(QCoreApplication::translate("Project", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Project: public Ui_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H

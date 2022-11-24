/********************************************************************************
** Form generated from reading UI file 'projectmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTMANAGEMENT_H
#define UI_PROJECTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectManagement
{
public:
    QPushButton *backgroundGradient;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *NavButton_4;
    QPushButton *profileButton;
    QFrame *line_4;
    QVBoxLayout *NavButton_15;
    QPushButton *assignButton;
    QFrame *line_16;
    QVBoxLayout *NavButton_16;
    QPushButton *managementButton;
    QFrame *line_17;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *NavButton_17;
    QPushButton *logoutButton;
    QFrame *line_18;
    QFrame *navBackground;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *pageFrame_2;
    QLabel *title_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *newProjectName;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *createProjectButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *ProjectManagement)
    {
        if (ProjectManagement->objectName().isEmpty())
            ProjectManagement->setObjectName("ProjectManagement");
        ProjectManagement->resize(1300, 800);
        ProjectManagement->setMinimumSize(QSize(1300, 800));
        ProjectManagement->setMaximumSize(QSize(1300, 800));
        backgroundGradient = new QPushButton(ProjectManagement);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-30, 0, 1341, 831));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(ProjectManagement);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        NavButton_4 = new QVBoxLayout();
        NavButton_4->setObjectName("NavButton_4");
        NavButton_4->setSizeConstraint(QLayout::SetMaximumSize);
        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName("profileButton");
        profileButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_4->addWidget(profileButton);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName("line_4");
        line_4->setEnabled(true);
        line_4->setMinimumSize(QSize(200, 5));
        line_4->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(15);
        line_4->setMidLineWidth(6);
        line_4->setFrameShape(QFrame::HLine);

        NavButton_4->addWidget(line_4);


        horizontalLayout_4->addLayout(NavButton_4);

        NavButton_15 = new QVBoxLayout();
        NavButton_15->setObjectName("NavButton_15");
        NavButton_15->setSizeConstraint(QLayout::SetMaximumSize);
        assignButton = new QPushButton(layoutWidget);
        assignButton->setObjectName("assignButton");
        assignButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_15->addWidget(assignButton);

        line_16 = new QFrame(layoutWidget);
        line_16->setObjectName("line_16");
        line_16->setEnabled(true);
        line_16->setMinimumSize(QSize(200, 5));
        line_16->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_16->setFrameShadow(QFrame::Plain);
        line_16->setLineWidth(15);
        line_16->setMidLineWidth(6);
        line_16->setFrameShape(QFrame::HLine);

        NavButton_15->addWidget(line_16);


        horizontalLayout_4->addLayout(NavButton_15);

        NavButton_16 = new QVBoxLayout();
        NavButton_16->setObjectName("NavButton_16");
        NavButton_16->setSizeConstraint(QLayout::SetMaximumSize);
        managementButton = new QPushButton(layoutWidget);
        managementButton->setObjectName("managementButton");
        managementButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_16->addWidget(managementButton);

        line_17 = new QFrame(layoutWidget);
        line_17->setObjectName("line_17");
        line_17->setEnabled(true);
        line_17->setMinimumSize(QSize(200, 5));
        line_17->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_17->setFrameShadow(QFrame::Plain);
        line_17->setLineWidth(15);
        line_17->setMidLineWidth(6);
        line_17->setFrameShape(QFrame::HLine);

        NavButton_16->addWidget(line_17);


        horizontalLayout_4->addLayout(NavButton_16);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        NavButton_17 = new QVBoxLayout();
        NavButton_17->setObjectName("NavButton_17");
        NavButton_17->setSizeConstraint(QLayout::SetMaximumSize);
        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_17->addWidget(logoutButton);

        line_18 = new QFrame(layoutWidget);
        line_18->setObjectName("line_18");
        line_18->setEnabled(true);
        line_18->setMinimumSize(QSize(200, 5));
        line_18->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_18->setFrameShadow(QFrame::Plain);
        line_18->setLineWidth(15);
        line_18->setMidLineWidth(6);
        line_18->setFrameShape(QFrame::HLine);

        NavButton_17->addWidget(line_18);


        horizontalLayout_4->addLayout(NavButton_17);

        navBackground = new QFrame(ProjectManagement);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(-10, -20, 1321, 61));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        assignedItems = new QScrollArea(ProjectManagement);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(-10, 30, 1321, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories_2 = new QWidget();
        assignmentCategories_2->setObjectName("assignmentCategories_2");
        assignmentCategories_2->setGeometry(QRect(0, 0, 1319, 759));
        verticalLayout_3 = new QVBoxLayout(assignmentCategories_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pageFrame_2 = new QVBoxLayout();
        pageFrame_2->setObjectName("pageFrame_2");
        title_2 = new QLabel(assignmentCategories_2);
        title_2->setObjectName("title_2");
        title_2->setMinimumSize(QSize(0, 100));
        title_2->setMaximumSize(QSize(16777215, 100));
        title_2->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        title_2->setAlignment(Qt::AlignCenter);

        pageFrame_2->addWidget(title_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 10);
        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        newProjectName = new QLineEdit(assignmentCategories_2);
        newProjectName->setObjectName("newProjectName");
        newProjectName->setMinimumSize(QSize(0, 35));
        newProjectName->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px; padding-left:5px;\n"
""));
        newProjectName->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(newProjectName);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        createProjectButton = new QPushButton(assignmentCategories_2);
        createProjectButton->setObjectName("createProjectButton");
        createProjectButton->setMinimumSize(QSize(200, 35));
        createProjectButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px;"));

        horizontalLayout_2->addWidget(createProjectButton);

        horizontalSpacer_8 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        pageFrame_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(pageFrame_2);

        verticalSpacer_6 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        assignedItems->setWidget(assignmentCategories_2);
        backgroundGradient->raise();
        navBackground->raise();
        layoutWidget->raise();
        assignedItems->raise();

        retranslateUi(ProjectManagement);

        QMetaObject::connectSlotsByName(ProjectManagement);
    } // setupUi

    void retranslateUi(QWidget *ProjectManagement)
    {
        ProjectManagement->setWindowTitle(QCoreApplication::translate("ProjectManagement", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("ProjectManagement", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("ProjectManagement", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("ProjectManagement", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("ProjectManagement", "Logout", nullptr));
        title_2->setText(QCoreApplication::translate("ProjectManagement", "Projects", nullptr));
        newProjectName->setInputMask(QString());
        newProjectName->setText(QString());
        newProjectName->setPlaceholderText(QCoreApplication::translate("ProjectManagement", "New project name...", nullptr));
        createProjectButton->setText(QCoreApplication::translate("ProjectManagement", "Create Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectManagement: public Ui_ProjectManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTMANAGEMENT_H

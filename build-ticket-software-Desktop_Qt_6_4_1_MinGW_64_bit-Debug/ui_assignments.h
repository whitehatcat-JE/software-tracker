/********************************************************************************
** Form generated from reading UI file 'assignments.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENTS_H
#define UI_ASSIGNMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignments
{
public:
    QFrame *navBackground;
    QPushButton *backgroundGradient;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *NavButton;
    QPushButton *profileButton;
    QFrame *line;
    QVBoxLayout *NavButton_6;
    QPushButton *assignedButton;
    QFrame *line_7;
    QVBoxLayout *NavButton_7;
    QPushButton *managementButton;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *NavButton_8;
    QPushButton *logoutButton;
    QFrame *line_9;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *ticketsLayout;
    QPushButton *ticketsButton;
    QVBoxLayout *groupsLayout;
    QPushButton *groupsButton;
    QVBoxLayout *projectsLayout;
    QPushButton *projectsButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Assignments)
    {
        if (Assignments->objectName().isEmpty())
            Assignments->setObjectName("Assignments");
        Assignments->resize(1300, 800);
        Assignments->setMinimumSize(QSize(1200, 800));
        Assignments->setMaximumSize(QSize(1300, 800));
        Assignments->setAutoFillBackground(false);
        Assignments->setStyleSheet(QString::fromUtf8(""));
        navBackground = new QFrame(Assignments);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        backgroundGradient = new QPushButton(Assignments);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-20, 20, 1331, 791));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(Assignments);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NavButton = new QVBoxLayout();
        NavButton->setObjectName("NavButton");
        NavButton->setSizeConstraint(QLayout::SetMaximumSize);
        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName("profileButton");
        profileButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton->addWidget(profileButton);

        line = new QFrame(layoutWidget);
        line->setObjectName("line");
        line->setEnabled(true);
        line->setMinimumSize(QSize(200, 5));
        line->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(15);
        line->setMidLineWidth(6);
        line->setFrameShape(QFrame::HLine);

        NavButton->addWidget(line);


        horizontalLayout->addLayout(NavButton);

        NavButton_6 = new QVBoxLayout();
        NavButton_6->setObjectName("NavButton_6");
        NavButton_6->setSizeConstraint(QLayout::SetMaximumSize);
        assignedButton = new QPushButton(layoutWidget);
        assignedButton->setObjectName("assignedButton");
        assignedButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_6->addWidget(assignedButton);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName("line_7");
        line_7->setEnabled(true);
        line_7->setMinimumSize(QSize(200, 5));
        line_7->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setLineWidth(15);
        line_7->setMidLineWidth(6);
        line_7->setFrameShape(QFrame::HLine);

        NavButton_6->addWidget(line_7);


        horizontalLayout->addLayout(NavButton_6);

        NavButton_7 = new QVBoxLayout();
        NavButton_7->setObjectName("NavButton_7");
        NavButton_7->setSizeConstraint(QLayout::SetMaximumSize);
        managementButton = new QPushButton(layoutWidget);
        managementButton->setObjectName("managementButton");
        managementButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_7->addWidget(managementButton);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName("line_8");
        line_8->setEnabled(true);
        line_8->setMinimumSize(QSize(200, 5));
        line_8->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setLineWidth(15);
        line_8->setMidLineWidth(6);
        line_8->setFrameShape(QFrame::HLine);

        NavButton_7->addWidget(line_8);


        horizontalLayout->addLayout(NavButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        NavButton_8 = new QVBoxLayout();
        NavButton_8->setObjectName("NavButton_8");
        NavButton_8->setSizeConstraint(QLayout::SetMaximumSize);
        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_8->addWidget(logoutButton);

        line_9 = new QFrame(layoutWidget);
        line_9->setObjectName("line_9");
        line_9->setEnabled(true);
        line_9->setMinimumSize(QSize(200, 5));
        line_9->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setLineWidth(15);
        line_9->setMidLineWidth(6);
        line_9->setFrameShape(QFrame::HLine);

        NavButton_8->addWidget(line_9);


        horizontalLayout->addLayout(NavButton_8);

        assignedItems = new QScrollArea(Assignments);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(-1, 39, 1301, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories = new QWidget();
        assignmentCategories->setObjectName("assignmentCategories");
        assignmentCategories->setGeometry(QRect(0, 0, 1299, 759));
        verticalLayout = new QVBoxLayout(assignmentCategories);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(assignmentCategories);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 150));
        label->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        ticketsLayout = new QVBoxLayout();
        ticketsLayout->setObjectName("ticketsLayout");
        ticketsButton = new QPushButton(assignmentCategories);
        ticketsButton->setObjectName("ticketsButton");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ticketsButton->sizePolicy().hasHeightForWidth());
        ticketsButton->setSizePolicy(sizePolicy);
        ticketsButton->setMinimumSize(QSize(0, 75));
        ticketsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        ticketsButton->setCheckable(true);

        ticketsLayout->addWidget(ticketsButton);


        verticalLayout->addLayout(ticketsLayout);

        groupsLayout = new QVBoxLayout();
        groupsLayout->setSpacing(6);
        groupsLayout->setObjectName("groupsLayout");
        groupsButton = new QPushButton(assignmentCategories);
        groupsButton->setObjectName("groupsButton");
        sizePolicy.setHeightForWidth(groupsButton->sizePolicy().hasHeightForWidth());
        groupsButton->setSizePolicy(sizePolicy);
        groupsButton->setMinimumSize(QSize(0, 75));
        groupsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        groupsButton->setCheckable(true);

        groupsLayout->addWidget(groupsButton);


        verticalLayout->addLayout(groupsLayout);

        projectsLayout = new QVBoxLayout();
        projectsLayout->setObjectName("projectsLayout");
        projectsButton = new QPushButton(assignmentCategories);
        projectsButton->setObjectName("projectsButton");
        sizePolicy.setHeightForWidth(projectsButton->sizePolicy().hasHeightForWidth());
        projectsButton->setSizePolicy(sizePolicy);
        projectsButton->setMinimumSize(QSize(0, 75));
        projectsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        projectsButton->setCheckable(true);

        projectsLayout->addWidget(projectsButton);


        verticalLayout->addLayout(projectsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        assignedItems->setWidget(assignmentCategories);
        backgroundGradient->raise();
        assignedItems->raise();
        navBackground->raise();
        layoutWidget->raise();

        retranslateUi(Assignments);

        QMetaObject::connectSlotsByName(Assignments);
    } // setupUi

    void retranslateUi(QWidget *Assignments)
    {
        Assignments->setWindowTitle(QCoreApplication::translate("Assignments", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("Assignments", "Profile", nullptr));
        assignedButton->setText(QCoreApplication::translate("Assignments", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("Assignments", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("Assignments", "Logout", nullptr));
        label->setText(QCoreApplication::translate("Assignments", "Assignments", nullptr));
        ticketsButton->setText(QCoreApplication::translate("Assignments", "Tickets                                                                                                            \342\226\272", nullptr));
        groupsButton->setText(QCoreApplication::translate("Assignments", "Groups                                                                                                            \342\226\272", nullptr));
        projectsButton->setText(QCoreApplication::translate("Assignments", "Projects                                                                                                           \342\226\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignments: public Ui_Assignments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENTS_H

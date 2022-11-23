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
    QPushButton *pushButton;
    QFrame *line;
    QVBoxLayout *NavButton_6;
    QPushButton *pushButton_6;
    QFrame *line_7;
    QVBoxLayout *NavButton_7;
    QPushButton *pushButton_7;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *NavButton_8;
    QPushButton *pushButton_8;
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
            Assignments->setObjectName(QString::fromUtf8("Assignments"));
        Assignments->resize(1300, 800);
        Assignments->setMinimumSize(QSize(1200, 800));
        Assignments->setMaximumSize(QSize(1300, 800));
        Assignments->setAutoFillBackground(false);
        Assignments->setStyleSheet(QString::fromUtf8(""));
        navBackground = new QFrame(Assignments);
        navBackground->setObjectName(QString::fromUtf8("navBackground"));
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        backgroundGradient = new QPushButton(Assignments);
        backgroundGradient->setObjectName(QString::fromUtf8("backgroundGradient"));
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-20, 20, 1331, 781));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(Assignments);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NavButton = new QVBoxLayout();
        NavButton->setObjectName(QString::fromUtf8("NavButton"));
        NavButton->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton->addWidget(pushButton);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
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
        NavButton_6->setObjectName(QString::fromUtf8("NavButton_6"));
        NavButton_6->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_6->addWidget(pushButton_6);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
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
        NavButton_7->setObjectName(QString::fromUtf8("NavButton_7"));
        NavButton_7->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_7->addWidget(pushButton_7);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
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
        NavButton_8->setObjectName(QString::fromUtf8("NavButton_8"));
        NavButton_8->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_8->addWidget(pushButton_8);

        line_9 = new QFrame(layoutWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
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
        assignedItems->setObjectName(QString::fromUtf8("assignedItems"));
        assignedItems->setGeometry(QRect(-1, 39, 1301, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories = new QWidget();
        assignmentCategories->setObjectName(QString::fromUtf8("assignmentCategories"));
        assignmentCategories->setGeometry(QRect(0, 0, 1299, 759));
        verticalLayout = new QVBoxLayout(assignmentCategories);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(assignmentCategories);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 150));
        label->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        ticketsLayout = new QVBoxLayout();
        ticketsLayout->setObjectName(QString::fromUtf8("ticketsLayout"));
        ticketsButton = new QPushButton(assignmentCategories);
        ticketsButton->setObjectName(QString::fromUtf8("ticketsButton"));
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
        groupsLayout->setObjectName(QString::fromUtf8("groupsLayout"));
        groupsButton = new QPushButton(assignmentCategories);
        groupsButton->setObjectName(QString::fromUtf8("groupsButton"));
        sizePolicy.setHeightForWidth(groupsButton->sizePolicy().hasHeightForWidth());
        groupsButton->setSizePolicy(sizePolicy);
        groupsButton->setMinimumSize(QSize(0, 75));
        groupsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        groupsButton->setCheckable(true);

        groupsLayout->addWidget(groupsButton);


        verticalLayout->addLayout(groupsLayout);

        projectsLayout = new QVBoxLayout();
        projectsLayout->setObjectName(QString::fromUtf8("projectsLayout"));
        projectsButton = new QPushButton(assignmentCategories);
        projectsButton->setObjectName(QString::fromUtf8("projectsButton"));
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
        pushButton->setText(QCoreApplication::translate("Assignments", "Profile", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Assignments", "Assigned", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Assignments", "Management", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Assignments", "Logout", nullptr));
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

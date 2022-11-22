/********************************************************************************
** Form generated from reading UI file 'groupmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMANAGEMENT_H
#define UI_GROUPMANAGEMENT_H

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

class Ui_GroupManagement
{
public:
    QPushButton *backgroundGradient;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *NavButton_3;
    QPushButton *profileButton;
    QFrame *line_3;
    QVBoxLayout *NavButton_12;
    QPushButton *assignButton;
    QFrame *line_13;
    QVBoxLayout *NavButton_13;
    QPushButton *managementButton;
    QFrame *line_14;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *NavButton_14;
    QPushButton *logoutButton;
    QFrame *line_15;
    QFrame *navBackground;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *pageFrame;
    QLabel *title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *newGroupName;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *createGroupButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *GroupManagement)
    {
        if (GroupManagement->objectName().isEmpty())
            GroupManagement->setObjectName("GroupManagement");
        GroupManagement->resize(1300, 800);
        GroupManagement->setMinimumSize(QSize(1300, 800));
        GroupManagement->setMaximumSize(QSize(1300, 800));
        backgroundGradient = new QPushButton(GroupManagement);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-30, 10, 1341, 791));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(GroupManagement);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        NavButton_3 = new QVBoxLayout();
        NavButton_3->setObjectName("NavButton_3");
        NavButton_3->setSizeConstraint(QLayout::SetMaximumSize);
        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName("profileButton");
        profileButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_3->addWidget(profileButton);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName("line_3");
        line_3->setEnabled(true);
        line_3->setMinimumSize(QSize(200, 5));
        line_3->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(15);
        line_3->setMidLineWidth(6);
        line_3->setFrameShape(QFrame::HLine);

        NavButton_3->addWidget(line_3);


        horizontalLayout_3->addLayout(NavButton_3);

        NavButton_12 = new QVBoxLayout();
        NavButton_12->setObjectName("NavButton_12");
        NavButton_12->setSizeConstraint(QLayout::SetMaximumSize);
        assignButton = new QPushButton(layoutWidget);
        assignButton->setObjectName("assignButton");
        assignButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_12->addWidget(assignButton);

        line_13 = new QFrame(layoutWidget);
        line_13->setObjectName("line_13");
        line_13->setEnabled(true);
        line_13->setMinimumSize(QSize(200, 5));
        line_13->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_13->setFrameShadow(QFrame::Plain);
        line_13->setLineWidth(15);
        line_13->setMidLineWidth(6);
        line_13->setFrameShape(QFrame::HLine);

        NavButton_12->addWidget(line_13);


        horizontalLayout_3->addLayout(NavButton_12);

        NavButton_13 = new QVBoxLayout();
        NavButton_13->setObjectName("NavButton_13");
        NavButton_13->setSizeConstraint(QLayout::SetMaximumSize);
        managementButton = new QPushButton(layoutWidget);
        managementButton->setObjectName("managementButton");
        managementButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_13->addWidget(managementButton);

        line_14 = new QFrame(layoutWidget);
        line_14->setObjectName("line_14");
        line_14->setEnabled(true);
        line_14->setMinimumSize(QSize(200, 5));
        line_14->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_14->setFrameShadow(QFrame::Plain);
        line_14->setLineWidth(15);
        line_14->setMidLineWidth(6);
        line_14->setFrameShape(QFrame::HLine);

        NavButton_13->addWidget(line_14);


        horizontalLayout_3->addLayout(NavButton_13);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        NavButton_14 = new QVBoxLayout();
        NavButton_14->setObjectName("NavButton_14");
        NavButton_14->setSizeConstraint(QLayout::SetMaximumSize);
        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_14->addWidget(logoutButton);

        line_15 = new QFrame(layoutWidget);
        line_15->setObjectName("line_15");
        line_15->setEnabled(true);
        line_15->setMinimumSize(QSize(200, 5));
        line_15->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_15->setFrameShadow(QFrame::Plain);
        line_15->setLineWidth(15);
        line_15->setMidLineWidth(6);
        line_15->setFrameShape(QFrame::HLine);

        NavButton_14->addWidget(line_15);


        horizontalLayout_3->addLayout(NavButton_14);

        navBackground = new QFrame(GroupManagement);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(-10, -10, 1321, 51));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        assignedItems = new QScrollArea(GroupManagement);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(-10, 40, 1321, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories = new QWidget();
        assignmentCategories->setObjectName("assignmentCategories");
        assignmentCategories->setGeometry(QRect(0, 0, 1319, 759));
        verticalLayout_2 = new QVBoxLayout(assignmentCategories);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pageFrame = new QVBoxLayout();
        pageFrame->setObjectName("pageFrame");
        title = new QLabel(assignmentCategories);
        title->setObjectName("title");
        title->setMinimumSize(QSize(0, 100));
        title->setMaximumSize(QSize(16777215, 100));
        title->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        title->setAlignment(Qt::AlignCenter);

        pageFrame->addWidget(title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 10);
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newGroupName = new QLineEdit(assignmentCategories);
        newGroupName->setObjectName("newGroupName");
        newGroupName->setMinimumSize(QSize(0, 35));
        newGroupName->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px; padding-left:5px;\n"
""));
        newGroupName->setClearButtonEnabled(false);

        horizontalLayout->addWidget(newGroupName);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        createGroupButton = new QPushButton(assignmentCategories);
        createGroupButton->setObjectName("createGroupButton");
        createGroupButton->setMinimumSize(QSize(200, 35));
        createGroupButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px;"));

        horizontalLayout->addWidget(createGroupButton);

        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        pageFrame->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(pageFrame);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        assignedItems->setWidget(assignmentCategories);
        backgroundGradient->raise();
        navBackground->raise();
        layoutWidget->raise();
        assignedItems->raise();

        retranslateUi(GroupManagement);

        QMetaObject::connectSlotsByName(GroupManagement);
    } // setupUi

    void retranslateUi(QWidget *GroupManagement)
    {
        GroupManagement->setWindowTitle(QCoreApplication::translate("GroupManagement", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("GroupManagement", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("GroupManagement", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("GroupManagement", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("GroupManagement", "Logout", nullptr));
        title->setText(QCoreApplication::translate("GroupManagement", "Groups", nullptr));
        newGroupName->setInputMask(QString());
        newGroupName->setText(QString());
        newGroupName->setPlaceholderText(QCoreApplication::translate("GroupManagement", "New group name...", nullptr));
        createGroupButton->setText(QCoreApplication::translate("GroupManagement", "Create Group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupManagement: public Ui_GroupManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMANAGEMENT_H

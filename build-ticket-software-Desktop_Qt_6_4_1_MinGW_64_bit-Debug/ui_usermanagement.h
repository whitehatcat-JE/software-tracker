/********************************************************************************
** Form generated from reading UI file 'usermanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENT_H
#define UI_USERMANAGEMENT_H

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

class Ui_UserManagement
{
public:
    QFrame *navBackground;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *pageFrame_3;
    QLabel *title_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEditPassword_3;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *lineEditPassword_4;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_7;
    QPushButton *backgroundGradient;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *NavButton_5;
    QPushButton *profileButton;
    QFrame *line_5;
    QVBoxLayout *NavButton_18;
    QPushButton *assignButton;
    QFrame *line_19;
    QVBoxLayout *NavButton_19;
    QPushButton *managementButton;
    QFrame *line_20;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *NavButton_20;
    QPushButton *logoutButton;
    QFrame *line_21;

    void setupUi(QWidget *UserManagement)
    {
        if (UserManagement->objectName().isEmpty())
            UserManagement->setObjectName("UserManagement");
        UserManagement->resize(1300, 800);
        UserManagement->setMinimumSize(QSize(1300, 800));
        UserManagement->setMaximumSize(QSize(1300, 800));
        navBackground = new QFrame(UserManagement);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(-10, -10, 1321, 51));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        assignedItems = new QScrollArea(UserManagement);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(-10, 40, 1321, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories_3 = new QWidget();
        assignmentCategories_3->setObjectName("assignmentCategories_3");
        assignmentCategories_3->setGeometry(QRect(0, 0, 1319, 759));
        verticalLayout_4 = new QVBoxLayout(assignmentCategories_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        pageFrame_3 = new QVBoxLayout();
        pageFrame_3->setObjectName("pageFrame_3");
        title_3 = new QLabel(assignmentCategories_3);
        title_3->setObjectName("title_3");
        title_3->setMinimumSize(QSize(0, 100));
        title_3->setMaximumSize(QSize(16777215, 100));
        title_3->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        title_3->setAlignment(Qt::AlignCenter);

        pageFrame_3->addWidget(title_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 10);
        horizontalSpacer_9 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        lineEditPassword_3 = new QLineEdit(assignmentCategories_3);
        lineEditPassword_3->setObjectName("lineEditPassword_3");
        lineEditPassword_3->setMinimumSize(QSize(0, 35));
        lineEditPassword_3->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px; padding-left:5px;\n"
""));
        lineEditPassword_3->setClearButtonEnabled(false);

        horizontalLayout_3->addWidget(lineEditPassword_3);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        lineEditPassword_4 = new QLineEdit(assignmentCategories_3);
        lineEditPassword_4->setObjectName("lineEditPassword_4");
        lineEditPassword_4->setMinimumSize(QSize(0, 35));
        lineEditPassword_4->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px; padding-left:5px;\n"
""));
        lineEditPassword_4->setClearButtonEnabled(false);

        horizontalLayout_3->addWidget(lineEditPassword_4);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        pushButton_6 = new QPushButton(assignmentCategories_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(200, 35));
        pushButton_6->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px;"));

        horizontalLayout_3->addWidget(pushButton_6);

        horizontalSpacer_11 = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        pageFrame_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(pageFrame_3);

        verticalSpacer_7 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_4->addItem(verticalSpacer_7);

        assignedItems->setWidget(assignmentCategories_3);
        backgroundGradient = new QPushButton(UserManagement);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-30, 10, 1341, 791));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(UserManagement);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        NavButton_5 = new QVBoxLayout();
        NavButton_5->setObjectName("NavButton_5");
        NavButton_5->setSizeConstraint(QLayout::SetMaximumSize);
        profileButton = new QPushButton(layoutWidget);
        profileButton->setObjectName("profileButton");
        profileButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_5->addWidget(profileButton);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName("line_5");
        line_5->setEnabled(true);
        line_5->setMinimumSize(QSize(200, 5));
        line_5->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(15);
        line_5->setMidLineWidth(6);
        line_5->setFrameShape(QFrame::HLine);

        NavButton_5->addWidget(line_5);


        horizontalLayout_5->addLayout(NavButton_5);

        NavButton_18 = new QVBoxLayout();
        NavButton_18->setObjectName("NavButton_18");
        NavButton_18->setSizeConstraint(QLayout::SetMaximumSize);
        assignButton = new QPushButton(layoutWidget);
        assignButton->setObjectName("assignButton");
        assignButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_18->addWidget(assignButton);

        line_19 = new QFrame(layoutWidget);
        line_19->setObjectName("line_19");
        line_19->setEnabled(true);
        line_19->setMinimumSize(QSize(200, 5));
        line_19->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_19->setFrameShadow(QFrame::Plain);
        line_19->setLineWidth(15);
        line_19->setMidLineWidth(6);
        line_19->setFrameShape(QFrame::HLine);

        NavButton_18->addWidget(line_19);


        horizontalLayout_5->addLayout(NavButton_18);

        NavButton_19 = new QVBoxLayout();
        NavButton_19->setObjectName("NavButton_19");
        NavButton_19->setSizeConstraint(QLayout::SetMaximumSize);
        managementButton = new QPushButton(layoutWidget);
        managementButton->setObjectName("managementButton");
        managementButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_19->addWidget(managementButton);

        line_20 = new QFrame(layoutWidget);
        line_20->setObjectName("line_20");
        line_20->setEnabled(true);
        line_20->setMinimumSize(QSize(200, 5));
        line_20->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_20->setFrameShadow(QFrame::Plain);
        line_20->setLineWidth(15);
        line_20->setMidLineWidth(6);
        line_20->setFrameShape(QFrame::HLine);

        NavButton_19->addWidget(line_20);


        horizontalLayout_5->addLayout(NavButton_19);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        NavButton_20 = new QVBoxLayout();
        NavButton_20->setObjectName("NavButton_20");
        NavButton_20->setSizeConstraint(QLayout::SetMaximumSize);
        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_20->addWidget(logoutButton);

        line_21 = new QFrame(layoutWidget);
        line_21->setObjectName("line_21");
        line_21->setEnabled(true);
        line_21->setMinimumSize(QSize(200, 5));
        line_21->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_21->setFrameShadow(QFrame::Plain);
        line_21->setLineWidth(15);
        line_21->setMidLineWidth(6);
        line_21->setFrameShape(QFrame::HLine);

        NavButton_20->addWidget(line_21);


        horizontalLayout_5->addLayout(NavButton_20);

        backgroundGradient->raise();
        navBackground->raise();
        assignedItems->raise();
        layoutWidget->raise();

        retranslateUi(UserManagement);

        QMetaObject::connectSlotsByName(UserManagement);
    } // setupUi

    void retranslateUi(QWidget *UserManagement)
    {
        UserManagement->setWindowTitle(QCoreApplication::translate("UserManagement", "Form", nullptr));
        title_3->setText(QCoreApplication::translate("UserManagement", "Users", nullptr));
        lineEditPassword_3->setInputMask(QString());
        lineEditPassword_3->setText(QString());
        lineEditPassword_3->setPlaceholderText(QCoreApplication::translate("UserManagement", "Username...", nullptr));
        lineEditPassword_4->setInputMask(QString());
        lineEditPassword_4->setText(QString());
        lineEditPassword_4->setPlaceholderText(QCoreApplication::translate("UserManagement", "Password...", nullptr));
        pushButton_6->setText(QCoreApplication::translate("UserManagement", "Create User", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("UserManagement", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("UserManagement", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("UserManagement", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("UserManagement", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManagement: public Ui_UserManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENT_H

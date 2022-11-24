/********************************************************************************
** Form generated from reading UI file 'management.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENT_H
#define UI_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Management
{
public:
    QPushButton *backgroundGradient;
    QFrame *navBackground;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *NavButton;
    QPushButton *profileButton;
    QFrame *line;
    QVBoxLayout *NavButton_6;
    QPushButton *assignedButton;
    QFrame *line_7;
    QVBoxLayout *NavButton_7;
    QPushButton *pushButton_7;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *NavButton_8;
    QPushButton *logoutButton;
    QFrame *line_9;
    QLabel *label;
    QPushButton *usersButton;
    QPushButton *groupsButton;
    QPushButton *projectsButton;

    void setupUi(QWidget *Management)
    {
        if (Management->objectName().isEmpty())
            Management->setObjectName("Management");
        Management->resize(1300, 800);
        Management->setMinimumSize(QSize(1300, 800));
        Management->setMaximumSize(QSize(1300, 800));
        backgroundGradient = new QPushButton(Management);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-10, -10, 1331, 831));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        navBackground = new QFrame(Management);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        layoutWidget = new QWidget(Management);
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
        assignedButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_6->addWidget(assignedButton);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName("line_7");
        line_7->setEnabled(true);
        line_7->setMinimumSize(QSize(200, 5));
        line_7->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setLineWidth(15);
        line_7->setMidLineWidth(6);
        line_7->setFrameShape(QFrame::HLine);

        NavButton_6->addWidget(line_7);


        horizontalLayout->addLayout(NavButton_6);

        NavButton_7 = new QVBoxLayout();
        NavButton_7->setObjectName("NavButton_7");
        NavButton_7->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_7->addWidget(pushButton_7);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName("line_8");
        line_8->setEnabled(true);
        line_8->setMinimumSize(QSize(200, 5));
        line_8->setStyleSheet(QString::fromUtf8("color:#05448A;"));
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

        label = new QLabel(Management);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 40, 1281, 150));
        label->setMinimumSize(QSize(0, 150));
        label->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        label->setAlignment(Qt::AlignCenter);
        usersButton = new QPushButton(Management);
        usersButton->setObjectName("usersButton");
        usersButton->setGeometry(QRect(-2, 200, 1301, 75));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usersButton->sizePolicy().hasHeightForWidth());
        usersButton->setSizePolicy(sizePolicy);
        usersButton->setMinimumSize(QSize(0, 75));
        usersButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        usersButton->setCheckable(true);
        groupsButton = new QPushButton(Management);
        groupsButton->setObjectName("groupsButton");
        groupsButton->setGeometry(QRect(0, 280, 1301, 75));
        sizePolicy.setHeightForWidth(groupsButton->sizePolicy().hasHeightForWidth());
        groupsButton->setSizePolicy(sizePolicy);
        groupsButton->setMinimumSize(QSize(0, 75));
        groupsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        groupsButton->setCheckable(true);
        projectsButton = new QPushButton(Management);
        projectsButton->setObjectName("projectsButton");
        projectsButton->setGeometry(QRect(0, 360, 1301, 75));
        sizePolicy.setHeightForWidth(projectsButton->sizePolicy().hasHeightForWidth());
        projectsButton->setSizePolicy(sizePolicy);
        projectsButton->setMinimumSize(QSize(0, 75));
        projectsButton->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        projectsButton->setCheckable(true);

        retranslateUi(Management);

        QMetaObject::connectSlotsByName(Management);
    } // setupUi

    void retranslateUi(QWidget *Management)
    {
        Management->setWindowTitle(QCoreApplication::translate("Management", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("Management", "Profile", nullptr));
        assignedButton->setText(QCoreApplication::translate("Management", "Assigned", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Management", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("Management", "Logout", nullptr));
        label->setText(QCoreApplication::translate("Management", "Management", nullptr));
        usersButton->setText(QCoreApplication::translate("Management", "Users                                                                                                                ", nullptr));
        groupsButton->setText(QCoreApplication::translate("Management", "Groups                                                                                                              ", nullptr));
        projectsButton->setText(QCoreApplication::translate("Management", "Projects                                                                                                            ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Management: public Ui_Management {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENT_H

/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QPushButton *EditDetails;
    QPushButton *Background;
    QLabel *PFP;
    QPushButton *Line1;
    QLabel *Name;
    QLabel *JobTitle;
    QLabel *workHours;
    QLabel *location;
    QPushButton *Line2;
    QLabel *email;
    QLabel *number;
    QPushButton *Line3;
    QPushButton *changePassword;
    QPushButton *Line4;
    QLineEdit *NameEdit;
    QLineEdit *JobEdit;
    QLineEdit *TimeEdit;
    QLineEdit *LocationEdit;
    QLineEdit *EmailEdit;
    QLineEdit *NumberEdit;
    QPushButton *EditProfilePic;
    QPushButton *ProfileOp1;
    QPushButton *ProfileOp2;
    QPushButton *ProfileOp3;
    QPushButton *ProfileOp4;
    QPushButton *ProfileOp5;
    QPushButton *ProfileOp6;
    QPushButton *ProfileOp7;
    QPushButton *ProfileOp8;
    QPushButton *ProfileOp9;
    QFrame *navBackground;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *NavButton;
    QPushButton *profileButton;
    QFrame *line;
    QVBoxLayout *NavButton_6;
    QPushButton *assignButton;
    QFrame *line_7;
    QVBoxLayout *NavButton_7;
    QPushButton *managementButton;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *NavButton_8;
    QPushButton *logoutButton;
    QFrame *line_9;

    void setupUi(QWidget *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName("Profile");
        Profile->resize(1300, 800);
        Profile->setMinimumSize(QSize(1300, 800));
        Profile->setMaximumSize(QSize(1300, 800));
        EditDetails = new QPushButton(Profile);
        EditDetails->setObjectName("EditDetails");
        EditDetails->setGeometry(QRect(1020, 200, 40, 40));
        EditDetails->setMinimumSize(QSize(39, 39));
        EditDetails->setMaximumSize(QSize(40, 40));
        EditDetails->setAutoFillBackground(false);
        EditDetails->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        EditDetails->setCheckable(true);
        Background = new QPushButton(Profile);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(-10, -20, 1321, 831));
        Background->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        PFP = new QLabel(Profile);
        PFP->setObjectName("PFP");
        PFP->setGeometry(QRect(40, 140, 300, 300));
        PFP->setMinimumSize(QSize(199, 199));
        PFP->setMaximumSize(QSize(300, 300));
        PFP->setAutoFillBackground(false);
        PFP->setScaledContents(true);
        Line1 = new QPushButton(Profile);
        Line1->setObjectName("Line1");
        Line1->setGeometry(QRect(390, 250, 611, 5));
        Line1->setMaximumSize(QSize(16777215, 5));
        Line1->setStyleSheet(QString::fromUtf8("background-color:#32ACBE; border:0px;"));
        Name = new QLabel(Profile);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(410, 150, 581, 91));
        QFont font;
        font.setPointSize(48);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        JobTitle = new QLabel(Profile);
        JobTitle->setObjectName("JobTitle");
        JobTitle->setGeometry(QRect(400, 270, 591, 41));
        QFont font1;
        font1.setPointSize(24);
        JobTitle->setFont(font1);
        JobTitle->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        workHours = new QLabel(Profile);
        workHours->setObjectName("workHours");
        workHours->setGeometry(QRect(400, 330, 591, 41));
        workHours->setFont(font1);
        workHours->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        location = new QLabel(Profile);
        location->setObjectName("location");
        location->setGeometry(QRect(400, 390, 591, 41));
        location->setFont(font1);
        location->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        Line2 = new QPushButton(Profile);
        Line2->setObjectName("Line2");
        Line2->setGeometry(QRect(390, 440, 611, 5));
        Line2->setMaximumSize(QSize(16777215, 5));
        Line2->setStyleSheet(QString::fromUtf8("background-color:#32ACBE; border:0px;"));
        email = new QLabel(Profile);
        email->setObjectName("email");
        email->setGeometry(QRect(400, 460, 591, 41));
        QFont font2;
        font2.setPointSize(20);
        email->setFont(font2);
        email->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        number = new QLabel(Profile);
        number->setObjectName("number");
        number->setGeometry(QRect(400, 520, 591, 41));
        number->setFont(font2);
        number->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        Line3 = new QPushButton(Profile);
        Line3->setObjectName("Line3");
        Line3->setGeometry(QRect(390, 580, 611, 5));
        Line3->setMaximumSize(QSize(16777215, 5));
        Line3->setStyleSheet(QString::fromUtf8("background-color:#CA0736; border:0px;"));
        changePassword = new QPushButton(Profile);
        changePassword->setObjectName("changePassword");
        changePassword->setGeometry(QRect(560, 600, 261, 41));
        changePassword->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736;"));
        Line4 = new QPushButton(Profile);
        Line4->setObjectName("Line4");
        Line4->setGeometry(QRect(1010, 250, 61, 5));
        Line4->setMinimumSize(QSize(50, 0));
        Line4->setMaximumSize(QSize(70, 5));
        Line4->setStyleSheet(QString::fromUtf8("background-color:#CA0736; border:0px;"));
        NameEdit = new QLineEdit(Profile);
        NameEdit->setObjectName("NameEdit");
        NameEdit->setGeometry(QRect(390, 170, 601, 71));
        NameEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        JobEdit = new QLineEdit(Profile);
        JobEdit->setObjectName("JobEdit");
        JobEdit->setGeometry(QRect(390, 270, 601, 41));
        JobEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        TimeEdit = new QLineEdit(Profile);
        TimeEdit->setObjectName("TimeEdit");
        TimeEdit->setGeometry(QRect(390, 330, 601, 41));
        TimeEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        LocationEdit = new QLineEdit(Profile);
        LocationEdit->setObjectName("LocationEdit");
        LocationEdit->setGeometry(QRect(390, 390, 601, 41));
        LocationEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        EmailEdit = new QLineEdit(Profile);
        EmailEdit->setObjectName("EmailEdit");
        EmailEdit->setGeometry(QRect(390, 460, 601, 41));
        EmailEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        NumberEdit = new QLineEdit(Profile);
        NumberEdit->setObjectName("NumberEdit");
        NumberEdit->setGeometry(QRect(390, 520, 601, 41));
        NumberEdit->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:black; border:none;"));
        EditProfilePic = new QPushButton(Profile);
        EditProfilePic->setObjectName("EditProfilePic");
        EditProfilePic->setGeometry(QRect(300, 140, 40, 39));
        EditProfilePic->setMinimumSize(QSize(39, 39));
        EditProfilePic->setMaximumSize(QSize(40, 40));
        EditProfilePic->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        EditProfilePic->setCheckable(true);
        ProfileOp1 = new QPushButton(Profile);
        ProfileOp1->setObjectName("ProfileOp1");
        ProfileOp1->setGeometry(QRect(30, 450, 100, 99));
        ProfileOp1->setMinimumSize(QSize(79, 99));
        ProfileOp1->setMaximumSize(QSize(100, 100));
        ProfileOp1->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp1->setCheckable(false);
        ProfileOp2 = new QPushButton(Profile);
        ProfileOp2->setObjectName("ProfileOp2");
        ProfileOp2->setGeometry(QRect(140, 450, 100, 99));
        ProfileOp2->setMinimumSize(QSize(79, 99));
        ProfileOp2->setMaximumSize(QSize(100, 100));
        ProfileOp2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp3 = new QPushButton(Profile);
        ProfileOp3->setObjectName("ProfileOp3");
        ProfileOp3->setGeometry(QRect(250, 450, 100, 99));
        ProfileOp3->setMinimumSize(QSize(79, 99));
        ProfileOp3->setMaximumSize(QSize(100, 100));
        ProfileOp3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp4 = new QPushButton(Profile);
        ProfileOp4->setObjectName("ProfileOp4");
        ProfileOp4->setGeometry(QRect(30, 560, 100, 100));
        ProfileOp4->setMinimumSize(QSize(79, 79));
        ProfileOp4->setMaximumSize(QSize(100, 100));
        ProfileOp4->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp5 = new QPushButton(Profile);
        ProfileOp5->setObjectName("ProfileOp5");
        ProfileOp5->setGeometry(QRect(30, 670, 100, 100));
        ProfileOp5->setMinimumSize(QSize(79, 79));
        ProfileOp5->setMaximumSize(QSize(100, 100));
        ProfileOp5->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp6 = new QPushButton(Profile);
        ProfileOp6->setObjectName("ProfileOp6");
        ProfileOp6->setGeometry(QRect(250, 560, 100, 100));
        ProfileOp6->setMinimumSize(QSize(79, 79));
        ProfileOp6->setMaximumSize(QSize(100, 100));
        ProfileOp6->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp7 = new QPushButton(Profile);
        ProfileOp7->setObjectName("ProfileOp7");
        ProfileOp7->setGeometry(QRect(250, 670, 100, 100));
        ProfileOp7->setMinimumSize(QSize(79, 79));
        ProfileOp7->setMaximumSize(QSize(100, 100));
        ProfileOp7->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp8 = new QPushButton(Profile);
        ProfileOp8->setObjectName("ProfileOp8");
        ProfileOp8->setGeometry(QRect(140, 670, 100, 100));
        ProfileOp8->setMinimumSize(QSize(79, 79));
        ProfileOp8->setMaximumSize(QSize(100, 100));
        ProfileOp8->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        ProfileOp9 = new QPushButton(Profile);
        ProfileOp9->setObjectName("ProfileOp9");
        ProfileOp9->setGeometry(QRect(140, 560, 100, 100));
        ProfileOp9->setMinimumSize(QSize(79, 79));
        ProfileOp9->setMaximumSize(QSize(100, 100));
        ProfileOp9->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        navBackground = new QFrame(Profile);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        layoutWidget = new QWidget(Profile);
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
        profileButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton->addWidget(profileButton);

        line = new QFrame(layoutWidget);
        line->setObjectName("line");
        line->setEnabled(true);
        line->setMinimumSize(QSize(200, 5));
        line->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(15);
        line->setMidLineWidth(6);
        line->setFrameShape(QFrame::HLine);

        NavButton->addWidget(line);


        horizontalLayout->addLayout(NavButton);

        NavButton_6 = new QVBoxLayout();
        NavButton_6->setObjectName("NavButton_6");
        NavButton_6->setSizeConstraint(QLayout::SetMaximumSize);
        assignButton = new QPushButton(layoutWidget);
        assignButton->setObjectName("assignButton");
        assignButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_6->addWidget(assignButton);

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

        Background->raise();
        EditDetails->raise();
        PFP->raise();
        Line1->raise();
        Name->raise();
        JobTitle->raise();
        workHours->raise();
        location->raise();
        Line2->raise();
        email->raise();
        number->raise();
        Line3->raise();
        changePassword->raise();
        Line4->raise();
        NameEdit->raise();
        JobEdit->raise();
        TimeEdit->raise();
        LocationEdit->raise();
        EmailEdit->raise();
        NumberEdit->raise();
        EditProfilePic->raise();
        ProfileOp1->raise();
        ProfileOp2->raise();
        ProfileOp3->raise();
        ProfileOp4->raise();
        ProfileOp5->raise();
        ProfileOp6->raise();
        ProfileOp7->raise();
        ProfileOp8->raise();
        ProfileOp9->raise();
        navBackground->raise();
        layoutWidget->raise();

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QWidget *Profile)
    {
        Profile->setWindowTitle(QCoreApplication::translate("Profile", "Form", nullptr));
        EditDetails->setText(QString());
        Background->setText(QString());
        PFP->setText(QString());
        Line1->setText(QString());
        Name->setText(QCoreApplication::translate("Profile", "Greg", nullptr));
        JobTitle->setText(QCoreApplication::translate("Profile", "Senior Software Engineer", nullptr));
        workHours->setText(QCoreApplication::translate("Profile", "09:00 - 17:30  UTC", nullptr));
        location->setText(QCoreApplication::translate("Profile", "Washington, DC", nullptr));
        Line2->setText(QString());
        email->setText(QCoreApplication::translate("Profile", "almightyGreg@gmail.com", nullptr));
        number->setText(QCoreApplication::translate("Profile", "021 123 4567", nullptr));
        Line3->setText(QString());
        changePassword->setText(QCoreApplication::translate("Profile", "Change Password", nullptr));
        Line4->setText(QString());
        EditProfilePic->setText(QString());
        ProfileOp1->setText(QString());
        ProfileOp2->setText(QString());
        ProfileOp3->setText(QString());
        ProfileOp4->setText(QString());
        ProfileOp5->setText(QString());
        ProfileOp6->setText(QString());
        ProfileOp7->setText(QString());
        ProfileOp8->setText(QString());
        ProfileOp9->setText(QString());
        profileButton->setText(QCoreApplication::translate("Profile", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("Profile", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("Profile", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("Profile", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H

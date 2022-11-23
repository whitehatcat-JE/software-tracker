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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
        Background->setGeometry(QRect(0, -10, 1321, 831));
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
        Line1->setStyleSheet(QString::fromUtf8("background: blue;"));
        Name = new QLabel(Profile);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(410, 150, 261, 91));
        QFont font;
        font.setPointSize(48);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        JobTitle = new QLabel(Profile);
        JobTitle->setObjectName("JobTitle");
        JobTitle->setGeometry(QRect(400, 270, 441, 41));
        QFont font1;
        font1.setPointSize(24);
        JobTitle->setFont(font1);
        JobTitle->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        workHours = new QLabel(Profile);
        workHours->setObjectName("workHours");
        workHours->setGeometry(QRect(400, 330, 351, 41));
        workHours->setFont(font1);
        workHours->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        location = new QLabel(Profile);
        location->setObjectName("location");
        location->setGeometry(QRect(400, 390, 441, 41));
        location->setFont(font1);
        location->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        Line2 = new QPushButton(Profile);
        Line2->setObjectName("Line2");
        Line2->setGeometry(QRect(390, 440, 611, 5));
        Line2->setMaximumSize(QSize(16777215, 5));
        Line2->setStyleSheet(QString::fromUtf8("background: blue;"));
        email = new QLabel(Profile);
        email->setObjectName("email");
        email->setGeometry(QRect(400, 460, 441, 41));
        QFont font2;
        font2.setPointSize(20);
        email->setFont(font2);
        email->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        number = new QLabel(Profile);
        number->setObjectName("number");
        number->setGeometry(QRect(400, 520, 441, 41));
        number->setFont(font2);
        number->setStyleSheet(QString::fromUtf8("color:#ffffff"));
        Line3 = new QPushButton(Profile);
        Line3->setObjectName("Line3");
        Line3->setGeometry(QRect(390, 580, 611, 5));
        Line3->setMaximumSize(QSize(16777215, 5));
        Line3->setStyleSheet(QString::fromUtf8("background: red;"));
        changePassword = new QPushButton(Profile);
        changePassword->setObjectName("changePassword");
        changePassword->setGeometry(QRect(620, 650, 181, 41));
        changePassword->setStyleSheet(QString::fromUtf8("background: red;"));
        Line4 = new QPushButton(Profile);
        Line4->setObjectName("Line4");
        Line4->setGeometry(QRect(1010, 250, 61, 5));
        Line4->setMinimumSize(QSize(50, 0));
        Line4->setMaximumSize(QSize(70, 5));
        Line4->setStyleSheet(QString::fromUtf8("background: red;"));
        NameEdit = new QLineEdit(Profile);
        NameEdit->setObjectName("NameEdit");
        NameEdit->setGeometry(QRect(710, 170, 281, 61));
        JobEdit = new QLineEdit(Profile);
        JobEdit->setObjectName("JobEdit");
        JobEdit->setGeometry(QRect(782, 270, 211, 41));
        TimeEdit = new QLineEdit(Profile);
        TimeEdit->setObjectName("TimeEdit");
        TimeEdit->setGeometry(QRect(780, 330, 211, 41));
        LocationEdit = new QLineEdit(Profile);
        LocationEdit->setObjectName("LocationEdit");
        LocationEdit->setGeometry(QRect(780, 390, 211, 41));
        EmailEdit = new QLineEdit(Profile);
        EmailEdit->setObjectName("EmailEdit");
        EmailEdit->setGeometry(QRect(780, 460, 211, 41));
        NumberEdit = new QLineEdit(Profile);
        NumberEdit->setObjectName("NumberEdit");
        NumberEdit->setGeometry(QRect(780, 520, 211, 41));
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
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H

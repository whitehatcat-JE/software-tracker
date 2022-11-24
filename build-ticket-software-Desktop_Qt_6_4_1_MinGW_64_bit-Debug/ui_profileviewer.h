/********************************************************************************
** Form generated from reading UI file 'profileviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEVIEWER_H
#define UI_PROFILEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileViewer
{
public:
    QWidget *centralwidget;
    QLabel *number;
    QLabel *workHours;
    QLabel *JobTitle;
    QLabel *Name;
    QLabel *PFP;
    QLabel *email;
    QLabel *location;
    QFrame *navBackground;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *NavButton_2;
    QPushButton *profileButton_2;
    QFrame *line_2;
    QVBoxLayout *NavButton_9;
    QPushButton *assignButton_2;
    QFrame *line_10;
    QVBoxLayout *NavButton_10;
    QPushButton *managementButton_2;
    QFrame *line_11;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *NavButton_11;
    QPushButton *logoutButton_2;
    QFrame *line_12;
    QPushButton *Background;
    QPushButton *Line1;
    QPushButton *Line2;
    QPushButton *accessLevel;
    QLabel *JobTitle_2;

    void setupUi(QMainWindow *ProfileViewer)
    {
        if (ProfileViewer->objectName().isEmpty())
            ProfileViewer->setObjectName("ProfileViewer");
        ProfileViewer->resize(1300, 800);
        ProfileViewer->setMinimumSize(QSize(1300, 800));
        ProfileViewer->setMaximumSize(QSize(1300, 800));
        centralwidget = new QWidget(ProfileViewer);
        centralwidget->setObjectName("centralwidget");
        number = new QLabel(centralwidget);
        number->setObjectName("number");
        number->setGeometry(QRect(390, 520, 601, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        number->setFont(font);
        number->setStyleSheet(QString::fromUtf8("font-size: 24px; font-family: Inter; color: white;"));
        workHours = new QLabel(centralwidget);
        workHours->setObjectName("workHours");
        workHours->setGeometry(QRect(390, 330, 601, 41));
        workHours->setFont(font);
        workHours->setStyleSheet(QString::fromUtf8("font-size: 24px; font-family: Inter; color: white;"));
        JobTitle = new QLabel(centralwidget);
        JobTitle->setObjectName("JobTitle");
        JobTitle->setGeometry(QRect(390, 270, 601, 41));
        JobTitle->setFont(font);
        JobTitle->setStyleSheet(QString::fromUtf8("font-size: 24px; font-family: Inter; color: white;"));
        Name = new QLabel(centralwidget);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(390, 150, 601, 91));
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("font-size: 48px; font-family: Inter; color: white;"));
        PFP = new QLabel(centralwidget);
        PFP->setObjectName("PFP");
        PFP->setGeometry(QRect(40, 140, 300, 300));
        PFP->setMinimumSize(QSize(199, 199));
        PFP->setMaximumSize(QSize(300, 300));
        PFP->setAutoFillBackground(false);
        PFP->setScaledContents(true);
        email = new QLabel(centralwidget);
        email->setObjectName("email");
        email->setGeometry(QRect(390, 460, 601, 41));
        email->setFont(font);
        email->setStyleSheet(QString::fromUtf8("font-size: 24px; font-family: Inter; color: white;"));
        location = new QLabel(centralwidget);
        location->setObjectName("location");
        location->setGeometry(QRect(390, 390, 601, 41));
        location->setFont(font);
        location->setStyleSheet(QString::fromUtf8("font-size: 24px; font-family: Inter; color: white;"));
        navBackground = new QFrame(centralwidget);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        NavButton_2 = new QVBoxLayout();
        NavButton_2->setObjectName("NavButton_2");
        NavButton_2->setSizeConstraint(QLayout::SetMaximumSize);
        profileButton_2 = new QPushButton(layoutWidget);
        profileButton_2->setObjectName("profileButton_2");
        profileButton_2->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_2->addWidget(profileButton_2);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName("line_2");
        line_2->setEnabled(true);
        line_2->setMinimumSize(QSize(200, 5));
        line_2->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(15);
        line_2->setMidLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        NavButton_2->addWidget(line_2);


        horizontalLayout_2->addLayout(NavButton_2);

        NavButton_9 = new QVBoxLayout();
        NavButton_9->setObjectName("NavButton_9");
        NavButton_9->setSizeConstraint(QLayout::SetMaximumSize);
        assignButton_2 = new QPushButton(layoutWidget);
        assignButton_2->setObjectName("assignButton_2");
        assignButton_2->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_9->addWidget(assignButton_2);

        line_10 = new QFrame(layoutWidget);
        line_10->setObjectName("line_10");
        line_10->setEnabled(true);
        line_10->setMinimumSize(QSize(200, 5));
        line_10->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setLineWidth(15);
        line_10->setMidLineWidth(6);
        line_10->setFrameShape(QFrame::HLine);

        NavButton_9->addWidget(line_10);


        horizontalLayout_2->addLayout(NavButton_9);

        NavButton_10 = new QVBoxLayout();
        NavButton_10->setObjectName("NavButton_10");
        NavButton_10->setSizeConstraint(QLayout::SetMaximumSize);
        managementButton_2 = new QPushButton(layoutWidget);
        managementButton_2->setObjectName("managementButton_2");
        managementButton_2->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_10->addWidget(managementButton_2);

        line_11 = new QFrame(layoutWidget);
        line_11->setObjectName("line_11");
        line_11->setEnabled(true);
        line_11->setMinimumSize(QSize(200, 5));
        line_11->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_11->setFrameShadow(QFrame::Plain);
        line_11->setLineWidth(15);
        line_11->setMidLineWidth(6);
        line_11->setFrameShape(QFrame::HLine);

        NavButton_10->addWidget(line_11);


        horizontalLayout_2->addLayout(NavButton_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        NavButton_11 = new QVBoxLayout();
        NavButton_11->setObjectName("NavButton_11");
        NavButton_11->setSizeConstraint(QLayout::SetMaximumSize);
        logoutButton_2 = new QPushButton(layoutWidget);
        logoutButton_2->setObjectName("logoutButton_2");
        logoutButton_2->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_11->addWidget(logoutButton_2);

        line_12 = new QFrame(layoutWidget);
        line_12->setObjectName("line_12");
        line_12->setEnabled(true);
        line_12->setMinimumSize(QSize(200, 5));
        line_12->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_12->setFrameShadow(QFrame::Plain);
        line_12->setLineWidth(15);
        line_12->setMidLineWidth(6);
        line_12->setFrameShape(QFrame::HLine);

        NavButton_11->addWidget(line_12);


        horizontalLayout_2->addLayout(NavButton_11);

        Background = new QPushButton(centralwidget);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(-10, -20, 1321, 831));
        Background->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        Line1 = new QPushButton(centralwidget);
        Line1->setObjectName("Line1");
        Line1->setGeometry(QRect(390, 250, 611, 5));
        Line1->setMaximumSize(QSize(16777215, 5));
        Line1->setStyleSheet(QString::fromUtf8("background-color:#32ACBE; border:0px;"));
        Line2 = new QPushButton(centralwidget);
        Line2->setObjectName("Line2");
        Line2->setGeometry(QRect(390, 440, 611, 5));
        Line2->setMaximumSize(QSize(16777215, 5));
        Line2->setStyleSheet(QString::fromUtf8("background-color:#32ACBE; border:0px;"));
        accessLevel = new QPushButton(centralwidget);
        accessLevel->setObjectName("accessLevel");
        accessLevel->setGeometry(QRect(1150, 110, 100, 100));
        accessLevel->setMinimumSize(QSize(100, 100));
        accessLevel->setMaximumSize(QSize(40, 40));
        accessLevel->setAutoFillBackground(false);
        accessLevel->setStyleSheet(QString::fromUtf8("font-size: 60px;font-family: Inter;color: white; font-weight:bold; background-color:#32ACBE; border-radius:50px;"));
        accessLevel->setCheckable(true);
        JobTitle_2 = new QLabel(centralwidget);
        JobTitle_2->setObjectName("JobTitle_2");
        JobTitle_2->setGeometry(QRect(1120, 220, 151, 31));
        JobTitle_2->setFont(font);
        JobTitle_2->setStyleSheet(QString::fromUtf8("color:white; font-size:24px;font-family: Inter;"));
        JobTitle_2->setAlignment(Qt::AlignCenter);
        ProfileViewer->setCentralWidget(centralwidget);
        Background->raise();
        number->raise();
        workHours->raise();
        JobTitle->raise();
        Name->raise();
        PFP->raise();
        email->raise();
        location->raise();
        navBackground->raise();
        layoutWidget->raise();
        Line1->raise();
        Line2->raise();
        accessLevel->raise();
        JobTitle_2->raise();

        retranslateUi(ProfileViewer);

        QMetaObject::connectSlotsByName(ProfileViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ProfileViewer)
    {
        ProfileViewer->setWindowTitle(QCoreApplication::translate("ProfileViewer", "MainWindow", nullptr));
        number->setText(QCoreApplication::translate("ProfileViewer", "021 123 4567", nullptr));
        workHours->setText(QCoreApplication::translate("ProfileViewer", "09:00 - 17:30  UTC", nullptr));
        JobTitle->setText(QCoreApplication::translate("ProfileViewer", "Senior Software Engineer", nullptr));
        Name->setText(QCoreApplication::translate("ProfileViewer", "Greg", nullptr));
        PFP->setText(QString());
        email->setText(QCoreApplication::translate("ProfileViewer", "almightyGreg@gmail.com", nullptr));
        location->setText(QCoreApplication::translate("ProfileViewer", "Washington, DC", nullptr));
        profileButton_2->setText(QCoreApplication::translate("ProfileViewer", "Profile", nullptr));
        assignButton_2->setText(QCoreApplication::translate("ProfileViewer", "Assigned", nullptr));
        managementButton_2->setText(QCoreApplication::translate("ProfileViewer", "Management", nullptr));
        logoutButton_2->setText(QCoreApplication::translate("ProfileViewer", "Logout", nullptr));
        Background->setText(QString());
        Line1->setText(QString());
        Line2->setText(QString());
        accessLevel->setText(QCoreApplication::translate("ProfileViewer", "3", nullptr));
        JobTitle_2->setText(QCoreApplication::translate("ProfileViewer", "Access Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileViewer: public Ui_ProfileViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEVIEWER_H

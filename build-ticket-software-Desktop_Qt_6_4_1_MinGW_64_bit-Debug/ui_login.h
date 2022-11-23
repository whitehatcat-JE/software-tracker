/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QWidget *signInWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *username;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *password;
    QLineEdit *lineEditPassword;
    QPushButton *logInBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(710, 640);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255));"));
        signInWidget = new QWidget(centralwidget);
        signInWidget->setObjectName("signInWidget");
        signInWidget->setGeometry(QRect(220, 230, 251, 161));
        signInWidget->setMinimumSize(QSize(251, 161));
        signInWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        verticalLayout = new QVBoxLayout(signInWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        username = new QLabel(signInWidget);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout->addWidget(username);

        lineEditUsername = new QLineEdit(signInWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        password = new QLabel(signInWidget);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        horizontalLayout_2->addWidget(password);

        lineEditPassword = new QLineEdit(signInWidget);
        lineEditPassword->setObjectName("lineEditPassword");

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        logInBtn = new QPushButton(signInWidget);
        logInBtn->setObjectName("logInBtn");
        logInBtn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));

        verticalLayout->addWidget(logInBtn);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 710, 22));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        username->setText(QCoreApplication::translate("Login", "Username", nullptr));
        password->setText(QCoreApplication::translate("Login", "Password ", nullptr));
        logInBtn->setText(QCoreApplication::translate("Login", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

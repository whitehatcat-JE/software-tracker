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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QWidget *signInWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *logInBtn;
    QPushButton *Background;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(1300, 800);
        Login->setMinimumSize(QSize(1300, 800));
        Login->setMaximumSize(QSize(1300, 800));
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        signInWidget = new QWidget(centralwidget);
        signInWidget->setObjectName("signInWidget");
        signInWidget->setGeometry(QRect(360, 350, 611, 211));
        signInWidget->setMinimumSize(QSize(500, 161));
        signInWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        verticalLayout = new QVBoxLayout(signInWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        line_2 = new QFrame(signInWidget);
        line_2->setObjectName("line_2");
        line_2->setEnabled(true);
        line_2->setMinimumSize(QSize(200, 5));
        line_2->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(15);
        line_2->setMidLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        horizontalLayout_4->addWidget(line_2);

        line = new QFrame(signInWidget);
        line->setObjectName("line");
        line->setEnabled(true);
        line->setMinimumSize(QSize(0, 5));
        line->setMaximumSize(QSize(50, 16777215));
        line->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(15);
        line->setMidLineWidth(6);
        line->setFrameShape(QFrame::HLine);

        horizontalLayout_4->addWidget(line);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditUsername = new QLineEdit(signInWidget);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setMinimumSize(QSize(250, 0));
        lineEditUsername->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:#010511; border:none; padding:5px; border-radius:2px;"));

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEditPassword = new QLineEdit(signInWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setMinimumSize(QSize(550, 0));
        lineEditPassword->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color:#010511; border:none; padding:5px; border-radius:2px;"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        logInBtn = new QPushButton(signInWidget);
        logInBtn->setObjectName("logInBtn");
        logInBtn->setMaximumSize(QSize(200, 16777215));
        logInBtn->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; padding:5px;"));

        horizontalLayout_3->addWidget(logInBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        Background = new QPushButton(centralwidget);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(-50, -60, 1391, 881));
        Background->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 170, 851, 101));
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("font-size: 86px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 260, 571, 71));
        label_2->setMinimumSize(QSize(0, 50));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color:#32ACBE; font-weight:bold; border:none;"));
        label_2->setAlignment(Qt::AlignCenter);
        Login->setCentralWidget(centralwidget);
        Background->raise();
        signInWidget->raise();
        label->raise();
        label_2->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("Login", "Username...", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("Login", "Password...", nullptr));
        logInBtn->setText(QCoreApplication::translate("Login", "Log In", nullptr));
        Background->setText(QString());
        label->setText(QCoreApplication::translate("Login", "Software", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Tracking System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

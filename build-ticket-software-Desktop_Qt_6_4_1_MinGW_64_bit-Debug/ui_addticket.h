/********************************************************************************
** Form generated from reading UI file 'addticket.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTICKET_H
#define UI_ADDTICKET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTicket
{
public:
    QPushButton *backgroundGradient;
    QFrame *navBackground;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *NavButton_2;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QVBoxLayout *NavButton_9;
    QPushButton *pushButton_9;
    QFrame *line_10;
    QVBoxLayout *NavButton_10;
    QPushButton *pushButton_10;
    QFrame *line_11;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *NavButton_11;
    QPushButton *pushButton_11;
    QFrame *line_12;
    QLineEdit *ticketTitle;
    QLabel *date;
    QLineEdit *category;
    QLabel *extraData;
    QTextEdit *details;
    QPushButton *createTicket;
    QPushButton *pushButton_4;
    QPushButton *backButton;

    void setupUi(QWidget *AddTicket)
    {
        if (AddTicket->objectName().isEmpty())
            AddTicket->setObjectName("AddTicket");
        AddTicket->resize(1300, 800);
        AddTicket->setMinimumSize(QSize(1300, 800));
        AddTicket->setMaximumSize(QSize(1300, 800));
        backgroundGradient = new QPushButton(AddTicket);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-30, 20, 1341, 791));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        navBackground = new QFrame(AddTicket);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        layoutWidget = new QWidget(AddTicket);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        NavButton_2 = new QVBoxLayout();
        NavButton_2->setObjectName("NavButton_2");
        NavButton_2->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_2->addWidget(pushButton_2);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName("line_2");
        line_2->setEnabled(true);
        line_2->setMinimumSize(QSize(200, 5));
        line_2->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(15);
        line_2->setMidLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        NavButton_2->addWidget(line_2);


        horizontalLayout_2->addLayout(NavButton_2);

        NavButton_9 = new QVBoxLayout();
        NavButton_9->setObjectName("NavButton_9");
        NavButton_9->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_9->addWidget(pushButton_9);

        line_10 = new QFrame(layoutWidget);
        line_10->setObjectName("line_10");
        line_10->setEnabled(true);
        line_10->setMinimumSize(QSize(200, 5));
        line_10->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setLineWidth(15);
        line_10->setMidLineWidth(6);
        line_10->setFrameShape(QFrame::HLine);

        NavButton_9->addWidget(line_10);


        horizontalLayout_2->addLayout(NavButton_9);

        NavButton_10 = new QVBoxLayout();
        NavButton_10->setObjectName("NavButton_10");
        NavButton_10->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_10->addWidget(pushButton_10);

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
        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_11->addWidget(pushButton_11);

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

        ticketTitle = new QLineEdit(AddTicket);
        ticketTitle->setObjectName("ticketTitle");
        ticketTitle->setGeometry(QRect(80, 140, 1131, 35));
        ticketTitle->setMinimumSize(QSize(0, 35));
        ticketTitle->setFocusPolicy(Qt::ClickFocus);
        ticketTitle->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px;padding-left:5px;"));
        ticketTitle->setClearButtonEnabled(false);
        date = new QLabel(AddTicket);
        date->setObjectName("date");
        date->setGeometry(QRect(80, 200, 231, 31));
        date->setMinimumSize(QSize(0, 0));
        date->setStyleSheet(QString::fromUtf8("font-size: 20px; font-family: Inter;color: #D4F8F6; font-weight:lighter; border:none;"));
        date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        category = new QLineEdit(AddTicket);
        category->setObjectName("category");
        category->setGeometry(QRect(310, 200, 231, 35));
        category->setMinimumSize(QSize(0, 35));
        category->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px;padding-left:5px;"));
        category->setAlignment(Qt::AlignCenter);
        category->setDragEnabled(false);
        category->setClearButtonEnabled(false);
        extraData = new QLabel(AddTicket);
        extraData->setObjectName("extraData");
        extraData->setGeometry(QRect(550, 200, 661, 31));
        extraData->setMinimumSize(QSize(0, 0));
        extraData->setStyleSheet(QString::fromUtf8("font-size: 20px; font-family: Inter;color: #D4F8F6; font-weight:lighter; border:none;"));
        extraData->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        details = new QTextEdit(AddTicket);
        details->setObjectName("details");
        details->setGeometry(QRect(80, 260, 1131, 441));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(details->sizePolicy().hasHeightForWidth());
        details->setSizePolicy(sizePolicy);
        details->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; border:5px solid white;"));
        details->setFrameShape(QFrame::Box);
        details->setFrameShadow(QFrame::Sunken);
        details->setReadOnly(false);
        details->setAcceptRichText(false);
        createTicket = new QPushButton(AddTicket);
        createTicket->setObjectName("createTicket");
        createTicket->setGeometry(QRect(460, 720, 321, 41));
        createTicket->setMinimumSize(QSize(200, 35));
        createTicket->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px;"));
        pushButton_4 = new QPushButton(AddTicket);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(80, 720, 101, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("border:none; background-color:transparent;font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Images/placeholderProfileIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(30, 30));
        backButton = new QPushButton(AddTicket);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(80, 70, 571, 41));
        backButton->setMinimumSize(QSize(200, 35));
        backButton->setStyleSheet(QString::fromUtf8("font-size: 50px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:transparent; text-align:left;"));

        retranslateUi(AddTicket);

        QMetaObject::connectSlotsByName(AddTicket);
    } // setupUi

    void retranslateUi(QWidget *AddTicket)
    {
        AddTicket->setWindowTitle(QCoreApplication::translate("AddTicket", "Form", nullptr));
        backgroundGradient->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("AddTicket", "Profile", nullptr));
        pushButton_9->setText(QCoreApplication::translate("AddTicket", "Assigned", nullptr));
        pushButton_10->setText(QCoreApplication::translate("AddTicket", "Management", nullptr));
        pushButton_11->setText(QCoreApplication::translate("AddTicket", "Logout", nullptr));
        ticketTitle->setInputMask(QString());
        ticketTitle->setText(QString());
        ticketTitle->setPlaceholderText(QCoreApplication::translate("AddTicket", "New ticket title...", nullptr));
        date->setText(QCoreApplication::translate("AddTicket", "Created on: 1/1/1982 - ", nullptr));
        category->setInputMask(QString());
        category->setText(QString());
        category->setPlaceholderText(QCoreApplication::translate("AddTicket", "Category...", nullptr));
        extraData->setText(QCoreApplication::translate("AddTicket", "- Untitled MMO - Unresolved", nullptr));
        details->setMarkdown(QCoreApplication::translate("AddTicket", "**Description:**\n"
"\n"
"\n"
"\n"
"**Steps to reproduce:**\n"
"\n"
"\n"
"\n"
"**Thoughts:**\n"
"\n"
"\n"
"", nullptr));
        details->setHtml(QCoreApplication::translate("AddTicket", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:24px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24px; font-weight:700;\">Description:</span><span style=\" font-size:24px;\"><br /><br /><br /><br /></span><span style=\" font-size:24px; font-weight:700;\">Steps to reproduce:</span><span style=\" font-size:24px;\"><br /><br /><br /><br /></span><span style=\" font-size:24px; font-weight:700;\">Thoughts:</span><span style=\" font-size:24px;\"><br /></span></p></body></html>", nullptr));
        createTicket->setText(QCoreApplication::translate("AddTicket", "Create Ticket", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AddTicket", " Greg", nullptr));
        backButton->setText(QCoreApplication::translate("AddTicket", "\342\227\204 Untitled MMO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTicket: public Ui_AddTicket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTICKET_H

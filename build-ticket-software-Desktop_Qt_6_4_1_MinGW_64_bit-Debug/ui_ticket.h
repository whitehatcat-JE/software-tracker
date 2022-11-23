/********************************************************************************
** Form generated from reading UI file 'ticket.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKET_H
#define UI_TICKET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ticket
{
public:
    QPushButton *backgroundGradient;
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
    QFrame *navBackground;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *titleText;
    QLabel *detailsText;
    QFrame *line_2;
    QTextBrowser *descriptionText;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *assignSelfButton;
    QPushButton *assignGroupButton;
    QPushButton *assignUserButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *archiveButton;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *postEntryText;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *postButton;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *posts;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_14;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_15;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Ticket)
    {
        if (Ticket->objectName().isEmpty())
            Ticket->setObjectName("Ticket");
        Ticket->resize(1300, 800);
        Ticket->setMinimumSize(QSize(1300, 800));
        Ticket->setMaximumSize(QSize(1300, 800));
        backgroundGradient = new QPushButton(Ticket);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-10, 20, 1351, 811));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(Ticket);
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
        assignButton = new QPushButton(layoutWidget);
        assignButton->setObjectName("assignButton");
        assignButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_6->addWidget(assignButton);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName("line_7");
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

        navBackground = new QFrame(Ticket);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        assignedItems = new QScrollArea(Ticket);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(0, 40, 1301, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories = new QWidget();
        assignmentCategories->setObjectName("assignmentCategories");
        assignmentCategories->setGeometry(QRect(0, 0, 1299, 759));
        verticalLayout_2 = new QVBoxLayout(assignmentCategories);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        titleText = new QLabel(assignmentCategories);
        titleText->setObjectName("titleText");
        titleText->setMinimumSize(QSize(0, 0));
        titleText->setStyleSheet(QString::fromUtf8("font-size: 36px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; padding-top:20px; padding-bottom:5px;"));

        verticalLayout_5->addWidget(titleText);

        detailsText = new QLabel(assignmentCategories);
        detailsText->setObjectName("detailsText");
        detailsText->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px;"));

        verticalLayout_5->addWidget(detailsText);

        line_2 = new QFrame(assignmentCategories);
        line_2->setObjectName("line_2");
        line_2->setEnabled(true);
        line_2->setMinimumSize(QSize(1000, 5));
        line_2->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(15);
        line_2->setMidLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_5->addWidget(line_2);

        descriptionText = new QTextBrowser(assignmentCategories);
        descriptionText->setObjectName("descriptionText");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(descriptionText->sizePolicy().hasHeightForWidth());
        descriptionText->setSizePolicy(sizePolicy);
        descriptionText->setMinimumSize(QSize(0, 300));
        descriptionText->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:transparent;"));
        descriptionText->setFrameShape(QFrame::NoFrame);
        descriptionText->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(descriptionText);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 10, -1, 10);
        assignSelfButton = new QPushButton(assignmentCategories);
        assignSelfButton->setObjectName("assignSelfButton");
        assignSelfButton->setMinimumSize(QSize(200, 35));
        assignSelfButton->setMaximumSize(QSize(200, 16777215));
        assignSelfButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px; margin-right:10px;"));

        horizontalLayout_2->addWidget(assignSelfButton);

        assignGroupButton = new QPushButton(assignmentCategories);
        assignGroupButton->setObjectName("assignGroupButton");
        assignGroupButton->setMinimumSize(QSize(200, 35));
        assignGroupButton->setMaximumSize(QSize(200, 16777215));
        assignGroupButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px; margin-right:10px;"));

        horizontalLayout_2->addWidget(assignGroupButton);

        assignUserButton = new QPushButton(assignmentCategories);
        assignUserButton->setObjectName("assignUserButton");
        assignUserButton->setMinimumSize(QSize(200, 35));
        assignUserButton->setMaximumSize(QSize(200, 16777215));
        assignUserButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px;"));

        horizontalLayout_2->addWidget(assignUserButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        archiveButton = new QPushButton(assignmentCategories);
        archiveButton->setObjectName("archiveButton");
        archiveButton->setMinimumSize(QSize(200, 35));
        archiveButton->setMaximumSize(QSize(200, 16777215));
        archiveButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px;"));
        archiveButton->setCheckable(true);

        horizontalLayout_2->addWidget(archiveButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        line_3 = new QFrame(assignmentCategories);
        line_3->setObjectName("line_3");
        line_3->setEnabled(true);
        line_3->setMinimumSize(QSize(1000, 5));
        line_3->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(15);
        line_3->setMidLineWidth(6);
        line_3->setFrameShape(QFrame::HLine);

        verticalLayout_5->addWidget(line_3);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_2);

        postEntryText = new QTextEdit(assignmentCategories);
        postEntryText->setObjectName("postEntryText");
        sizePolicy.setHeightForWidth(postEntryText->sizePolicy().hasHeightForWidth());
        postEntryText->setSizePolicy(sizePolicy);
        postEntryText->setMaximumSize(QSize(16777215, 100));
        postEntryText->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; background-color:white; border:0px;"));
        postEntryText->setFrameShadow(QFrame::Sunken);
        postEntryText->setReadOnly(false);
        postEntryText->setAcceptRichText(false);

        verticalLayout_5->addWidget(postEntryText);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 10, -1, 10);
        postButton = new QPushButton(assignmentCategories);
        postButton->setObjectName("postButton");
        postButton->setMinimumSize(QSize(100, 35));
        postButton->setMaximumSize(QSize(100, 16777215));
        postButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px; margin-right:10px;"));

        horizontalLayout_4->addWidget(postButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        posts = new QVBoxLayout();
        posts->setObjectName("posts");
        posts->setContentsMargins(-1, -1, -1, 10);

        verticalLayout_5->addLayout(posts);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton_10 = new QPushButton(assignmentCategories);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setLayoutDirection(Qt::RightToLeft);
        pushButton_10->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Images/placeholderProfileIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon);
        pushButton_10->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(pushButton_10);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        pushButton_13 = new QPushButton(assignmentCategories);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setLayoutDirection(Qt::RightToLeft);
        pushButton_13->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        pushButton_13->setIcon(icon);
        pushButton_13->setIconSize(QSize(25, 25));

        horizontalLayout_8->addWidget(pushButton_13);

        horizontalSpacer_12 = new QSpacerItem(5, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);

        pushButton_14 = new QPushButton(assignmentCategories);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setLayoutDirection(Qt::RightToLeft);
        pushButton_14->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        pushButton_14->setIcon(icon);
        pushButton_14->setIconSize(QSize(25, 25));

        horizontalLayout_9->addWidget(pushButton_14);

        horizontalSpacer_14 = new QSpacerItem(5, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        pushButton_15 = new QPushButton(assignmentCategories);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setLayoutDirection(Qt::RightToLeft);
        pushButton_15->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        pushButton_15->setIcon(icon);
        pushButton_15->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(pushButton_15);

        horizontalSpacer_16 = new QSpacerItem(5, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);


        verticalLayout_4->addLayout(horizontalLayout_10);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_3);

        assignedItems->setWidget(assignmentCategories);
        backgroundGradient->raise();
        navBackground->raise();
        layoutWidget->raise();
        assignedItems->raise();

        retranslateUi(Ticket);

        QMetaObject::connectSlotsByName(Ticket);
    } // setupUi

    void retranslateUi(QWidget *Ticket)
    {
        Ticket->setWindowTitle(QCoreApplication::translate("Ticket", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("Ticket", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("Ticket", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("Ticket", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("Ticket", "Logout", nullptr));
        titleText->setText(QCoreApplication::translate("Ticket", "Jumping crashes game", nullptr));
        detailsText->setText(QCoreApplication::translate("Ticket", "Created on: 8/12/22 - Physics System - Untitled MMO - Actively Working On", nullptr));
        descriptionText->setHtml(QCoreApplication::translate("Ticket", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:24px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24px;\">Description:<br />When in singularity point, if you jump while on a moving platform, game instantly crashes and the user\342\200\231s save is corrupted.<br /><br />Steps to reproduce:<br />Go to the moving platform next to the arcade in singularity point.<br />Jump.<br /><br />Thoughts:<br />Major problem, since the moving platforms will be needed for later parkour sections in singularity point.</span></p></body></html>", nullptr));
        assignSelfButton->setText(QCoreApplication::translate("Ticket", "Self-Assign", nullptr));
        assignGroupButton->setText(QCoreApplication::translate("Ticket", "Assign Group", nullptr));
        assignUserButton->setText(QCoreApplication::translate("Ticket", "Assign User", nullptr));
        archiveButton->setText(QCoreApplication::translate("Ticket", "Close Ticket", nullptr));
        postEntryText->setMarkdown(QString());
        postEntryText->setHtml(QCoreApplication::translate("Ticket", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:24px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        postEntryText->setPlaceholderText(QCoreApplication::translate("Ticket", "Enter post...  ", nullptr));
        postButton->setText(QCoreApplication::translate("Ticket", "Post", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Ticket", "Greg ", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Ticket", "Greg ", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Ticket", "Greg ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Ticket", "Greg ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ticket: public Ui_Ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKET_H

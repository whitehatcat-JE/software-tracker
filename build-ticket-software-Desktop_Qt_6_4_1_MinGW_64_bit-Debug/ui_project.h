/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Project
{
public:
    QFrame *navBackground;
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
    QScrollArea *assignedItems;
    QWidget *assignmentCategories;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *title;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *detailsButton_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QPushButton *archiveButton;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *details;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *detailsButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEditPassword;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *createTicketButton;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *ticketList;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Project)
    {
        if (Project->objectName().isEmpty())
            Project->setObjectName("Project");
        Project->resize(1300, 800);
        Project->setMinimumSize(QSize(1300, 800));
        Project->setMaximumSize(QSize(1300, 800));
        navBackground = new QFrame(Project);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        backgroundGradient = new QPushButton(Project);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-10, 20, 1341, 781));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(Project);
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

        assignedItems = new QScrollArea(Project);
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
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, 25, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        title = new QLineEdit(assignmentCategories);
        title->setObjectName("title");
        title->setStyleSheet(QString::fromUtf8("font-size: 72px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:transparent;"));
        title->setReadOnly(true);

        verticalLayout_4->addWidget(title);

        line_2 = new QFrame(assignmentCategories);
        line_2->setObjectName("line_2");
        line_2->setEnabled(true);
        line_2->setMinimumSize(QSize(200, 5));
        line_2->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(15);
        line_2->setMidLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_4->addWidget(line_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_2);

        detailsButton_2 = new QPushButton(assignmentCategories);
        detailsButton_2->setObjectName("detailsButton_2");
        detailsButton_2->setStyleSheet(QString::fromUtf8("border:none; background-color:transparent;font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-style:italic;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/Images/editIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/Image/Images/editEnabledIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        detailsButton_2->setIcon(icon);
        detailsButton_2->setIconSize(QSize(50, 50));
        detailsButton_2->setCheckable(true);
        detailsButton_2->setFlat(false);

        verticalLayout_5->addWidget(detailsButton_2);

        line_3 = new QFrame(assignmentCategories);
        line_3->setObjectName("line_3");
        line_3->setEnabled(true);
        line_3->setMinimumSize(QSize(5, 5));
        line_3->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(15);
        line_3->setMidLineWidth(6);
        line_3->setFrameShape(QFrame::HLine);

        verticalLayout_5->addWidget(line_3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_3);

        archiveButton = new QPushButton(assignmentCategories);
        archiveButton->setObjectName("archiveButton");
        archiveButton->setStyleSheet(QString::fromUtf8("border:none; background-color:transparent;font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-style:italic;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/Images/archiveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        archiveButton->setIcon(icon1);
        archiveButton->setIconSize(QSize(50, 50));
        archiveButton->setCheckable(true);
        archiveButton->setFlat(false);

        verticalLayout_6->addWidget(archiveButton);

        line_4 = new QFrame(assignmentCategories);
        line_4->setObjectName("line_4");
        line_4->setEnabled(true);
        line_4->setMinimumSize(QSize(5, 5));
        line_4->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(15);
        line_4->setMidLineWidth(6);
        line_4->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_4);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        details = new QTextEdit(assignmentCategories);
        details->setObjectName("details");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(details->sizePolicy().hasHeightForWidth());
        details->setSizePolicy(sizePolicy);
        details->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:transparent; border:0px;"));
        details->setFrameShadow(QFrame::Sunken);
        details->setReadOnly(true);
        details->setAcceptRichText(false);

        horizontalLayout_5->addWidget(details);

        horizontalSpacer_3 = new QSpacerItem(225, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        detailsButton = new QPushButton(assignmentCategories);
        detailsButton->setObjectName("detailsButton");
        detailsButton->setStyleSheet(QString::fromUtf8("border:none; background-color:transparent;font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-style:italic;"));
        detailsButton->setIcon(icon);
        detailsButton->setIconSize(QSize(30, 30));
        detailsButton->setCheckable(true);
        detailsButton->setFlat(false);

        horizontalLayout_6->addWidget(detailsButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(assignmentCategories);
        label_6->setObjectName("label_6");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMaximumSize(QSize(35, 35));
        label_6->setStyleSheet(QString::fromUtf8("background-color:white;"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Image/Images/searchIcon.png")));
        label_6->setScaledContents(true);
        label_6->setMargin(5);

        horizontalLayout_7->addWidget(label_6);

        lineEditPassword = new QLineEdit(assignmentCategories);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setMinimumSize(QSize(0, 35));
        lineEditPassword->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #040F65; font-weight:lighter; padding-right:5px; border:0px;\n"
""));
        lineEditPassword->setClearButtonEnabled(false);

        horizontalLayout_7->addWidget(lineEditPassword);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        createTicketButton = new QPushButton(assignmentCategories);
        createTicketButton->setObjectName("createTicketButton");
        createTicketButton->setMinimumSize(QSize(200, 35));
        createTicketButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px;"));

        horizontalLayout_7->addWidget(createTicketButton);

        horizontalSpacer_5 = new QSpacerItem(400, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        ticketList = new QVBoxLayout();
        ticketList->setObjectName("ticketList");

        verticalLayout_2->addLayout(ticketList);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        assignedItems->setWidget(assignmentCategories);
        backgroundGradient->raise();
        navBackground->raise();
        layoutWidget->raise();
        assignedItems->raise();

        retranslateUi(Project);

        QMetaObject::connectSlotsByName(Project);
    } // setupUi

    void retranslateUi(QWidget *Project)
    {
        Project->setWindowTitle(QCoreApplication::translate("Project", "Form", nullptr));
        backgroundGradient->setText(QString());
        profileButton->setText(QCoreApplication::translate("Project", "Profile", nullptr));
        assignButton->setText(QCoreApplication::translate("Project", "Assigned", nullptr));
        managementButton->setText(QCoreApplication::translate("Project", "Management", nullptr));
        logoutButton->setText(QCoreApplication::translate("Project", "Logout", nullptr));
        title->setText(QCoreApplication::translate("Project", "Untitled MMO", nullptr));
        detailsButton_2->setText(QString());
        archiveButton->setText(QString());
        details->setHtml(QCoreApplication::translate("Project", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Inter'; font-size:24px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24px;\">Our upcoming MMORPG, set in the same universe as the rest of the Quantum Duck series. It\342\200\231ll feature several explorable dimensions, and have procedually generated enemies, using our new cardinal balancing A.I to auto-create an effective game balance. The current release date is set in late 2025, but if we can get it done earlier, we\342\200\231ll have more available time to spend on the in-game custom magic system.</span></p></body></html>", nullptr));
        detailsButton->setText(QString());
        label_6->setText(QString());
        lineEditPassword->setInputMask(QString());
        lineEditPassword->setText(QString());
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("Project", "Search tickets...", nullptr));
        createTicketButton->setText(QCoreApplication::translate("Project", "Create Ticket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Project: public Ui_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H

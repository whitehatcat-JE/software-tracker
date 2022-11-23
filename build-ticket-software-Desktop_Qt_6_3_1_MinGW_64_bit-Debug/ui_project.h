/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *pushButton;
    QFrame *line;
    QVBoxLayout *NavButton_6;
    QPushButton *pushButton_6;
    QFrame *line_7;
    QVBoxLayout *NavButton_7;
    QPushButton *pushButton_7;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *NavButton_8;
    QPushButton *pushButton_8;
    QFrame *line_9;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QFrame *line_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Project)
    {
        if (Project->objectName().isEmpty())
            Project->setObjectName(QString::fromUtf8("Project"));
        Project->resize(1300, 800);
        Project->setMinimumSize(QSize(1300, 800));
        Project->setMaximumSize(QSize(1300, 800));
        navBackground = new QFrame(Project);
        navBackground->setObjectName(QString::fromUtf8("navBackground"));
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(0, 0, 1301, 40));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        backgroundGradient = new QPushButton(Project);
        backgroundGradient->setObjectName(QString::fromUtf8("backgroundGradient"));
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-10, 20, 1341, 781));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(Project);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NavButton = new QVBoxLayout();
        NavButton->setObjectName(QString::fromUtf8("NavButton"));
        NavButton->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton->addWidget(pushButton);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
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
        NavButton_6->setObjectName(QString::fromUtf8("NavButton_6"));
        NavButton_6->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_6->addWidget(pushButton_6);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
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
        NavButton_7->setObjectName(QString::fromUtf8("NavButton_7"));
        NavButton_7->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_7->addWidget(pushButton_7);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
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
        NavButton_8->setObjectName(QString::fromUtf8("NavButton_8"));
        NavButton_8->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_8->addWidget(pushButton_8);

        line_9 = new QFrame(layoutWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
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
        assignedItems->setObjectName(QString::fromUtf8("assignedItems"));
        assignedItems->setGeometry(QRect(0, 40, 1301, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories = new QWidget();
        assignmentCategories->setObjectName(QString::fromUtf8("assignmentCategories"));
        assignmentCategories->setGeometry(QRect(0, 0, 1299, 759));
        verticalLayout_2 = new QVBoxLayout(assignmentCategories);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 5, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(assignmentCategories);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 100));
        label->setStyleSheet(QString::fromUtf8("font-size: 72px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        line_2 = new QFrame(assignmentCategories);
        line_2->setObjectName(QString::fromUtf8("line_2"));
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
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_2);

        label_2 = new QLabel(assignmentCategories);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setPixmap(QPixmap(QString::fromUtf8("Images/editIcon.png")));
        label_2->setScaledContents(true);

        verticalLayout_5->addWidget(label_2);

        line_3 = new QFrame(assignmentCategories);
        line_3->setObjectName(QString::fromUtf8("line_3"));
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
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_6->addItem(verticalSpacer_3);

        label_3 = new QLabel(assignmentCategories);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(50, 50));
        label_3->setPixmap(QPixmap(QString::fromUtf8("Images/editIcon.png")));
        label_3->setScaledContents(true);

        verticalLayout_6->addWidget(label_3);

        line_4 = new QFrame(assignmentCategories);
        line_4->setObjectName(QString::fromUtf8("line_4"));
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout_3);

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
        pushButton->setText(QCoreApplication::translate("Project", "Profile", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Project", "Assigned", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Project", "Management", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Project", "Logout", nullptr));
        label->setText(QCoreApplication::translate("Project", "Untitled MMO", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Project: public Ui_Project {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H

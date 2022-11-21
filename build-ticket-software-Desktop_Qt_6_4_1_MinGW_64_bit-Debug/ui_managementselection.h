/********************************************************************************
** Form generated from reading UI file 'managementselection.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTSELECTION_H
#define UI_MANAGEMENTSELECTION_H

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

class Ui_ManagementSelection
{
public:
    QFrame *navBackground;
    QScrollArea *assignedItems;
    QWidget *assignmentCategories_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *pageFrame_2;
    QLabel *title;
    QSpacerItem *verticalSpacer_6;
    QPushButton *backgroundGradient;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *NavButton_4;
    QPushButton *pushButton_4;
    QFrame *line_4;
    QVBoxLayout *NavButton_15;
    QPushButton *pushButton_15;
    QFrame *line_16;
    QVBoxLayout *NavButton_16;
    QPushButton *pushButton_16;
    QFrame *line_17;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *NavButton_17;
    QPushButton *pushButton_17;
    QFrame *line_18;

    void setupUi(QWidget *ManagementSelection)
    {
        if (ManagementSelection->objectName().isEmpty())
            ManagementSelection->setObjectName("ManagementSelection");
        ManagementSelection->resize(1300, 800);
        ManagementSelection->setMinimumSize(QSize(1300, 800));
        ManagementSelection->setMaximumSize(QSize(1300, 800));
        navBackground = new QFrame(ManagementSelection);
        navBackground->setObjectName("navBackground");
        navBackground->setEnabled(true);
        navBackground->setGeometry(QRect(-10, -10, 1321, 51));
        navBackground->setMinimumSize(QSize(0, 40));
        navBackground->setStyleSheet(QString::fromUtf8("background-color:#010511;"));
        navBackground->setFrameShadow(QFrame::Plain);
        navBackground->setLineWidth(500);
        navBackground->setFrameShape(QFrame::HLine);
        assignedItems = new QScrollArea(ManagementSelection);
        assignedItems->setObjectName("assignedItems");
        assignedItems->setGeometry(QRect(-10, 40, 1321, 761));
        assignedItems->setStyleSheet(QString::fromUtf8("QScrollArea { background: transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; }\n"
"QScrollArea > QWidget > QScrollBar { background: palette(base); }"));
        assignedItems->setFrameShadow(QFrame::Raised);
        assignedItems->setLineWidth(0);
        assignedItems->setWidgetResizable(true);
        assignmentCategories_2 = new QWidget();
        assignmentCategories_2->setObjectName("assignmentCategories_2");
        assignmentCategories_2->setGeometry(QRect(0, 0, 1319, 759));
        verticalLayout_3 = new QVBoxLayout(assignmentCategories_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pageFrame_2 = new QVBoxLayout();
        pageFrame_2->setObjectName("pageFrame_2");
        title = new QLabel(assignmentCategories_2);
        title->setObjectName("title");
        title->setMinimumSize(QSize(0, 75));
        title->setMaximumSize(QSize(16777215, 100));
        title->setStyleSheet(QString::fromUtf8("font-size: 48px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; padding-left:5px;"));
        title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        pageFrame_2->addWidget(title);


        verticalLayout_3->addLayout(pageFrame_2);

        verticalSpacer_6 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        assignedItems->setWidget(assignmentCategories_2);
        backgroundGradient = new QPushButton(ManagementSelection);
        backgroundGradient->setObjectName("backgroundGradient");
        backgroundGradient->setEnabled(false);
        backgroundGradient->setGeometry(QRect(-30, 10, 1341, 791));
        backgroundGradient->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255))"));
        backgroundGradient->setFlat(false);
        layoutWidget = new QWidget(ManagementSelection);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1301, 42));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        NavButton_4 = new QVBoxLayout();
        NavButton_4->setObjectName("NavButton_4");
        NavButton_4->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_4->addWidget(pushButton_4);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName("line_4");
        line_4->setEnabled(true);
        line_4->setMinimumSize(QSize(200, 5));
        line_4->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(15);
        line_4->setMidLineWidth(6);
        line_4->setFrameShape(QFrame::HLine);

        NavButton_4->addWidget(line_4);


        horizontalLayout_4->addLayout(NavButton_4);

        NavButton_15 = new QVBoxLayout();
        NavButton_15->setObjectName("NavButton_15");
        NavButton_15->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_15 = new QPushButton(layoutWidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_15->addWidget(pushButton_15);

        line_16 = new QFrame(layoutWidget);
        line_16->setObjectName("line_16");
        line_16->setEnabled(true);
        line_16->setMinimumSize(QSize(200, 5));
        line_16->setStyleSheet(QString::fromUtf8("color:#32ACBE;"));
        line_16->setFrameShadow(QFrame::Plain);
        line_16->setLineWidth(15);
        line_16->setMidLineWidth(6);
        line_16->setFrameShape(QFrame::HLine);

        NavButton_15->addWidget(line_16);


        horizontalLayout_4->addLayout(NavButton_15);

        NavButton_16 = new QVBoxLayout();
        NavButton_16->setObjectName("NavButton_16");
        NavButton_16->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_16 = new QPushButton(layoutWidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: #32ACBE; font-weight:bold; border:none;"));

        NavButton_16->addWidget(pushButton_16);

        line_17 = new QFrame(layoutWidget);
        line_17->setObjectName("line_17");
        line_17->setEnabled(true);
        line_17->setMinimumSize(QSize(200, 5));
        line_17->setStyleSheet(QString::fromUtf8("color:#05448A;"));
        line_17->setFrameShadow(QFrame::Plain);
        line_17->setLineWidth(15);
        line_17->setMidLineWidth(6);
        line_17->setFrameShape(QFrame::HLine);

        NavButton_16->addWidget(line_17);


        horizontalLayout_4->addLayout(NavButton_16);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        NavButton_17 = new QVBoxLayout();
        NavButton_17->setObjectName("NavButton_17");
        NavButton_17->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_17 = new QPushButton(layoutWidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setStyleSheet(QString::fromUtf8("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none;"));

        NavButton_17->addWidget(pushButton_17);

        line_18 = new QFrame(layoutWidget);
        line_18->setObjectName("line_18");
        line_18->setEnabled(true);
        line_18->setMinimumSize(QSize(200, 5));
        line_18->setStyleSheet(QString::fromUtf8("color:#CA0736;"));
        line_18->setFrameShadow(QFrame::Plain);
        line_18->setLineWidth(15);
        line_18->setMidLineWidth(6);
        line_18->setFrameShape(QFrame::HLine);

        NavButton_17->addWidget(line_18);


        horizontalLayout_4->addLayout(NavButton_17);

        backgroundGradient->raise();
        navBackground->raise();
        assignedItems->raise();
        layoutWidget->raise();

        retranslateUi(ManagementSelection);

        QMetaObject::connectSlotsByName(ManagementSelection);
    } // setupUi

    void retranslateUi(QWidget *ManagementSelection)
    {
        ManagementSelection->setWindowTitle(QCoreApplication::translate("ManagementSelection", "Form", nullptr));
        title->setText(QCoreApplication::translate("ManagementSelection", "< Groups", nullptr));
        backgroundGradient->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("ManagementSelection", "Profile", nullptr));
        pushButton_15->setText(QCoreApplication::translate("ManagementSelection", "Assigned", nullptr));
        pushButton_16->setText(QCoreApplication::translate("ManagementSelection", "Management", nullptr));
        pushButton_17->setText(QCoreApplication::translate("ManagementSelection", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagementSelection: public Ui_ManagementSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTSELECTION_H

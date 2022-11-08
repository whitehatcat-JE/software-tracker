#include "assignments.h"
#include "ui_assignments.h"

Assignments::Assignments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Assignments)
{
    ui->setupUi(this);
}

Assignments::~Assignments()
{
    delete ui;
}

void Assignments::on_ticketsButton_toggled(bool checked)
{
    if (checked == false) {
        ui->ticketsButton->setText("Tickets                                                                                                            ►");
        QObjectList list = ui->assignedItems->widget()->children();
        for (int i = 0; i < list.size(); i++) {
            QString name = list.at(i)->objectName();
            if (name.contains("displayedTicket")) {
                delete list.at(i);
            }
        }
    } else {
        ui->ticketsButton->setText("Tickets                                                                                                            ▼");
        for (int i = 0; i < 8; i++) {
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(i));
            button->setText("Duplication exploit with shopkeeper NPCs");
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");

            QLabel *label = new QLabel("metadata", button);
            label->setText("Created on: 9/12/22 - Physics Engine - Untitled MMO - Actively Working On");
            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
            ui->ticketsLayout->addWidget(button);
        }
    }
}

void Assignments::on_groupsButton_toggled(bool checked)
{
    if (checked == false) {
        ui->groupsButton->setText("Groups                                                                                                            ►");
    } else {
        ui->groupsButton->setText("Groups                                                                                                            ▼");
    }
}


void Assignments::on_projectsButton_toggled(bool checked)
{
    if (checked == false) {
        ui->projectsButton->setText("Projects                                                                                                           ►");
        QObjectList list = ui->assignedItems->widget()->children();
        for (int i = 0; i < list.size(); i++) {
            QString name = list.at(i)->objectName();
            if (name.contains("displayedProject")) {
                delete list.at(i);
            }
        }
    } else {
        ui->projectsButton->setText("Projects                                                                                                           ▼");
        for (int i = 0; i < 8; i++) {
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedProject" + QString::number(i));
            button->setText("Untitled MMO");
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            ui->projectsLayout->addWidget(button);
        }
    }
}


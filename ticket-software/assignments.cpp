#include "assignments.h"
#include "ui_assignments.h"

#include <QDebug>
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
            button->setText("Hello World");
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 36px; font-weight: bold; text-align: left; padding-left: 10px;");
            ui->assignedItems->widget()->layout()->addWidget(button);
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
    } else {
        ui->projectsButton->setText("Projects                                                                                                           ▼");
    }
}


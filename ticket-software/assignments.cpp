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
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
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
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                if (!projects[projectIdx].tickets[ticketIdx].isOpen) { continue; }
                QPushButton *button = new QPushButton(this);
                button->setObjectName("displayedTicket" + QString::number(ticketIdx));
                button->setText(projects[projectIdx].tickets[ticketIdx].title);
                button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
                int projectID = projects[projectIdx].uniqueIdentifier;
                int ticketID = projects[projectIdx].tickets[ticketIdx].creationTime;

                connect(button, &QPushButton::clicked, [this, projectID, ticketID] { openTicket(projectID, ticketID); });
                QLabel *label = new QLabel("metadata", button);
                QString metadataString = "Created on: 9/12/22 - ";
                metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
                metadataString += projects[projectIdx].name + " - ";
                metadataString += projects[projectIdx].tickets[ticketIdx].progress;

                label->setText(metadataString);
                label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
                ui->ticketsLayout->addWidget(button);
            }
        }
    }
}

void Assignments::on_groupsButton_toggled(bool checked)
{
    if (checked == false) {
        ui->groupsButton->setText("Groups                                                                                                            ►");
        QVector<QWidget*> widgets = ui->assignedItems->findChildren<QWidget *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < widgets.size(); widIdx++) {
            if (widgets.at(widIdx)->objectName() == "displayedGroup") { delete widgets.at(widIdx); }
        }
    } else {
        ui->groupsButton->setText("Groups                                                                                                            ▼");
        FileManager myFiles;
        QVector<FileManager::Group> groups = myFiles.loadGroups();
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            QWidget *groupParent = new QWidget();
            groupParent->setObjectName("displayedGroup");
            ui->groupsLayout->addWidget(groupParent);
            QVBoxLayout *layout = new QVBoxLayout(groupParent);
            layout->setContentsMargins(0, 0, 0, 0);
            QPushButton *button = new QPushButton(this);
            button->setText(groups[groupIdx].name);
            button->setStyleSheet("background-color: #010511; color: white; height: 75px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");

            QLabel *label = new QLabel("groupIndicator", button);
            label->setText("►");
            label->setStyleSheet("font-family: Inter; font-size: 24px; text-align: right; margin-left:1208px; font-weight: normal; margin-top:25px;");
            layout->addWidget(button);
        }
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

        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());

        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedProject" + QString::number(projectIdx));
            button->setText(projects[projectIdx].name);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int projectIdentifer = projects[projectIdx].uniqueIdentifier;
            connect(button, &QPushButton::clicked, [this, projectIdentifer] { on_projectButton_triggered(projectIdentifer); });
            ui->projectsLayout->addWidget(button);
        }
    }
}

void Assignments::on_projectButton_triggered(int id) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = id;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Assignments::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Assignments::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Assignments::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Assignments::openTicket(int projectID, int ticketID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 4;
    state.pageData = projectID;
    state.secondaryPageData = ticketID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


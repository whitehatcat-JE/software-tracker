#include "project.h"
#include "ui_project.h"

Project::Project(int projectID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Project)
{

    ui->setupUi(this);

    assignedIdentifier = projectID;

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    int projectIdx = 0;
    for (;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != projectID) { continue;}
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");

            QLabel *label = new QLabel("metadata", button);
            QString metadataString = "Created on: 9/12/22 - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
            metadataString += projects[projectIdx].name + " - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].progress;

            label->setText(metadataString);
            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
            ui->ticketList->addWidget(button);
            displayedTickets.push_back(button);
        }
        break;
    }
    ui->title->setText(projects[projectIdx].name);
    ui->details->setText(projects[projectIdx].description);
}

Project::~Project()
{
    delete ui;
}

void Project::on_lineEditPassword_textChanged(const QString &query)
{
    while (displayedTickets.size() > 0) {
        displayedTickets[0]->deleteLater();
        displayedTickets.pop_front();
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());

    for (int projectIdx = 0;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != assignedIdentifier) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (!projects[projectIdx].tickets[ticketIdx].title.contains(query)) { continue; }
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");

            QLabel *label = new QLabel("metadata", button);
            QString metadataString = "Created on: 9/12/22 - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
            metadataString += projects[projectIdx].name + " - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].progress;

            label->setText(metadataString);
            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
            ui->ticketList->addWidget(button);
            displayedTickets.push_back(button);
        }
        break;
    }
}


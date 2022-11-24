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
            if (!projects[projectIdx].tickets[ticketIdx].isOpen) { continue; }
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
            connect(button, &QPushButton::clicked, [this, ticketIdentifier] { openTicket(ticketIdentifier); });
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
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
        ui->detailsButton->hide();
        ui->detailsButton_2->hide();
        ui->line_3->hide();
    }

    ui->title->setText(projects[projectIdx].name);
    ui->details->setText(projects[projectIdx].description);
}

Project::~Project()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
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
            if (!projects[projectIdx].tickets[ticketIdx].title.contains(query) ||
                    !projects[projectIdx].tickets[ticketIdx].isOpen) { continue; }
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
            connect(button, &QPushButton::clicked, [this, ticketIdentifier] { openTicket(ticketIdentifier); });
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

void Project::on_detailsButton_toggled(bool checked)
{
    if (checked) {
        ui->detailsButton->setText(" Save");
        ui->details->setReadOnly(false);
        ui->details->setStyleSheet("font-size: 24px;font-family: Inter;color: #010511; font-weight:lighter; background-color:white; border:0px;");
    } else {
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
                projects[projectIdx].description = ui->details->toPlainText();
                myFiles.saveProjects(myFiles.compileProjects(projects));
                break;
            }
        }
        ui->detailsButton->setText("");
        ui->details->setReadOnly(true);
        ui->details->setStyleSheet("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:transparent; border:0px;");
    }
}

void Project::on_detailsButton_2_toggled(bool checked)
{
    if (checked) {
        ui->title->setReadOnly(false);
        ui->title->setStyleSheet("font-size: 72px;font-family: Inter;color: #010511; font-weight:bold; background-color:white; border:0px;");
    } else {
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
                projects[projectIdx].name = ui->title->text();
                myFiles.saveProjects(myFiles.compileProjects(projects));
                break;
            }
        }
        ui->title->setReadOnly(true);
        ui->title->setStyleSheet("font-size: 72px;font-family: Inter;color: white; font-weight:bold; background-color:transparent; border:0px;");
    }
}

void Project::openTicket(int ticketID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 4;
    state.pageData = assignedIdentifier;
    state.secondaryPageData = ticketID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_createTicketButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 5;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Project::on_archiveButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 6;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


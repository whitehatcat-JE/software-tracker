#include "addticket.h"
#include "ui_addticket.h"

#include "filemanager.h"

AddTicket::AddTicket(int projectID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTicket)
{
    ui->setupUi(this);
    assignedIdentifier = projectID;

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd/MM/yyyy");
    ui->date->setText("Created on: " + formattedTime + " -");

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::User> users = myFiles.loadUsers();
    int projectIdx = 0;
    for (;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != projectID) { continue;}
        ui->backButton->setText("◄ " + projects[projectIdx].name);
        ui->extraData->setText("- " + projects[projectIdx].name + " - Unresolved");
    }
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == myFiles.loadState().userID) {
            ui->displayedUser->setText(users[userIdx].username);
            ui->displayedUser->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png"));
        }
    }
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
    }
}

AddTicket::~AddTicket()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void AddTicket::on_createTicket_clicked()
{
    if (ui->details->toPlainText().size() == 0 || ui->category->text().size() == 0 || ui->ticketTitle->text().size() == 0) {
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    FileManager::Ticket newTicket;
    newTicket.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    newTicket.description = ui->details->toPlainText();
    newTicket.isOpen = true;
    newTicket.logs = {};

    newTicket.priority = 0;
    newTicket.progress = "Unresolved";
    newTicket.system = ui->category->text();
    newTicket.title = ui->ticketTitle->text();
    newTicket.uniqueIdentifier = myFiles.loadState().userID;

    FileManager::Log initialLog;
    initialLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    initialLog.description = "Ticket created";
    initialLog.isConsole = true;
    initialLog.uniqueIdentifier = 0;

    newTicket.logs.push_back(initialLog);
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
            projects[projectIdx].tickets.append(newTicket);
            myFiles.saveProjects(myFiles.compileProjects(projects));
        }
    }

    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void AddTicket::on_backButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void AddTicket::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void AddTicket::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void AddTicket::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void AddTicket::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

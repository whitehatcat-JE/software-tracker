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
    int projectIdx = 0;
    for (;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != projectID) { continue;}
        ui->title->setText("◄ " + projects[projectIdx].name);
        ui->extraData->setText("- " + projects[projectIdx].name + " - Unresolved");
    }
}

AddTicket::~AddTicket()
{
    delete ui;
}

void AddTicket::on_createTicket_clicked()
{
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    FileManager::Ticket newTicket;
    newTicket.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    newTicket.description = ui->details->toPlainText();
    newTicket.isOpen = true;
    newTicket.logs = {};

    FileManager::Log initialLog;
    initialLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();

}


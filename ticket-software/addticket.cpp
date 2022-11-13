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
    if (ui->details->toPlainText().count() == 0 || ui->category->text().count() == 0 || ui->ticketTitle->text().count() == 0) {
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
    newTicket.uniqueIdentifier = 0;

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
}


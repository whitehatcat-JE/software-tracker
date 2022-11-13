#include "ticket.h"
#include "ui_ticket.h"

Ticket::Ticket(int projectID, int ticketID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);

    IDProject = projectID;
    IDTicket = ticketID;

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                ui->titleText->setText(projects[projectIdx].tickets[ticketIdx].title);
                ui->descriptionText->setText(projects[projectIdx].tickets[ticketIdx].description);

                QDateTime date = QDateTime::fromSecsSinceEpoch(ticketID);
                QString formattedTime = date.toString("dd/MM/yyyy");
                QString details = "Created on: " + formattedTime + " - " +
                        projects[projectIdx].tickets[ticketIdx].system + " - " +
                        projects[projectIdx].name + " - " +
                        projects[projectIdx].tickets[ticketIdx].progress;
                ui->detailsText->setText(details);
                if (!projects[projectIdx].tickets[ticketIdx].isOpen) {
                    ui->archiveButton->setText("Re-open Ticket");
                    ui->archiveButton->setDown(true);
                    ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:rgb(255, 255, 255); border-radius:1px;");
                }
                break;
            }
        }
    }
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::on_archiveButton_toggled(bool checked)
{
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                projects[projectIdx].tickets[ticketIdx].isOpen = !checked;
            }
        }
    }
    myFiles.saveProjects(myFiles.compileProjects(projects));
    if (checked) {
        ui->archiveButton->setText("Re-open Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:rgb(255, 255, 255); border-radius:1px;");
    } else {
        ui->archiveButton->setText("Close Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px;");
    }
}


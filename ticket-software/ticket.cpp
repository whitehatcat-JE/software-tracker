#include "ticket.h"
#include "ui_ticket.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>

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
                QString details = "Created on " + formattedTime + " - " +
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
    reloadLogs();
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::reloadLogs() {
    QVector<QLabel*> list = ui->assignedItems->findChildren<QLabel *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < list.size(); widIdx++) {
        if (list.at(widIdx)->objectName() == "logStuff") { delete list.at(widIdx); }
    }
    QVector<QPushButton*> listB = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < listB.size(); widIdx++) {
        if (listB.at(widIdx)->objectName() == "logStuff") { delete listB.at(widIdx); }
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                for (int logIdx = projects[projectIdx].tickets[ticketIdx].logs.size()-1; logIdx >= 0; logIdx--) {
                    if (projects[projectIdx].tickets[ticketIdx].logs[logIdx].isConsole) {
                        QLabel *logDetails = new QLabel(this);
                        logDetails->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        QDateTime date = QDateTime::fromSecsSinceEpoch(projects[projectIdx].tickets[ticketIdx].logs[logIdx].creationTime);
                        QString formattedTime = date.toString("dd/MM/yyyy");
                        logDetails->setText(projects[projectIdx].tickets[ticketIdx].logs[logIdx].description + " on " + formattedTime);
                        QPushButton *logUser = new QPushButton(this);
                        QPushButton *logUserIcon = new QPushButton(this);
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        logUserIcon->setIconSize(QSize(25, 25));
                        logUser->setText("Greg");
                        logUser->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:#32ACBE; border:0px;height:24px; padding:5px; text-align:right;");
                        logUserIcon->setStyleSheet("height:24px; padding:5px; border:0px; background-color:#32ACBE;");
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        logUserIcon->setMaximumWidth(35);
                        logUserIcon->setIconSize(QSize(25, 25));
                        QHBoxLayout *logInfoLayout = new QHBoxLayout();
                        logInfoLayout->addWidget(logDetails);
                        logInfoLayout->addWidget(logUser);
                        logInfoLayout->addWidget(logUserIcon);
                        ui->posts->addLayout(logInfoLayout);
                        logDetails->setObjectName("logStuff");
                        logUser->setObjectName("logStuff");
                        logUserIcon->setObjectName("logStuff");
                    } else {
                        QLabel *logText = new QLabel(this);
                        logText->setStyleSheet("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        logText->setText(projects[projectIdx].tickets[ticketIdx].logs[logIdx].description);
                        QLabel *logDetails = new QLabel(this);
                        logDetails->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        QDateTime date = QDateTime::fromSecsSinceEpoch(projects[projectIdx].tickets[ticketIdx].logs[logIdx].creationTime);
                        QString formattedTime = date.toString("dd/MM/yyyy");
                        logDetails->setText("Posted on " + formattedTime);
                        QPushButton *logUser = new QPushButton(this);
                        QPushButton *logUserIcon = new QPushButton(this);
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        logUserIcon->setIconSize(QSize(25, 25));
                        logUser->setText("Greg");
                        logUser->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:#32ACBE; border:0px;height:24px; padding:5px; text-align:right;");
                        logUserIcon->setStyleSheet("height:24px; padding:5px; border:0px; background-color:#32ACBE;");
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        logUserIcon->setMaximumWidth(35);
                        logUserIcon->setIconSize(QSize(25, 25));
                        QHBoxLayout *logInfoLayout = new QHBoxLayout();
                        logInfoLayout->addWidget(logDetails);
                        logInfoLayout->addWidget(logUser);
                        logInfoLayout->addWidget(logUserIcon);
                        ui->posts->addWidget(logText);
                        ui->posts->addLayout(logInfoLayout);
                        logText->setObjectName("logStuff");
                        logDetails->setObjectName("logStuff");
                        logUser->setObjectName("logStuff");
                        logUserIcon->setObjectName("logStuff");
                    }
                    QLabel *logSpacing = new QLabel(this);
                    logSpacing->setObjectName("logStuff");
                    logSpacing->setStyleSheet("background-color:transparent; font-size:10px;");
                    ui->posts->addWidget(logSpacing);
                }
            }
        }
    }
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
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        FileManager::Log newLog;
        newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
        newLog.description = "Ticket closed";
        newLog.uniqueIdentifier = 0;
        newLog.isConsole = true;
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                    projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
                }
            }
        }
        myFiles.saveProjects(myFiles.compileProjects(projects));
        ui->archiveButton->setText("Re-open Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:rgb(255, 255, 255); border-radius:1px;");
    } else {
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        FileManager::Log newLog;
        newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
        newLog.description = "Ticket re-opened";
        newLog.uniqueIdentifier = 0;
        newLog.isConsole = true;
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                    projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
                }
            }
        }
        myFiles.saveProjects(myFiles.compileProjects(projects));
        ui->archiveButton->setText("Close Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px;");
    }
    reloadLogs();
}

void Ticket::on_postButton_clicked()
{
    if (ui->postEntryText->toPlainText().size() == 0) {
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    FileManager::Log newLog;
    newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    newLog.description = ui->postEntryText->toPlainText();
    newLog.uniqueIdentifier = 0;
    newLog.isConsole = false;
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
            }
        }
    }
    myFiles.saveProjects(myFiles.compileProjects(projects));
    reloadLogs();
}


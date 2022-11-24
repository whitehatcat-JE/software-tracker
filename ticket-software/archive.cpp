#include "archive.h"
#include "ui_archive.h"

Archive::Archive(int projectID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
    IDProject = projectID;

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());


    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        ui->title->setText(projects[projectIdx].name);
    }
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
    }
    reloadTickets();
}

Archive::~Archive()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void Archive::reloadTickets() {
    QVector<QPushButton*> uiButtons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < uiButtons.size(); widIdx++) {
        if (uiButtons.at(widIdx)->objectName() == "archivedTicket") { delete uiButtons.at(widIdx); }
    }

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].isOpen) { continue; }
            int ticketCreationTime = projects[projectIdx].tickets[ticketIdx].creationTime;
            QPushButton* ticketButton = new QPushButton;
            ticketButton->setStyleSheet("background-color:#32ACBE; font-size:24px; font-weight:bold; color:white; padding:5px; text-align:left; border:0px; padding-left:10px;");
            ticketButton->setText(projects[projectIdx].tickets[ticketIdx].title);
            ticketButton->setObjectName("archivedTicket");
            connect(ticketButton, &QPushButton::clicked, [this, ticketCreationTime] { openTicket(ticketCreationTime); });
            QPushButton* openButton = new QPushButton;
            openButton->setStyleSheet("background-color: white; font-size:24px; font-weight:bold; color:#CA0736; padding:5px; border:0px;");
            openButton->setText("Re-open");
            openButton->setMaximumWidth(125);
            openButton->setObjectName("archivedTicket");
            connect(openButton, &QPushButton::clicked, [this, ticketCreationTime] { reOpenTicket(ticketCreationTime); });
            QPushButton* deleteButton = new QPushButton;
            deleteButton->setStyleSheet("background-color:#CA0736; font-size:24px; font-weight:bold; color:white; padding:5px; border:0px;");
            deleteButton->setText("Delete");
            deleteButton->setMaximumWidth(100);
            deleteButton->setObjectName("archivedTicket");
            connect(deleteButton, &QPushButton::clicked, [this, ticketCreationTime] { deleteTicket(ticketCreationTime); });

            QHBoxLayout* ticketLayout = new QHBoxLayout;

            ui->pageFrame->addLayout(ticketLayout);
            ticketLayout->addWidget(ticketButton);
            ticketLayout->addWidget(openButton);
            ticketLayout->addWidget(deleteButton);
            if (userAccessLevel == 0) {
                openButton->hide();
                deleteButton->hide();
            }
        }
    }
}

void Archive::reOpenTicket(int ticketID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());

    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            FileManager::Log newLog;
            newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
            newLog.description = "Ticket re-opened";
            newLog.uniqueIdentifier = 0;
            newLog.isConsole = true;
            projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
            if (projects[projectIdx].tickets[ticketIdx].creationTime != ticketID) { continue; }
            projects[projectIdx].tickets[ticketIdx].isOpen = true;
            myFiles.saveProjects(myFiles.compileProjects(projects));
            break;
        }
    }

    reloadTickets();
}

void Archive::deleteTicket(int ticketID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());

    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime != ticketID) { continue; }
            projects[projectIdx].tickets.removeAt(ticketIdx);
            myFiles.saveProjects(myFiles.compileProjects(projects));
            break;
        }
    }

    reloadTickets();
}

void Archive::openTicket(int ticketID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 4;
    state.pageData = IDProject;
    state.secondaryPageData = ticketID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Archive::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Archive::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Archive::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Archive::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

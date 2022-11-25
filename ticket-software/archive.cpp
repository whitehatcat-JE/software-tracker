#include "archive.h"
#include "ui_archive.h"
// Archive constructor
Archive::Archive(int projectID, QWidget *parent) : QWidget(parent), ui(new Ui::Archive) {
    ui->setupUi(this);
    IDProject = projectID;
    // Loads project data
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Displays project name
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) {
            ui->title->setText(projects[projectIdx].name);
            break;
        }
    }
    // Hides management button if user access level is too low
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
    }

    // Loads all archived project tickets
    reloadTickets();
}
// Archive destructor
Archive::~Archive() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Displays all archived project tickets
void Archive::reloadTickets() {
    // Deletes currently displayed tickets
    QVector<QPushButton*> uiButtons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < uiButtons.size(); widIdx++) {
        if (uiButtons.at(widIdx)->objectName() == "archivedTicket") { delete uiButtons.at(widIdx); }
    }
    // Re-creates all tickets
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        // Loops through all tickets in project
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].isOpen) { continue; } // Checks if ticket is archived
            // Creates and formats displayed ticket
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
            // Adds ticket to layout
            QHBoxLayout* ticketLayout = new QHBoxLayout;

            ui->pageFrame->addLayout(ticketLayout);
            ticketLayout->addWidget(ticketButton);
            ticketLayout->addWidget(openButton);
            ticketLayout->addWidget(deleteButton);
            if (userAccessLevel == 0) { // Hides ticket manipulation buttons if user access level is too low
                openButton->hide();
                deleteButton->hide();
            }
        }
    }
}

// Un-archives ticket
void Archive::reOpenTicket(int ticketID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Finds ticket in DB
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            // Adds re-opened log to ticket
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
    // Saves changes
    reloadTickets();
}

// Deletes ticket from project
void Archive::deleteTicket(int ticketID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Finds ticket
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime != ticketID) { continue; }
            // Delete ticket
            projects[projectIdx].tickets.removeAt(ticketIdx);
            myFiles.saveProjects(myFiles.compileProjects(projects));
            break;
        }
    }
    // Saves changes
    reloadTickets();
}

// Opens ticket page
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

// Opens assigments page
void Archive::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void Archive::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void Archive::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void Archive::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

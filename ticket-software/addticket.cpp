// Includes headers
#include "addticket.h"
#include "ui_addticket.h"

// Add ticket class constructor
AddTicket::AddTicket(int projectID, QWidget *parent) : QWidget(parent), ui(new Ui::AddTicket) {
    ui->setupUi(this);
    assignedIdentifier = projectID;
    // Converts UNIX stored time into day/month/year format
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd/MM/yyyy");
    ui->date->setText("Created on: " + formattedTime + " -");
    // Retrieves db information to be displayed on page
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::User> users = myFiles.loadUsers();
    int projectIdx = 0;
    // Displays project name that ticket is being assigned to
    for (;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != projectID) { continue; }
        ui->backButton->setText("◄ " + projects[projectIdx].name); // Adds project name to end of back button
        ui->extraData->setText("- " + projects[projectIdx].name + " - Unresolved"); // Adds project name to metadata
        break;
    }
    // Displays username of logged in user
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == myFiles.loadState().userID) {
            ui->displayedUser->setText(users[userIdx].username); // Displays username
            ui->displayedUser->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png")); // Displays user profile picture
            break;
        }
    }
    // Hides management nav bar option if user access level isn't high enough
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
    }
}

// Add ticket class destructor
AddTicket::~AddTicket() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Creates new ticket
void AddTicket::on_createTicket_clicked() {
    // Displays error message if any input field is left blank
    if (ui->details->toPlainText().size() == 0 || ui->category->text().size() == 0 || ui->ticketTitle->text().size() == 0) {
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }
    // Writes ticket to DB
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    //  Constructs new ticket
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
    //  Appends ticket to correct project struct
    newTicket.logs.push_back(initialLog);
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
            projects[projectIdx].tickets.append(newTicket);
            // Saves changes
            myFiles.saveProjects(myFiles.compileProjects(projects));
        }
    }
    // Redirects user back to project page
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Switches to project page
void AddTicket::on_backButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Switches to assignments page
void AddTicket::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Switches to profile page
void AddTicket::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Switches to management page
void AddTicket::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void AddTicket::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

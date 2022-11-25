#include "project.h"
#include "ui_project.h"

// Project constructor
Project::Project(int projectID, QWidget *parent) : QWidget(parent), ui(new Ui::Project) {
    ui->setupUi(this);
    assignedIdentifier = projectID;
    // Loads all projects
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    int projectIdx = 0;
    // Finds given project
    for (;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != projectID) { continue;}
        // Displays all tickets in given project
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (!projects[projectIdx].tickets[ticketIdx].isOpen) { continue; }
            // Draws ticket button
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
            connect(button, &QPushButton::clicked, [this, ticketIdentifier] { openTicket(ticketIdentifier); });
            // Draws ticket metadata
            QLabel *label = new QLabel("metadata", button);
            QString metadataString = "Created on: 9/12/22 - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
            metadataString += projects[projectIdx].name + " - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].progress;
            label->setText(metadataString);
            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
            // Adds ticket to UI
            ui->ticketList->addWidget(button);
            displayedTickets.push_back(button);
        } break;
    }
    // Hides management button if user access level is too low
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
        ui->detailsButton->hide();
        ui->detailsButton_2->hide();
        ui->line_3->hide();
    }
    // Changes project page details to reflect current project
    ui->title->setText(projects[projectIdx].name);
    ui->details->setText(projects[projectIdx].description);
}

// Project page destructor
Project::~Project() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Updates ticket results based off search bar
void Project::on_lineEditPassword_textChanged(const QString &query) {
    while (displayedTickets.size() > 0) { // Deletes currently displayed tickets
        displayedTickets[0]->deleteLater();
        displayedTickets.pop_front();
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Loops through all tickets in given project
    for (int projectIdx = 0;projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != assignedIdentifier) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (!projects[projectIdx].tickets[ticketIdx].title.contains(query) ||
                    !projects[projectIdx].tickets[ticketIdx].isOpen) { continue; } // Stops archived tickets from being displayed
            // Draws ticket button
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedTicket" + QString::number(ticketIdx));
            button->setText(projects[projectIdx].tickets[ticketIdx].title);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
            connect(button, &QPushButton::clicked, [this, ticketIdentifier] { openTicket(ticketIdentifier); });
            // Draws ticket metadata
            QLabel *label = new QLabel("metadata", button);
            QString metadataString = "Created on: 9/12/22 - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
            metadataString += projects[projectIdx].name + " - ";
            metadataString += projects[projectIdx].tickets[ticketIdx].progress;
            label->setText(metadataString);
            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
            // Adds ticket to UI
            ui->ticketList->addWidget(button);
            displayedTickets.push_back(button);
        } break;
    }
}

// Enable / disable project description editing
void Project::on_detailsButton_toggled(bool checked) {
    if (checked) { // Enable description editing
        // Enables title edit field
        ui->detailsButton->setText(" Save");
        ui->details->setReadOnly(false);
        ui->details->setStyleSheet("font-size: 24px;font-family: Inter;color: #010511; font-weight:lighter; background-color:white; border:0px;");
    } else { // Disable description editing
        // Save new project description
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
                projects[projectIdx].description = ui->details->toPlainText();
                // Writes new description to disk
                myFiles.saveProjects(myFiles.compileProjects(projects));
                break;
            }
        }
        // Disables description edit field
        ui->detailsButton->setText("");
        ui->details->setReadOnly(true);
        ui->details->setStyleSheet("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:transparent; border:0px;");
    }
}

// Enable / disable project title editing
void Project::on_detailsButton_2_toggled(bool checked) {
    if (checked) { // Enable title editing
        ui->title->setReadOnly(false);
        ui->title->setStyleSheet("font-size: 72px;font-family: Inter;color: #010511; font-weight:bold; background-color:white; border:0px;");
    } else { // Disable title editing
        // Save new project title
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            if (projects[projectIdx].uniqueIdentifier == assignedIdentifier) {
                projects[projectIdx].name = ui->title->text();
                // Writes new title to disk
                myFiles.saveProjects(myFiles.compileProjects(projects));
                break;
            }
        }
        // Disables title edit field
        ui->title->setReadOnly(true);
        ui->title->setStyleSheet("font-size: 72px;font-family: Inter;color: white; font-weight:bold; background-color:transparent; border:0px;");
    }
}

// Opens ticket page
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

// Opens assignments page
void Project::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void Project::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void Project::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void Project::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens add ticket page
void Project::on_createTicketButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 5;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens project archive page
void Project::on_archiveButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 6;
    state.pageData = assignedIdentifier;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


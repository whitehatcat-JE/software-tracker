#include "management.h"
#include "ui_management.h"
// Management constructor
Management::Management(QWidget *parent) : QWidget(parent), ui(new Ui::Management) {
    ui->setupUi(this);
}

// Management destructor
Management::~Management() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Opens assignement page
void Management::on_assignedButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void Management::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void Management::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens user management page
void Management::on_usersButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 8;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens group management page
void Management::on_groupsButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 9;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens project management page
void Management::on_projectsButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 10;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

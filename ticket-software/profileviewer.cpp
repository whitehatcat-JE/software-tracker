#include "profileviewer.h"
#include "ui_profileviewer.h"

// ProfileViewer constructor
ProfileViewer::ProfileViewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::ProfileViewer) {
    ui->setupUi(this);
    FileManager myFiles;
    // Hides management button if user access level is too low
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton_2->hide();
        ui->line_11->hide();
    }
    // Loads users from db
    QVector<FileManager::User> users = myFiles.loadUsers();
    FileManager::StateData state = myFiles.loadState();
    // Finds given user
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (state.pageData == users[userIdx].uniqueIdentifier) {
            // Changes page data to reflect current user
            ui->Name->setText(users[userIdx].username);
            ui->JobTitle->setText(users[userIdx].job);
            ui->workHours->setText(users[userIdx].activeTimes);
            ui->location->setText(users[userIdx].location);
            ui->number->setText(users[userIdx].phone);
            ui->email->setText(users[userIdx].email);
            ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png);");
            ui->accessLevel->setText(QString::number(users[userIdx].accessLevel+1));
            return;
        }
    }
}

// ProfileViewer destructor
ProfileViewer::~ProfileViewer() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Open management page
void ProfileViewer::on_managementButton_2_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open assignments page
void ProfileViewer::on_assignButton_2_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open profile page
void ProfileViewer::on_profileButton_2_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void ProfileViewer::on_logoutButton_2_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

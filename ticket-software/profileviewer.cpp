#include "profileviewer.h"
#include "ui_profileviewer.h"

ProfileViewer::ProfileViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfileViewer)
{
    ui->setupUi(this);
    FileManager myFiles;
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton_2->hide();
        ui->line_11->hide();
    }
    QVector<FileManager::User> users = myFiles.loadUsers();
    FileManager::StateData state = myFiles.loadState();

    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (state.pageData == users[userIdx].uniqueIdentifier) {
            ui->Name->setText(users[userIdx].username);
            ui->JobTitle->setText(users[userIdx].job);
            ui->workHours->setText(users[userIdx].activeTimes);
            ui->location->setText(users[userIdx].location);
            ui->number->setText(users[userIdx].phone);
            ui->email->setText(users[userIdx].email);
            ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png);");
            return;
        }
    }
}

ProfileViewer::~ProfileViewer()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void ProfileViewer::on_managementButton_2_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProfileViewer::on_assignButton_2_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProfileViewer::on_profileButton_2_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProfileViewer::on_logoutButton_2_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

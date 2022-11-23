#include "management.h"
#include "ui_management.h"

Management::Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Management)
{
    ui->setupUi(this);
}

Management::~Management() {
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void Management::on_assignedButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Management::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Management::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Management::on_usersButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 8;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Management::on_groupsButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 9;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void Management::on_projectsButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 10;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

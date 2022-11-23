#include "usermanagement.h"
#include "ui_usermanagement.h"

UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);
    reloadUsers();
}

void UserManagement::reloadUsers() {
    QVector<QPushButton*> userButtons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < userButtons.size(); widIdx++) {
        if (userButtons.at(widIdx)->objectName() == "userInfo") { delete userButtons.at(widIdx); }
    }
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        int userID = users[userIdx].uniqueIdentifier;

        QHBoxLayout* userLayout = new QHBoxLayout;

        QPushButton* userButton = new QPushButton;
        QPushButton* projectsButton = new QPushButton;
        QPushButton* groupsButton = new QPushButton;
        QPushButton* ticketsButton = new QPushButton;
        QPushButton* accessLevelButton = new QPushButton;
        QPushButton* deleteButton = new QPushButton;

        userButton->setText(users[userIdx].username);
        if (myFiles.loadState().userID != userID) {
            userButton->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        } else {
            userButton->setStyleSheet("background-color:#32ACBE; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        }
        userButton->setMinimumHeight(50);
        userButton->setObjectName("userInfo");
        //connect(projectButton, &QPushButton::clicked, [this, projectIdentifer] { openProject(projectIdentifer); });

        accessLevelButton->setText(QString::number(users[userIdx].accessLevel));
        accessLevelButton->setStyleSheet("background-color:#CA0736; border:0px; color:white; font-weight: bold; font-size:24px; border-radius:25px;");
        accessLevelButton->setMaximumWidth(50);
        accessLevelButton->setMinimumHeight(50);
        accessLevelButton->setObjectName("userInfo");
        if (myFiles.loadState().userID != userID) {
            connect(accessLevelButton, &QPushButton::clicked, [this, userID] { incrementAccessLevel(userID); });
            accessLevelButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px; border-radius:25px;");
        }

        projectsButton->setText("Projects");
        projectsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        projectsButton->setMaximumWidth(100);
        projectsButton->setMinimumHeight(50);
        projectsButton->setObjectName("userInfo");

        groupsButton->setText("Groups");
        groupsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        groupsButton->setMaximumWidth(100);
        groupsButton->setMinimumHeight(50);
        groupsButton->setObjectName("userInfo");
        //(groupsButton, &QPushButton::clicked, [this, projectIdentifer] { openProjectGroups(projectIdentifer); });

        ticketsButton->setText("Tickets");
        ticketsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        ticketsButton->setMaximumWidth(100);
        ticketsButton->setMinimumHeight(50);
        ticketsButton->setObjectName("userInfo");

        deleteButton->setIcon(QIcon(":/Image/Images/lockIcon.png"));
        deleteButton->setStyleSheet("background-color:transparent; border:0px;");
        deleteButton->setIconSize(QSize(50, 50));
        deleteButton->setMaximumWidth(50);
        deleteButton->setObjectName("userInfo");
        if (myFiles.loadState().userID != userID) {
            connect(deleteButton, &QPushButton::clicked, [this, userID] { deleteUser(userID); });
            deleteButton->setIcon(QIcon(":/Image/Images/trashIcon.png"));
        }

        userLayout->addWidget(userButton);
        userLayout->addWidget(accessLevelButton);
        userLayout->addWidget(projectsButton);
        userLayout->addWidget(groupsButton);
        userLayout->addWidget(ticketsButton);
        userLayout->addWidget(deleteButton);

        ui->pageFrame_3->addLayout(userLayout);
    }
}

UserManagement::~UserManagement() {
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void UserManagement::incrementAccessLevel(int userID) {
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) {
            users[userIdx].accessLevel += users[userIdx].accessLevel == 2 ? -2 : 1;
        }
    }
    myFiles.saveUsers(users);
    reloadUsers();
}

void UserManagement::deleteUser(int userID) {
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) {
            users.removeAt(userIdx);
            myFiles.saveUsers(users);
            reloadUsers();
            return;
        }
    }
}

void UserManagement::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void UserManagement::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void UserManagement::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void UserManagement::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void UserManagement::on_createUserButton_clicked()
{
    if (ui->usernameField->text().size() == 0 || ui->passwordField->text().size() == 0) {
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }

    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    FileManager::User newUser;
    newUser.username = ui->usernameField->text();
    newUser.uniqueIdentifier = users.size() == 0 ? 0 : users[users.size()-1].uniqueIdentifier+1;
    newUser.password = myFiles.hash(newUser.uniqueIdentifier, ui->passwordField->text());
    users.push_back(newUser);
    myFiles.saveUsers(users);
    reloadUsers();
}


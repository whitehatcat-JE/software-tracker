#include "usermanagement.h"
#include "ui_usermanagement.h"

// UserManagement constructor
UserManagement::UserManagement(QWidget *parent) : QWidget(parent), ui(new Ui::UserManagement) {
    ui->setupUi(this);
    reloadUsers();
}

// Display all users in system
void UserManagement::reloadUsers() {
    // Removes all displayed users
    QVector<QPushButton*> userButtons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < userButtons.size(); widIdx++) {
        if (userButtons.at(widIdx)->objectName() == "userInfo") { delete userButtons.at(widIdx); }
    }
    // Re-draws all users
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        int userID = users[userIdx].uniqueIdentifier;
        // Creates new user widgets
        QHBoxLayout* userLayout = new QHBoxLayout;

        QPushButton* userButton = new QPushButton;
        QPushButton* projectsButton = new QPushButton;
        QPushButton* groupsButton = new QPushButton;
        QPushButton* ticketsButton = new QPushButton;
        QPushButton* accessLevelButton = new QPushButton;
        QPushButton* deleteButton = new QPushButton;
        // Checks if user is same as currently signed in user
        userButton->setText(users[userIdx].username);
        if (myFiles.loadState().userID != userID) { // Changes user background color to red
            userButton->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        } else { // Changes user background color to blue
            userButton->setStyleSheet("background-color:#32ACBE; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        }
        // Formats user button
        userButton->setMinimumHeight(50);
        userButton->setObjectName("userInfo");
        // Formats access level button
        accessLevelButton->setText(QString::number(users[userIdx].accessLevel+1));
        accessLevelButton->setStyleSheet("background-color:#CA0736; border:0px; color:white; font-weight: bold; font-size:24px; border-radius:25px;");
        accessLevelButton->setMaximumWidth(50);
        accessLevelButton->setMinimumHeight(50);
        accessLevelButton->setObjectName("userInfo");
        if (myFiles.loadState().userID != userID) { // Locks access level button if user is currently signed in user
            connect(accessLevelButton, &QPushButton::clicked, [this, userID] { incrementAccessLevel(userID); });
            accessLevelButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px; border-radius:25px;");
        }
        // Formats projectsButton
        projectsButton->setText("Projects");
        projectsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        projectsButton->setMaximumWidth(100);
        projectsButton->setMinimumHeight(50);
        projectsButton->setObjectName("userInfo");
        connect(projectsButton, &QPushButton::clicked, [this, userID] { assignUserProjects(userID); });
        // Formats groupsButton
        groupsButton->setText("Groups");
        groupsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        groupsButton->setMaximumWidth(100);
        groupsButton->setMinimumHeight(50);
        groupsButton->setObjectName("userInfo");
        connect(groupsButton, &QPushButton::clicked, [this, userID] { assignUserGroups(userID); });
        // Formats ticketsButton
        ticketsButton->setText("Tickets");
        ticketsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        ticketsButton->setMaximumWidth(100);
        ticketsButton->setMinimumHeight(50);
        ticketsButton->setObjectName("userInfo");
        connect(ticketsButton, &QPushButton::clicked, [this, userID] { assignUserTickets(userID); });
        // Formats deleteButton
        deleteButton->setIcon(QIcon(":/Image/Images/lockIcon.png"));
        deleteButton->setStyleSheet("background-color:transparent; border:0px;");
        deleteButton->setIconSize(QSize(50, 50));
        deleteButton->setMaximumWidth(50);
        deleteButton->setObjectName("userInfo");
        if (myFiles.loadState().userID != userID) { // Prevents user from deleting self
            connect(deleteButton, &QPushButton::clicked, [this, userID] { deleteUser(userID); });
            deleteButton->setIcon(QIcon(":/Image/Images/trashIcon.png"));
        }
        // Adds user widgets to layout
        userLayout->addWidget(userButton);
        userLayout->addWidget(accessLevelButton);
        userLayout->addWidget(projectsButton);
        userLayout->addWidget(groupsButton);
        userLayout->addWidget(ticketsButton);
        userLayout->addWidget(deleteButton);
        // Adds layout to UI
        ui->pageFrame_3->addLayout(userLayout);
    }
}

// UserManagement destructor
UserManagement::~UserManagement() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Changes user access level
void UserManagement::incrementAccessLevel(int userID) {
    // Loads all users
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    // Finds given user
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) {
            // Increments access level
            users[userIdx].accessLevel += users[userIdx].accessLevel == 2 ? -2 : 1;
        }
    }
    // Saves changes
    myFiles.saveUsers(users);
    // Displays new changes
    reloadUsers();
}

// Delete given user
void UserManagement::deleteUser(int userID) {
    // Loads all users
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    // Finds given user
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) {
            // Deletes user
            users.removeAt(userIdx);
            // Saves changes
            myFiles.saveUsers(users);
            // Displays changes
            reloadUsers();
            return;
        }
    }
}

// Open managementSelection page for user groups
void UserManagement::assignUserGroups(int userID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 6;
    state.secondaryPageData = userID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open mangementSelection page for user tickets
void UserManagement::assignUserTickets(int userID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 7;
    state.secondaryPageData = userID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens managementSelection page for user projects
void UserManagement::assignUserProjects(int userID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 5;
    state.secondaryPageData = userID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open assignments page
void UserManagement::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open profile page
void UserManagement::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open management page
void UserManagement::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void UserManagement::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Adds new user to system
void UserManagement::on_createUserButton_clicked() {
    if (ui->usernameField->text().size() == 0 || ui->passwordField->text().size() == 0) { // Checks if username or password field empty
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return; // Stops new user from being created
    }
    // Loads all users
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    // Create new user struct
    FileManager::User newUser;
    newUser.username = ui->usernameField->text();
    newUser.uniqueIdentifier = users.size() == 0 ? 0 : users[users.size()-1].uniqueIdentifier+1;
    newUser.password = myFiles.hash(newUser.uniqueIdentifier, ui->passwordField->text());
    // Add new user to users DB
    users.push_back(newUser);
    // Write changes to disk
    myFiles.saveUsers(users);
    // Displays changes
    reloadUsers();
}

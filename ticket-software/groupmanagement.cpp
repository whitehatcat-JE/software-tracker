#include "groupmanagement.h"
#include "ui_groupmanagement.h"

// GroupManagement constructor
GroupManagement::GroupManagement(QWidget *parent) : QWidget(parent), ui(new Ui::GroupManagement) {
    ui->setupUi(this);
    reloadGroups();
}

// GroupManagement destructor
GroupManagement::~GroupManagement() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Loads all groups
void GroupManagement::reloadGroups(){
    // Deletes existing group buttons
    QVector<QPushButton*> buttons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < buttons.size(); widIdx++) {
        if (buttons.at(widIdx)->objectName() == "groupInfo") { delete buttons.at(widIdx); }
    }
    // Deletes existing group input fields
    QVector<QLineEdit*> groupNameFields = ui->assignedItems->findChildren<QLineEdit *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < groupNameFields.size(); widIdx++) {
        if (groupNameFields.at(widIdx)->objectName() == "groupInfo") { delete groupNameFields.at(widIdx); }
    }
    // Loops through all groups
    FileManager myFiles;
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
        // Draws new group
        int groupIdentifier = groups[groupIdx].ID;

        QHBoxLayout* groupLayout = new QHBoxLayout;

        QLineEdit* groupTextField = new QLineEdit;
        // Group manipulation buttons
        QPushButton* projectsButton = new QPushButton;
        QPushButton* usersButton = new QPushButton;
        QPushButton* ticketsButton = new QPushButton;
        QPushButton* editButton = new QPushButton;
        QPushButton* deleteButton = new QPushButton;

        // Formats group buttons / fields
        groupTextField->setText(groups[groupIdx].name);
        groupTextField->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        groupTextField->setMaximumHeight(50);
        groupTextField->setObjectName("groupInfo");
        groupTextField->setReadOnly(true);

        projectsButton->setText("Projects");
        projectsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        projectsButton->setMinimumWidth(100);
        projectsButton->setMinimumHeight(50);
        projectsButton->setObjectName("groupInfo");
        connect(projectsButton, &QPushButton::clicked, [this, groupIdentifier] { openGroupProjects(groupIdentifier); });

        ticketsButton->setText("Tickets");
        ticketsButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
        ticketsButton->setMinimumWidth(100);
        ticketsButton->setMinimumHeight(50);
        ticketsButton->setObjectName("groupInfo");
        connect(ticketsButton, &QPushButton::clicked, [this, groupIdentifier] { openGroupTickets(groupIdentifier); });

        usersButton->setText("Users");
        usersButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
        usersButton->setMinimumWidth(100);
        usersButton->setMinimumHeight(50);
        usersButton->setObjectName("groupInfo");
        connect(usersButton, &QPushButton::clicked, [this, groupIdentifier] { openGroupUsers(groupIdentifier); });

        editButton->setIcon(QIcon(":/Image/Images/editIcon.png"));
        editButton->setStyleSheet("background-color:transparent; border:0px;");
        editButton->setIconSize(QSize(50, 50));
        editButton->setMaximumWidth(50);
        editButton->setObjectName("groupInfo");
        connect(editButton, &QPushButton::clicked, [this, groupIdentifier, groupTextField, editButton] { editGroup(groupIdentifier, groupTextField, editButton); });

        deleteButton->setIcon(QIcon(":/Image/Images/trashIcon.png"));
        deleteButton->setStyleSheet("background-color:transparent; border:0px;");
        deleteButton->setIconSize(QSize(50, 50));
        deleteButton->setMaximumWidth(50);
        deleteButton->setObjectName("groupInfo");
        connect(deleteButton, &QPushButton::clicked, [this, groupIdentifier] { deleteGroup(groupIdentifier); });

        // Adds group to layout
        groupLayout->addWidget(groupTextField);
        groupLayout->addWidget(projectsButton);
        groupLayout->addWidget(ticketsButton);
        groupLayout->addWidget(usersButton);
        groupLayout->addWidget(editButton);
        groupLayout->addWidget(deleteButton);
        // Adds layout to UI
        ui->pageFrame->addLayout(groupLayout);
    }
}

// Opens assignments page
void GroupManagement::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void GroupManagement::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void GroupManagement::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void GroupManagement::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Creates a new group
void GroupManagement::on_createGroupButton_clicked() {
    if (ui->newGroupName->text().size() == 0) { // Display error message if name is blank
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }
    // Adds new group to groupDB
    FileManager myFiles;
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    FileManager::Group newGroup;
    newGroup.name = ui->newGroupName->text();
    if (groups.size() == 0) { newGroup.ID = 0; }
    else { newGroup.ID = groups[groups.size()-1].ID+1; }
    groups.push_back(newGroup);
    myFiles.saveGroups(groups);
    // Redraws groups
    reloadGroups();
}

// Edit group name
void GroupManagement::editGroup(int groupID, QLineEdit* textField, QPushButton* editButton) {
    if (textField->isReadOnly()) { // Enable group name editing
        textField->setReadOnly(false);
        textField->setStyleSheet("background-color:white; color:#CA0736; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        editButton->setIcon(QIcon(":/Image/Images/editEnabledIcon.png"));
        return;
    }

    if (textField->text().size() == 0) { // Displays error if name is blank
        QMessageBox::warning(
            this,
            tr("No name entered"),
            tr("Group name cannot be empty") );
        return;
    }
    // Disable group name editing
    textField->setReadOnly(true);
    textField->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
    editButton->setIcon(QIcon(":/Image/Images/editIcon.png"));
    // Writes new group name to groupDB
    FileManager myFiles;
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
        if (groups[groupIdx].ID != groupID) { continue; }
        groups[groupIdx].name = textField->text();
        myFiles.saveGroups(groups);
        return;
    }
}

// Deletes group
void GroupManagement::deleteGroup(int groupID) {
    // Loads groupData
    FileManager myFiles;
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    // Removes group from groupData
    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
        if (groups[groupIdx].ID != groupID) { continue; }
        groups.removeAt(groupIdx);
    }
    // Saves group data
    myFiles.saveGroups(groups);
    // Applies group data changes to UI
    reloadGroups();

}

// Opens project management selection page
void GroupManagement::openGroupProjects(int groupID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 0;
    state.secondaryPageData = groupID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens ticket management selection page
void GroupManagement::openGroupTickets(int groupID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 1;
    state.secondaryPageData = groupID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open user management selection page
void GroupManagement::openGroupUsers(int groupID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 2;
    state.secondaryPageData = groupID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

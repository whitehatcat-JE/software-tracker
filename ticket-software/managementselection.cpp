#include "managementselection.h"
#include "ui_managementselection.h"

// ManagementSelection constructor
ManagementSelection::ManagementSelection(int selectionType, int id, QWidget *parent) : QWidget(parent), ui(new Ui::ManagementSelection) {
    // Selection Types:
    // 0:groupProject 1:groupUser 2:groupTicket
    // 3:projectGroup 4: projectUser
    // 5:userProject 6:userGroup 7:userTicket
    // 8:ticketUser 9:ticketGroup
    type = selectionType;
    objID = id;
    ui->setupUi(this);

    // Load files needed by different selectionTypes
    FileManager myFiles;

    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    QVector<FileManager::User> users = myFiles.loadUsers();
    QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();

    // Displays selected item list
    switch (selectionType) {
    case 0: // Group Projects
        ui->backButton->setText("< Groups");
        // Loops through all projects
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            // Draws new project
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            int projectIdentifier = projects[projectIdx].uniqueIdentifier;
            newLabel->setText(projects[projectIdx].name);
            // Checks if project assigned to group
            for (int groupIdx = 0; groupIdx < groups.size() && !currentlyAssigned; groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size() && !currentlyAssigned; groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == projectIdentifier) { currentlyAssigned = true; }
                }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton] { changeListing(projectIdentifier, addButton); });
        } break;
    case 1: // Group Tickets
        ui->backButton->setText("< Groups");
        // Loops through all tickets in all projects
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            int projectIdentifier = projects[projectIdx].uniqueIdentifier;
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
                // Draw new ticket
                QHBoxLayout* newLayout = new QHBoxLayout;
                QLabel* newLabel = new QLabel;
                newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                newLabel->setMinimumHeight(50);
                QPushButton* addButton = new QPushButton;
                bool currentlyAssigned = false;
                newLabel->setText(projects[projectIdx].tickets[ticketIdx].title);
                // Check if ticket currently assigned
                for (int groupIdx = 0; groupIdx < groups.size() && !currentlyAssigned; groupIdx++) {
                    if (groups[groupIdx].ID != objID) { continue; }
                    for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size() && !currentlyAssigned; groupTicketIdx++) {
                        if (groups[groupIdx].tickets[groupTicketIdx].ticketID == ticketIdentifier &&
                            groups[groupIdx].tickets[groupTicketIdx].projectID == projectIdentifier) { currentlyAssigned = true; }
                    }
                }
                // Changes add button to remove if currently assigned
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                // Formats AddButton
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);
                // Adds AddButton to Layout
                newLayout->addWidget(newLabel);
                newLayout->addWidget(addButton);
                // Add Layout to UI
                ui->pageFrame_2->addLayout(newLayout);
                // Connects AddButton to assignment method
                connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton, ticketIdentifier] { changeListing(projectIdentifier, addButton, ticketIdentifier); });
            }
        } break;
    case 2: // Group Users
        ui->backButton->setText("< Groups");
        // Loops through users
        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
            int userID = users[userIdx].uniqueIdentifier;
            // Adds new user
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(users[userIdx].username);
            // Checks if user currently assigned
            for (int groupIdx = 0; groupIdx < groups.size() && !currentlyAssigned; groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size() && !currentlyAssigned; groupUserIdx++) {
                    if (groups[groupIdx].users[groupUserIdx] == userID) { currentlyAssigned = true; }
                }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, userID, addButton] { changeListing(userID, addButton); });
        } break;
    case 3: // Project Groups
        ui->backButton->setText("< Projects");
        // Loops through groups
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            int groupIdentifier = groups[groupIdx].ID;
            // Draws new group
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(groups[groupIdx].name);
            // Checks if group is currently assigned
            for (int projectIdx = 0; projectIdx < groups[groupIdx].projects.size() && !currentlyAssigned; projectIdx++) {
                if (groups[groupIdx].projects[projectIdx] == objID) { currentlyAssigned = true; }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });
        } break;
    case 4: // Project Users
        ui->backButton->setText("< Projects");
        // Loops through users
        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
            int userID = users[userIdx].uniqueIdentifier;
            // Drwas new user
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(users[userIdx].username);
            // Checks if user is currently assigned
            for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !currentlyAssigned; userRelationIdx++) {
                if (userRelations[userRelationIdx].uniqueIdentifier != userID) { continue; }
                if (userRelations[userRelationIdx].projects.contains(objID)) { currentlyAssigned = true; }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, userID, addButton] { changeListing(userID, addButton); });
        } break;
    case 5: // User projects
        ui->backButton->setText("< Users");
        // Loops through projects
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            int projectIdentifier = projects[projectIdx].uniqueIdentifier;
            // Draws new project
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(projects[projectIdx].name);
            // Checks if project currently assigned
            for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !currentlyAssigned; userRelationIdx++) {
                if (userRelations[userRelationIdx].uniqueIdentifier != objID) { continue; }
                for (int projectRelationIdx = 0; projectRelationIdx < userRelations[userRelationIdx].projects.size() && !currentlyAssigned; projectRelationIdx++) {
                    if (userRelations[userRelationIdx].projects[projectRelationIdx] == projectIdentifier) { currentlyAssigned = true; }
                }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton] { changeListing(projectIdentifier, addButton); });
        } break;
    case 6: // User groups
        ui->backButton->setText("< Users");
        // Loops through groups
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            int groupIdentifier = groups[groupIdx].ID;
            // Draws new group
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(groups[groupIdx].name);
            // Checks if group currently assigned
            for (int userIdx = 0; userIdx < groups[groupIdx].users.size() && !currentlyAssigned; userIdx++) {
                if (groups[groupIdx].users[userIdx] == objID) { currentlyAssigned = true; }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });
        } break;
    case 7: // User tickets
        ui->backButton->setText("< Users");
        // Loops through all tickets in all projects
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            int projectIdentifier = projects[projectIdx].uniqueIdentifier;
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
                // Draws new ticket
                QHBoxLayout* newLayout = new QHBoxLayout;
                QLabel* newLabel = new QLabel;
                newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                newLabel->setMinimumHeight(50);
                QPushButton* addButton = new QPushButton;
                bool currentlyAssigned = false;
                newLabel->setText(projects[projectIdx].tickets[ticketIdx].title);
                // Checks if ticket currently assigned
                for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !currentlyAssigned; userRelationIdx++) {
                    if (userRelations[userRelationIdx].uniqueIdentifier != objID) { continue; }
                    for (int ticketRelationIdx = 0; ticketRelationIdx < userRelations[userRelationIdx].tickets.size() && !currentlyAssigned; ticketRelationIdx++) {
                        if (userRelations[userRelationIdx].tickets[ticketRelationIdx].ticketID == ticketIdentifier &&
                            userRelations[userRelationIdx].tickets[ticketRelationIdx].projectID == projectIdentifier) { currentlyAssigned = true; }
                    }
                }
                // Changes add button to remove if currently assigned
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                // Formats AddButton
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);
                // Adds AddButton to Layout
                newLayout->addWidget(newLabel);
                newLayout->addWidget(addButton);
                // Add Layout to UI
                ui->pageFrame_2->addLayout(newLayout);
                // Connects AddButton to assignment method
                connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton, ticketIdentifier] { changeListing(projectIdentifier, addButton, ticketIdentifier); });
            }
        } break;
    case 8: // Ticket users
        ui->backButton->setText("< Ticket");
        // Loops through users
        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
            int userID = users[userIdx].uniqueIdentifier;
            // Drwas new user
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(users[userIdx].username);
            // Checks if user is currently assigned
            for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !currentlyAssigned; userRelationIdx++) {
                if (userRelations[userRelationIdx].uniqueIdentifier != userID) { continue; }
                for (int ticketIdx = 0; ticketIdx < userRelations[userRelationIdx].tickets.size() && !currentlyAssigned; ticketIdx++) {
                    if (userRelations[userRelationIdx].tickets[ticketIdx].ticketID == objID) { currentlyAssigned = true; }
                }
            }
            // Checks if ticket in project
            int projectIdentifier = -1;
            for (int projectIdx = 0; projectIdx < projects.size() && projectIdentifier == -1; projectIdx++) {
                for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                    if (projects[projectIdx].tickets[ticketIdx].creationTime == objID) {
                        projectIdentifier = projects[projectIdx].uniqueIdentifier;
                        break;
                    }
                }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton, userID] { changeListing(projectIdentifier, addButton, userID); });
        } break;
    case 9: // Ticket groups
        ui->backButton->setText("< Ticket");
        // Loops through groups
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            int groupIdentifier = groups[groupIdx].ID;
            // Draws new group
            QHBoxLayout* newLayout = new QHBoxLayout;
            QLabel* newLabel = new QLabel;
            newLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
            newLabel->setMinimumHeight(50);
            QPushButton* addButton = new QPushButton;
            bool currentlyAssigned = false;
            newLabel->setText(groups[groupIdx].name);
            // Checks if group currently assigned
            for (int ticketIdx = 0; ticketIdx < groups[groupIdx].tickets.size() && !currentlyAssigned; ticketIdx++) {
                if (groups[groupIdx].tickets[ticketIdx].ticketID == objID) { currentlyAssigned = true; }
            }
            // Changes add button to remove if currently assigned
            if (currentlyAssigned) {
                addButton->setText("Remove");
                addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
            } else {
                addButton->setText("Add");
                addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
            }
            // Formats AddButton
            addButton->setMinimumWidth(200);
            addButton->setMaximumWidth(200);
            addButton->setMinimumHeight(50);
            // Adds AddButton to Layout
            newLayout->addWidget(newLabel);
            newLayout->addWidget(addButton);
            // Add Layout to UI
            ui->pageFrame_2->addLayout(newLayout);
            // Connects AddButton to assignment method
            connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });
        } break;
    }
}

// ManagementSelection destructor
ManagementSelection::~ManagementSelection() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Adds / removes assignment from entity
void ManagementSelection::changeListing(int id, QPushButton* button, int secondaryID) {
    // Gets all DB info
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();

    if (button->text() == "Add") { // Adds assignment to entity
        button->setText("Remove");
        button->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
        switch (type) {
        case 0: // Adds project to group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                groups[groupIdx].projects.push_back(id);
                break;
            } break;
        case 1: // Adds ticket to group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = secondaryID;
                newTicket.projectID = id;
                groups[groupIdx].tickets.push_back(newTicket);
                break;
            } break;
        case 2: // Adds user to group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                groups[groupIdx].users.push_back(id);
                break;
            } break;
        case 3: // Adds group to project
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                groups[groupIdx].projects.push_back(objID);
                break;
            } break;
        case 4: // Adds user to project
            for (int relationIdx = 0; relationIdx < userRelations.size(); relationIdx++) {
                if (userRelations[relationIdx].uniqueIdentifier != id) { continue; }
                userRelations[relationIdx].projects.push_back(objID);
            } break;
        case 5: // Adds project to user
            for (int relationIdx = 0; relationIdx < userRelations.size(); relationIdx++) {
                if (userRelations[relationIdx].uniqueIdentifier != objID) { continue; }
                userRelations[relationIdx].projects.push_back(id);
            } break;
        case 6:  // Adds group to user
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                groups[groupIdx].users.push_back(objID);
                break;
            } break;
        case 7: // Adds ticket to user
            for (int relationIdx = 0; relationIdx < userRelations.size(); relationIdx++) {
                if (userRelations[relationIdx].uniqueIdentifier != objID) { continue; }
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = secondaryID;
                newTicket.projectID = id;
                userRelations[relationIdx].tickets.push_back(newTicket);
                break;
            } break;
        case 8: // Adds user to ticket
            for (int relationIdx = 0; relationIdx < userRelations.size(); relationIdx++) {
                if (userRelations[relationIdx].uniqueIdentifier != secondaryID) { continue; }
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = objID;
                newTicket.projectID = id;
                userRelations[relationIdx].tickets.push_back(newTicket);
                break;
            } break;
        case 9: // Adds group to project
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = objID;
                for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
                    for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                        if (projects[projectIdx].tickets[ticketIdx].creationTime == objID) {
                            newTicket.projectID = projects[projectIdx].uniqueIdentifier;
                            break;
                        }
                    }
                }
                groups[groupIdx].tickets.push_back(newTicket);
                break;
            } break;
        }
    } else { // Removes assignment from entity
        button->setText("Add");
        button->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
        switch (type) {
        case 0: // Removes project from group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == id) {
                        groups[groupIdx].projects.removeAt(groupProjectIdx);
                        break;
                    }
                } break;
            } break;
        case 1: // Removes ticket from group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                    if (groups[groupIdx].tickets[groupTicketIdx].projectID == id &&
                            groups[groupIdx].tickets[groupTicketIdx].ticketID == secondaryID) {
                        groups[groupIdx].tickets.removeAt(groupTicketIdx);
                        break;
                    }
                } break;
            } break;
        case 2: // Removes group from user
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size(); groupUserIdx++) {
                    if (groups[groupIdx].users[groupUserIdx] == id) {
                        groups[groupIdx].users.removeAt(groupUserIdx);
                        break;
                    }
                } break;
            } break;
        case 3: // Removes project from group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == objID) {
                        groups[groupIdx].projects.removeAt(groupProjectIdx);
                        break;
                    }
                } break;
            } break;
        case 4: // Removes user from project
            for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
                if (userRelations[userIdx].uniqueIdentifier == id) {
                    for (int projectIdx = 0; projectIdx < userRelations[userIdx].projects.size(); projectIdx++) {
                        if (userRelations[userIdx].projects[projectIdx] == objID) {
                            userRelations[userIdx].projects.removeAt(projectIdx);
                            break;
                        }
                    } break;
                }
            } break;
        case 5: // Removes project from user
            for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
                if (userRelations[userIdx].uniqueIdentifier == objID) {
                    for (int projectIdx = 0; projectIdx < userRelations[userIdx].projects.size(); projectIdx++) {
                        if (userRelations[userIdx].projects[projectIdx] == id) {
                            userRelations[userIdx].projects.removeAt(projectIdx);
                            break;
                        }
                    } break;
                }
            } break;
        case 6: // Removes user from group
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size(); groupUserIdx++) {
                    if (groups[groupIdx].users[groupUserIdx] == objID) {
                        groups[groupIdx].users.removeAt(groupUserIdx);
                        break;
                    }
                }
            } break;
        case 7: // Remove user from ticket
            for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
                if (userRelations[userIdx].uniqueIdentifier == objID) {
                    for (int ticketIdx = 0; ticketIdx < userRelations[userIdx].tickets.size(); ticketIdx++) {
                        if (userRelations[userIdx].tickets[ticketIdx].ticketID == secondaryID &&
                            userRelations[userIdx].tickets[ticketIdx].projectID == id) {
                            userRelations[userIdx].tickets.removeAt(ticketIdx);
                            break;
                        }
                    } break;
                }
            } break;
        case 8: // Remove ticket from user
            for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
                if (userRelations[userIdx].uniqueIdentifier == secondaryID) {
                    for (int ticketIdx = 0; ticketIdx < userRelations[userIdx].tickets.size(); ticketIdx++) {
                        if (userRelations[userIdx].tickets[ticketIdx].projectID == id &&
                            userRelations[userIdx].tickets[ticketIdx].ticketID == objID) {
                            userRelations[userIdx].tickets.removeAt(ticketIdx);
                        }
                    }
                }
            } break;
        case 9: // Remove project from group
            int projectID = 0;
            for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
                for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                    if (projects[projectIdx].tickets[ticketIdx].creationTime == objID) {
                        projectID = projects[projectIdx].uniqueIdentifier;
                        break;
                    }
                }
            }
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                    if (groups[groupIdx].tickets[groupTicketIdx].projectID == projectID &&
                        groups[groupIdx].tickets[groupTicketIdx].ticketID == objID) {
                        groups[groupIdx].tickets.removeAt(groupTicketIdx);
                        break;
                    }
                } break;
            } break;
        }
    }
    // Save changes
    myFiles.saveGroups(groups);
    myFiles.saveProjects(myFiles.compileProjects(projects));
    myFiles.saveUserRelations(userRelations);
}

// Open assignments page
void ManagementSelection::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open profile page
void ManagementSelection::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Open management page
void ManagementSelection::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void ManagementSelection::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens previously open page
void ManagementSelection::on_backButton_clicked() {
    // Retrieves which page to go back to
    FileManager myFiles;
    FileManager::StateData state;
    if (type <= 2) { state.newPage = 9; }
    else if (type <= 4) { state.newPage = 10; }
    else if (type <= 7) { state.newPage = 8; }
    else {
        state.newPage = 4;

        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        int projectID = 0;
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                if (projects[projectIdx].tickets[ticketIdx].creationTime == objID) {
                    projectID = projects[projectIdx].uniqueIdentifier;
                    break;
                }
            }
        }
        state.pageData = projectID;
        state.secondaryPageData = objID;
    }
    // Opens selected page
    myFiles.saveState(state);
    closing = false;
    this->close();
}


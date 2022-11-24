#include "managementselection.h"
#include "ui_managementselection.h"

ManagementSelection::ManagementSelection(int selectionType, int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagementSelection)
{
    // Selection Types:
    // 0:groupProject 1:groupUser 2:groupTicket
    // 3:projectGroup 4: projectUser
    // 5:userProject 6:userGroup 7:userTicket
    // 8:ticketUser 9:ticketGroup
    type = selectionType;
    objID = id;
    ui->setupUi(this);

    FileManager myFiles;

    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::Group> groups = myFiles.loadGroups();
    QVector<FileManager::User> users = myFiles.loadUsers();

    if (selectionType <= 2) {
        ui->backButton->setText("< Groups");
        if (selectionType == 0) {
            for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
                int projectIdentifier = projects[projectIdx].uniqueIdentifier;

                QHBoxLayout* projectLayout = new QHBoxLayout;

                QLabel* projectLabel = new QLabel;
                QPushButton* addButton = new QPushButton;

                projectLabel->setText(projects[projectIdx].name);
                projectLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                projectLabel->setMinimumHeight(50);

                bool currentlyAssigned = false;
                for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                    if (groups[groupIdx].ID != objID) { continue; }
                    for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                        if (groups[groupIdx].projects[groupProjectIdx] == projectIdentifier) {
                            currentlyAssigned = true;
                            break;
                        }
                    }
                    break;
                }
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);

                connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton] { changeListing(projectIdentifier, addButton); });

                projectLayout->addWidget(projectLabel);
                projectLayout->addWidget(addButton);

                ui->pageFrame_2->addLayout(projectLayout);
            }
        } else if (selectionType == 1) {
            for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
                int projectIdentifier = projects[projectIdx].uniqueIdentifier;
                for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                    int ticketIdentifier = projects[projectIdx].tickets[ticketIdx].creationTime;
                    QHBoxLayout* ticketLayout = new QHBoxLayout;

                    QLabel* ticketLabel = new QLabel;
                    QPushButton* addButton = new QPushButton;

                    ticketLabel->setText(projects[projectIdx].tickets[ticketIdx].title);
                    ticketLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                    ticketLabel->setMinimumHeight(50);

                    bool currentlyAssigned = false;
                    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                        if (groups[groupIdx].ID != objID) { continue; }
                        for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                            if (groups[groupIdx].tickets[groupTicketIdx].ticketID == ticketIdentifier &&
                                    groups[groupIdx].tickets[groupTicketIdx].projectID == projectIdentifier) {
                                currentlyAssigned = true;
                                break;
                            }
                        }
                        break;
                    }
                    if (currentlyAssigned) {
                        addButton->setText("Remove");
                        addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                    } else {
                        addButton->setText("Add");
                        addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                    }
                    addButton->setMinimumWidth(200);
                    addButton->setMaximumWidth(200);
                    addButton->setMinimumHeight(50);

                    connect(addButton, &QPushButton::clicked, [this, projectIdentifier, addButton, ticketIdentifier] { changeListing(projectIdentifier, addButton, ticketIdentifier); });

                    ticketLayout->addWidget(ticketLabel);
                    ticketLayout->addWidget(addButton);

                    ui->pageFrame_2->addLayout(ticketLayout);
                }
            }
        } else if (selectionType == 2) {
            for (int userIdx = 0; userIdx < users.size(); userIdx++) {
                int userID = users[userIdx].uniqueIdentifier;
                bool currentlyAssigned = false;

                QHBoxLayout* userLayout = new QHBoxLayout;

                QLabel* userLabel = new QLabel;
                QPushButton* addButton = new QPushButton;

                userLabel->setText(users[userIdx].username);
                userLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                userLabel->setMinimumHeight(50);

                for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                    if (groups[groupIdx].ID != objID) { continue; }
                    for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size(); groupUserIdx++) {
                        if (groups[groupIdx].users[groupUserIdx] == userID) {
                            currentlyAssigned = true;
                            break;
                        }
                    }
                    break;
                }
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);

                connect(addButton, &QPushButton::clicked, [this, userID, addButton] { changeListing(userID, addButton); });

                userLayout->addWidget(userLabel);
                userLayout->addWidget(addButton);

                ui->pageFrame_2->addLayout(userLayout);
            }
        }

    }
    else if (selectionType <= 4) {
        ui->backButton->setText("< Projects");
        if (selectionType == 3) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                int groupIdentifier = groups[groupIdx].ID;
                QHBoxLayout* groupLayout = new QHBoxLayout;

                QLabel* groupLabel = new QLabel;
                QPushButton* addButton = new QPushButton;

                groupLabel->setText(groups[groupIdx].name);
                groupLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                groupLabel->setMinimumHeight(50);

                bool currentlyAssigned = false;
                for (int projectIdx = 0; projectIdx < groups[groupIdx].projects.size(); projectIdx++) {
                    if (groups[groupIdx].projects[projectIdx] == objID) { currentlyAssigned = true; }
                }
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);

                connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });

                groupLayout->addWidget(groupLabel);
                groupLayout->addWidget(addButton);

                ui->pageFrame_2->addLayout(groupLayout);
            }
        }
    }
    else if (selectionType <= 7) {
        ui->backButton->setText("< Users");
        if (selectionType == 6) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                int groupIdentifier = groups[groupIdx].ID;
                QHBoxLayout* groupLayout = new QHBoxLayout;

                QLabel* groupLabel = new QLabel;
                QPushButton* addButton = new QPushButton;

                groupLabel->setText(groups[groupIdx].name);
                groupLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                groupLabel->setMinimumHeight(50);

                bool currentlyAssigned = false;
                for (int userIdx = 0; userIdx < groups[groupIdx].users.size(); userIdx++) {
                    if (groups[groupIdx].users[userIdx] == objID) { currentlyAssigned = true; }
                }
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);

                connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });

                groupLayout->addWidget(groupLabel);
                groupLayout->addWidget(addButton);

                ui->pageFrame_2->addLayout(groupLayout);
            }
        }
    } else {
        ui->backButton->setText("< Ticket");
        if (selectionType == 9) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                int groupIdentifier = groups[groupIdx].ID;
                QHBoxLayout* groupLayout = new QHBoxLayout;

                QLabel* groupLabel = new QLabel;
                QPushButton* addButton = new QPushButton;

                groupLabel->setText(groups[groupIdx].name);
                groupLabel->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
                groupLabel->setMinimumHeight(50);

                bool currentlyAssigned = false;
                for (int ticketIdx = 0; ticketIdx < groups[groupIdx].tickets.size(); ticketIdx++) {
                    if (groups[groupIdx].tickets[ticketIdx].ticketID == objID) { currentlyAssigned = true; }
                }
                if (currentlyAssigned) {
                    addButton->setText("Remove");
                    addButton->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
                } else {
                    addButton->setText("Add");
                    addButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
                }
                addButton->setMinimumWidth(200);
                addButton->setMaximumWidth(200);
                addButton->setMinimumHeight(50);

                connect(addButton, &QPushButton::clicked, [this, groupIdentifier, addButton] { changeListing(groupIdentifier, addButton); });

                groupLayout->addWidget(groupLabel);
                groupLayout->addWidget(addButton);

                ui->pageFrame_2->addLayout(groupLayout);
            }
        }
    }
}

ManagementSelection::~ManagementSelection()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void ManagementSelection::changeListing(int id, QPushButton* button, int secondaryID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::Group> groups = myFiles.loadGroups();

    if (button->text() == "Add") {
        button->setText("Remove");
        button->setStyleSheet("background-color:white; border:0px; color:#CA0736; font-weight: bold; font-size:24px;");
        if (type == 0) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                groups[groupIdx].projects.push_back(id);
                break;
            }
        } else if (type == 1) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = secondaryID;
                newTicket.projectID = id;
                groups[groupIdx].tickets.push_back(newTicket);
                break;
            }
        } else if (type == 2) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                groups[groupIdx].users.push_back(id);
                break;
            }
        } else if (type == 3) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                groups[groupIdx].projects.push_back(objID);
                break;
            }
        } else if (type == 6) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                groups[groupIdx].users.push_back(objID);
            }
        } else if (type == 9) {
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
            }
        }
    } else {
        button->setText("Add");
        button->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
        if (type == 0) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == id) {
                        groups[groupIdx].projects.removeAt(groupProjectIdx);
                        break;
                    }
                }
                break;
            }
        } else if (type == 1) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                    if (groups[groupIdx].tickets[groupTicketIdx].projectID == id &&
                            groups[groupIdx].tickets[groupTicketIdx].ticketID == secondaryID) {
                        groups[groupIdx].tickets.removeAt(groupTicketIdx);
                        break;
                    }
                }
                break;
            }
        } else if (type == 2) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != objID) { continue; }
                for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size(); groupUserIdx++) {
                    if (groups[groupIdx].users[groupUserIdx] == id) {
                        groups[groupIdx].users.removeAt(groupUserIdx);
                        break;
                    }
                }
                break;
            }
        } else if (type == 3) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == objID) {
                        groups[groupIdx].projects.removeAt(groupProjectIdx);
                        break;
                    }
                }
                break;
            }
        } else if (type == 6) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID != id) { continue; }
                for (int groupUserIdx = 0; groupUserIdx < groups[groupIdx].users.size(); groupUserIdx++) {
                    if (groups[groupIdx].users[groupUserIdx] == objID) {
                        groups[groupIdx].users.removeAt(groupUserIdx);
                        break;
                    }
                }
            }
        } else if (type == 9) {
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
                }
                break;
            }
        }
    }

    myFiles.saveGroups(groups);
    myFiles.saveProjects(myFiles.compileProjects(projects));
}

void ManagementSelection::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ManagementSelection::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ManagementSelection::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ManagementSelection::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void ManagementSelection::on_backButton_clicked()
{
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
    myFiles.saveState(state);
    closing = false;
    this->close();
}


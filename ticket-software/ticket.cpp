#include "ticket.h"
#include "ui_ticket.h"
// Included Qt modules
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>
// Ticket constructor
Ticket::Ticket(int projectID, int ticketID, QWidget *parent) : QWidget(parent), ui(new Ui::Ticket) {
    ui->setupUi(this);

    IDProject = projectID;
    IDTicket = ticketID;
    // Loads projects
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Finds given ticket
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                // Shows given ticket
                ui->titleText->setText(projects[projectIdx].tickets[ticketIdx].title);
                ui->descriptionText->setText(projects[projectIdx].tickets[ticketIdx].description);

                QDateTime date = QDateTime::fromSecsSinceEpoch(ticketID);
                QString formattedTime = date.toString("dd/MM/yyyy");
                QString details = "Created on " + formattedTime + " - " +
                        projects[projectIdx].tickets[ticketIdx].system + " - " +
                        projects[projectIdx].name + " - " +
                        projects[projectIdx].tickets[ticketIdx].progress;
                ui->detailsText->setText(details);
                // Switches open ticket button if ticket is archived
                if (!projects[projectIdx].tickets[ticketIdx].isOpen) {
                    ui->archiveButton->setText("Re-open Ticket");
                    ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:rgb(255, 255, 255); border-radius:1px;");
                }
                // Shows current ticket priority
                switch (projects[projectIdx].tickets[ticketIdx].priority) {
                case 0:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/unknownIcon.png"));
                    break;
                case 1:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/notificationIcon.png"));
                    break;
                case 2:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/emergencyIcon.png"));
                    break;
                }
                break;
            }
        }
    }

    // Hides management button if user access level is too low
    FileManager::StateData state = myFiles.loadState();
    int userAccessLevel = myFiles.getAccessLevel(state.userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
        ui->assignUserButton->hide();
        ui->assignGroupButton->hide();
        if (userAccessLevel < 1) { // Hides archive button / disables priority button if level too low
            ui->archiveButton->hide();
            ui->priorityButton->setDisabled(true);
        }
    }

    // Displays all users assigned to ticket
    QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();
    QVector<FileManager::User> users = myFiles.loadUsers();

    for (int userRelationIdx = 0; userRelationIdx < userRelations.size(); userRelationIdx++) {
        for (int ticketIdx = 0; ticketIdx < userRelations[userRelationIdx].tickets.size(); ticketIdx++) {
            if (userRelations[userRelationIdx].tickets[ticketIdx].projectID == IDProject &&
                userRelations[userRelationIdx].tickets[ticketIdx].ticketID == IDTicket) {
                // Displays assigned user username
                QHBoxLayout* userBoxLayout = new QHBoxLayout;
                userBoxLayout->addStretch(1);
                QPushButton* userButton = new QPushButton;
                userButton->setStyleSheet("font-size: 24px;font-family: Inter;color:white; font-weight:bold; border:none;");
                userButton->setLayoutDirection(Qt::RightToLeft);
                userButton->setObjectName("assignedUser");
                int userID = userRelations[userRelationIdx].uniqueIdentifier;
                connect(userButton, &QPushButton::clicked, [this, userID] { openUser(userID); });
                // Displays assigned user profile pic
                for (int userIdx = 0; userIdx < users.size(); userIdx++) {
                    if (users[userIdx].uniqueIdentifier == userRelations[userRelationIdx].uniqueIdentifier) {
                        userButton->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png"));
                        userButton->setIconSize(QSize(50, 50));
                        userButton->setText(users[userIdx].username + " ");
                        break;
                    }
                }
                // Draws user
                userBoxLayout->addWidget(userButton);
                ui->userList->addLayout(userBoxLayout);
                // Updates self-assign button if logged in user is currently assigned to ticket
                if (userRelations[userRelationIdx].uniqueIdentifier == state.userID) {
                    ui->assignSelfButton->setText("Unassign");
                    ui->assignSelfButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:white; border-radius:1px; margin-right:10px;");
                }
                break;
            }
        }
    }
    // Display ticket logs
    reloadLogs();
}

// Ticket destructor
Ticket::~Ticket() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Display all ticket logs
void Ticket::reloadLogs() {
    // Delete existing log text
    QVector<QLabel*> list = ui->assignedItems->findChildren<QLabel *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < list.size(); widIdx++) {
        if (list.at(widIdx)->objectName() == "logStuff") { delete list.at(widIdx); }
    }
    // Delete existing log buttons
    QVector<QPushButton*> listB = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < listB.size(); widIdx++) {
        if (listB.at(widIdx)->objectName() == "logStuff") { delete listB.at(widIdx); }
    }
    // Draw new logs
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                for (int logIdx = projects[projectIdx].tickets[ticketIdx].logs.size()-1; logIdx >= 0; logIdx--) {
                    if (projects[projectIdx].tickets[ticketIdx].logs[logIdx].isConsole) { // Draw new console log
                        QLabel *logDetails = new QLabel(this);
                        logDetails->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        QDateTime date = QDateTime::fromSecsSinceEpoch(projects[projectIdx].tickets[ticketIdx].logs[logIdx].creationTime);
                        QString formattedTime = date.toString("dd/MM/yyyy");
                        logDetails->setText(projects[projectIdx].tickets[ticketIdx].logs[logIdx].description + " on " + formattedTime);
                        QPushButton *logUser = new QPushButton(this);
                        QPushButton *logUserIcon = new QPushButton(this);
                        logUser->setText("Deleted");
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        int userID = projects[projectIdx].tickets[ticketIdx].logs[logIdx].uniqueIdentifier;
                        // Draws log creator profile picture
                        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
                            if (userID == users[userIdx].uniqueIdentifier) {
                                logUser->setText(users[userIdx].username);
                                logUserIcon->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png"));
                            }
                        }
                        logUser->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:#32ACBE; border:0px;height:24px; padding:5px; text-align:right;");
                        logUserIcon->setStyleSheet("height:24px; padding:5px; border:0px; background-color:#32ACBE;");
                        logUserIcon->setMaximumWidth(35);
                        logUserIcon->setIconSize(QSize(25, 25));
                        // Stores log items in layout
                        QHBoxLayout *logInfoLayout = new QHBoxLayout();
                        logInfoLayout->addWidget(logDetails);
                        logInfoLayout->addWidget(logUser);
                        logInfoLayout->addWidget(logUserIcon);
                        // Saves layout to UI
                        ui->posts->addLayout(logInfoLayout);
                        // Applys object names for when deletion is needed
                        logDetails->setObjectName("logStuff");
                        logUser->setObjectName("logStuff");
                        logUserIcon->setObjectName("logStuff");
                    } else { // Draw new user log
                        QLabel *logText = new QLabel(this);
                        logText->setStyleSheet("font-size: 24px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        logText->setText(projects[projectIdx].tickets[ticketIdx].logs[logIdx].description);
                        QLabel *logDetails = new QLabel(this);
                        logDetails->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; padding:5px; background-color:#32ACBE;");
                        QDateTime date = QDateTime::fromSecsSinceEpoch(projects[projectIdx].tickets[ticketIdx].logs[logIdx].creationTime);
                        QString formattedTime = date.toString("dd/MM/yyyy");
                        logDetails->setText("Posted on " + formattedTime);
                        QPushButton *logUser = new QPushButton(this);
                        QPushButton *logUserIcon = new QPushButton(this);
                        logUser->setText("Deleted");
                        logUserIcon->setIcon(QIcon(":/Image/Images/placeholderProfileIcon.png"));
                        int userID = projects[projectIdx].tickets[ticketIdx].logs[logIdx].uniqueIdentifier;
                        // Draws log creator profile picture
                        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
                            if (userID == users[userIdx].uniqueIdentifier) {
                                logUser->setText(users[userIdx].username);
                                logUserIcon->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png"));
                            }
                        }
                        logUser->setStyleSheet("font-size: 18px;font-family: Inter;color: #D4F8F6; font-weight:lighter; background-color:#32ACBE; border:0px;height:24px; padding:5px; text-align:right;");
                        logUserIcon->setStyleSheet("height:24px; padding:5px; border:0px; background-color:#32ACBE;");
                        logUserIcon->setMaximumWidth(35);
                        logUserIcon->setIconSize(QSize(25, 25));
                        // Stores log items in layout
                        QHBoxLayout *logInfoLayout = new QHBoxLayout();
                        logInfoLayout->addWidget(logDetails);
                        logInfoLayout->addWidget(logUser);
                        logInfoLayout->addWidget(logUserIcon);
                        // Saves layout to UI
                        ui->posts->addWidget(logText);
                        ui->posts->addLayout(logInfoLayout);
                        // Applys object names for when deletion is needed
                        logText->setObjectName("logStuff");
                        logDetails->setObjectName("logStuff");
                        logUser->setObjectName("logStuff");
                        logUserIcon->setObjectName("logStuff");
                    }
                    // Adds spacing between each log
                    QLabel *logSpacing = new QLabel(this);
                    logSpacing->setObjectName("logStuff");
                    logSpacing->setStyleSheet("background-color:transparent; font-size:10px;");
                    ui->posts->addWidget(logSpacing);
                }
            }
        }
    }
}

// Adds new log to ticket
void Ticket::on_postButton_clicked() {
    if (ui->postEntryText->toPlainText().size() == 0) { // Displays error if log is blank
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return; // Stops log from being added
    }
    // Loads all projects
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Creates new log
    FileManager::Log newLog;
    newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
    newLog.description = ui->postEntryText->toPlainText();
    newLog.uniqueIdentifier = myFiles.loadState().userID;
    newLog.isConsole = false;
    // Saves log to ticket
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
            }
        }
    }
    // Writes changes
    myFiles.saveProjects(myFiles.compileProjects(projects));
    // Displays changed logs
    reloadLogs();
}

// Opens assignments page
void Ticket::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void Ticket::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void Ticket::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void Ticket::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Archives / Re-opens ticket
void Ticket::on_archiveButton_clicked() {
    bool isOpen = false;
    // Checks if ticket is currently archived
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                // Adds log stating whether ticket was just archived or unarchived
                projects[projectIdx].tickets[ticketIdx].isOpen = !projects[projectIdx].tickets[ticketIdx].isOpen;
                isOpen = projects[projectIdx].tickets[ticketIdx].isOpen;
                FileManager::Log newLog;
                newLog.creationTime = QDateTime::currentDateTime().toSecsSinceEpoch();
                newLog.description = isOpen ? "Ticket re-opened" : "Ticket closed";
                newLog.uniqueIdentifier = myFiles.loadState().userID;
                newLog.isConsole = true;
                projects[projectIdx].tickets[ticketIdx].logs.append(newLog);
            }
        }
    }
    // Writes new log to disk
    myFiles.saveProjects(myFiles.compileProjects(projects));
    if (isOpen) { // Change archive button to default format
        ui->archiveButton->setText("Close Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#CA0736; border-radius:1px;");
    } else { // Changes archive button to re-open format
        ui->archiveButton->setText("Re-open Ticket");
        ui->archiveButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:rgb(255, 255, 255); border-radius:1px;");
    }
    // Update displayed logs
    reloadLogs();
}

// Open managementSelection page for ticket groups
void Ticket::on_assignGroupButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 9;
    state.secondaryPageData = IDTicket;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Changes ticket priority
void Ticket::on_priorityButton_clicked() {
    // Finds ticket in projects DB
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier != IDProject) { continue; }
        for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
            // Changes ticket priority
            if (projects[projectIdx].tickets[ticketIdx].creationTime == IDTicket) {
                projects[projectIdx].tickets[ticketIdx].priority += projects[projectIdx].tickets[ticketIdx].priority == 2 ? -2 : 1;
                // Updates priority button icon
                switch (projects[projectIdx].tickets[ticketIdx].priority) {
                case 0:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/unknownIcon.png"));
                    break;
                case 1:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/notificationIcon.png"));
                    break;
                case 2:
                    ui->priorityButton->setIcon(QIcon(":/Images/Images/emergencyIcon.png"));
                    break;
                }
            }
        }
    }
    // Save priority change
    myFiles.saveProjects(myFiles.compileProjects(projects));
}

// Open managementSelection page for user groups
void Ticket::on_assignUserButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 8;
    state.secondaryPageData = IDTicket;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Assign / remove self from ticket
void Ticket::on_assignSelfButton_clicked() {
    FileManager myFiles;
    QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();
    // Retrieve logged in user
    FileManager::StateData state = myFiles.loadState();
    // Loads all users
    QVector<FileManager::User> users = myFiles.loadUsers();

    if (ui->assignSelfButton->text() == "Self-Assign") { // Assign self to ticket
        ui->assignSelfButton->setText("Unassign");
        ui->assignSelfButton->setStyleSheet("font-size: 24px;font-family: Inter;color:#CA0736; font-weight:bold; border:none; background-color:white; border-radius:1px; margin-right:10px;");
        // Adds user-ticket relation
        for (int userRelationIdx = 0; userRelationIdx < userRelations.size(); userRelationIdx++) {
            if (userRelations[userRelationIdx].uniqueIdentifier == state.userID) {
                FileManager::TicketIDs newTicket;
                newTicket.ticketID = IDTicket;
                newTicket.projectID = IDProject;
                userRelations[userRelationIdx].tickets.push_back(newTicket);
                break;
            }
        }
    } else { // Remove self from ticket
        ui->assignSelfButton->setText("Self-Assign");
        ui->assignSelfButton->setStyleSheet("font-size: 24px;font-family: Inter;color: rgb(255, 255, 255); font-weight:bold; border:none; background-color:#32ACBE; border-radius:1px; margin-right:10px;");
        // Remove user-ticket relation
        for (int userRelationIdx = 0; userRelationIdx < userRelations.size(); userRelationIdx++) {
            if (userRelations[userRelationIdx].uniqueIdentifier == state.userID) {
                for (int ticketIdx = 0; ticketIdx < userRelations[userRelationIdx].tickets.size(); ticketIdx++) {
                    if (userRelations[userRelationIdx].tickets[ticketIdx].ticketID == IDTicket &&
                        userRelations[userRelationIdx].tickets[ticketIdx].projectID == IDProject) {
                        userRelations[userRelationIdx].tickets.removeAt(ticketIdx);
                        break;
                    }
                }
                break;
            }
        }
    }
    // Save userRelations changes
    myFiles.saveUserRelations(userRelations);
    // Delete all assigned users from UI
    QVector<QPushButton*> buttons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < buttons.size(); widIdx++) {
        if (buttons.at(widIdx)->objectName() == "assignedUser") { delete buttons.at(widIdx); }
    }
    // Re-add assigned users
    for (int userRelationIdx = 0; userRelationIdx < userRelations.size(); userRelationIdx++) {
        for (int ticketIdx = 0; ticketIdx < userRelations[userRelationIdx].tickets.size(); ticketIdx++) {
            if (userRelations[userRelationIdx].tickets[ticketIdx].projectID == IDProject &&
                userRelations[userRelationIdx].tickets[ticketIdx].ticketID == IDTicket) {
                // Draws new user
                QHBoxLayout* userBoxLayout = new QHBoxLayout;
                userBoxLayout->addStretch(1);
                QPushButton* userButton = new QPushButton;
                userButton->setStyleSheet("font-size: 24px;font-family: Inter;color:white; font-weight:bold; border:none;");
                userButton->setLayoutDirection(Qt::RightToLeft);
                userButton->setObjectName("assignedUser");
                int userID = userRelations[userRelationIdx].uniqueIdentifier;
                connect(userButton, &QPushButton::clicked, [this, userID] { openUser(userID); });
                // Draws new user profile picture
                for (int userIdx = 0; userIdx < users.size(); userIdx++) {
                    if (users[userIdx].uniqueIdentifier == userRelations[userRelationIdx].uniqueIdentifier) {
                        userButton->setIcon(QIcon(":/Images/Images/PFP/" + myFiles.getAvatar(users[userIdx].profilePicID) + ".png"));
                        userButton->setIconSize(QSize(50, 50));
                        userButton->setText(users[userIdx].username + " ");
                        break;
                    }
                }
                // Adds new user to UI
                userBoxLayout->addWidget(userButton);
                ui->userList->addLayout(userBoxLayout);
                break;
            }
        }
    }
}

// Opens profile viewing page
void Ticket::openUser(int userID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 12;
    state.pageData = userID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


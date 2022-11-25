#include "assignments.h"
#include "ui_assignments.h"

#include <QDebug>

// Assignments constructor
Assignments::Assignments(QWidget *parent) : QWidget(parent), ui(new Ui::Assignments) {
    ui->setupUi(this);
    // Hides management button if user access level is too low
    FileManager myFiles;
    int userAccessLevel = myFiles.getAccessLevel(myFiles.loadState().userID);
    if (userAccessLevel < 2) {
        ui->managementButton->hide();
        ui->line_8->hide();
    }
}

// Assignments destructor
Assignments::~Assignments() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Displays / hides assigned tickets
void Assignments::on_ticketsButton_toggled(bool checked)
{
    if (checked == false) { // Hides tickets
        ui->ticketsButton->setText("Tickets                                                                                                            ►");
        // Deletes all existing tickets
        QObjectList list = ui->assignedItems->widget()->children();
        for (int i = 0; i < list.size(); i++) {
            QString name = list.at(i)->objectName();
            if (name.contains("displayedTicket")) {
                delete list.at(i);
            }
        }
    } else { // Shows tickets
        ui->ticketsButton->setText("Tickets                                                                                                            ▼");
        // Creates all ticket UI elements
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();
        FileManager::StateData state = myFiles.loadState();
        // Loops through all tickets in all projects
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                int projectID = projects[projectIdx].uniqueIdentifier;
                int ticketID = projects[projectIdx].tickets[ticketIdx].creationTime;
                // Checks if ticket is assigned to user
                bool assigned = false;
                for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !assigned; userRelationIdx++) {
                    if (userRelations[userRelationIdx].uniqueIdentifier == state.userID) {
                        for (int ticketRelationIdx = 0; ticketRelationIdx < userRelations[userRelationIdx].tickets.size() && !assigned; ticketRelationIdx++) {
                            if (userRelations[userRelationIdx].tickets[ticketRelationIdx].ticketID == ticketID &&
                                userRelations[userRelationIdx].tickets[ticketRelationIdx].projectID == projectID) {
                                assigned = true;
                            }
                        }
                    }
                }
                if (!projects[projectIdx].tickets[ticketIdx].isOpen || !assigned) { continue; }
                // Draw new ticket button
                QPushButton* button = new QPushButton(this);
                button->setObjectName("displayedTicket" + QString::number(ticketIdx));
                button->setText(projects[projectIdx].tickets[ticketIdx].title);
                button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
                connect(button, &QPushButton::clicked, [this, projectID, ticketID] { openTicket(projectID, ticketID); });
                // Draws ticket metadata
                QLabel *label = new QLabel("metadata", button);
                QDateTime date = QDateTime::fromSecsSinceEpoch(projects[projectIdx].tickets[ticketIdx].creationTime);
                QString formattedTime = date.toString("dd/MM/yyyy");
                QString metadataString = "Created on: ";
                metadataString += formattedTime + " - ";
                metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
                metadataString += projects[projectIdx].name + " - ";
                metadataString += projects[projectIdx].tickets[ticketIdx].progress;
                label->setText(metadataString);
                label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
                // Adds ticket to UI
                ui->ticketsLayout->addWidget(button);
            }
        }
    }
}

// Shows / hides assigned groups
void Assignments::on_groupsButton_toggled(bool checked)
{
    if (checked == false) { // Hides groups
        ui->groupsButton->setText("Groups                                                                                                            ►");
        // Delets all group tabs
        QVector<QPushButton*> buttons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < buttons.size(); widIdx++) {
            if (buttons.at(widIdx)->objectName().contains("groupTicket")) { delete buttons.at(widIdx); }
        }
        // Delete all group ticket metadata
        QVector<QLabel*> labels = ui->assignedItems->findChildren<QLabel *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < labels.size(); widIdx++) {
            if (labels.at(widIdx)->objectName().contains("groupTicket")) { delete labels.at(widIdx); }
        }
        // Delete all group ticket buttons
        QVector<QWidget*> widgets = ui->assignedItems->findChildren<QWidget *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < widgets.size(); widIdx++) {
            if (widgets.at(widIdx)->objectName() == "displayedGroup") { delete widgets.at(widIdx); }
        }
    } else { // Shows groups
        ui->groupsButton->setText("Groups                                                                                                            ▼");
        // Loops through all groups
        FileManager myFiles;
        QVector<FileManager::Group> groups = myFiles.loadGroups();
        FileManager::StateData state = myFiles.loadState();
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            if (!groups[groupIdx].users.contains(state.userID)) { continue; } // Checks if group assigned to user
            // Draws group tab
            QWidget *groupParent = new QWidget();
            groupParent->setObjectName("displayedGroup");
            ui->groupsLayout->addWidget(groupParent);
            QVBoxLayout *layout = new QVBoxLayout(groupParent);
            layout->setContentsMargins(0, 0, 0, 0);
            QPushButton *button = new QPushButton(this);
            button->setText(groups[groupIdx].name);
            button->setStyleSheet("background-color: #010511; color: white; height: 75px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 20px; border:none;");
            int groupID = groups[groupIdx].ID;
            // Draws group arrow
            QLabel *label = new QLabel("groupIndicator", button);
            label->setText("►");
            label->setStyleSheet("font-family: Inter; font-size: 24px; text-align: right; margin-left:1208px; font-weight: normal; margin-top:25px;");
            connect(button, &QPushButton::clicked, [this, groupID, label, layout] { openGroup(groupID, label, layout); });
            // Adds group to UI
            layout->addWidget(button);
        }
    }
}

// Shows / hides group tickets
void Assignments::openGroup(int groupID, QLabel* groupArrow, QVBoxLayout* groupLayout) {
    if (groupArrow->text() == "►") { // Shows group tickets
        groupArrow->setText("▼");
        // Loops through all groups
        FileManager myFiles;
        QVector<FileManager::Group> groups = myFiles.loadGroups();
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
            if (groups[groupIdx].ID != groupID) { continue; } // Checks if group is requested group
            // Loops through all tickets in group
            for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                // Loops through all tickets in all projects
                for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
                    for (int ticketIdx = 0; ticketIdx < projects[projectIdx].tickets.size(); ticketIdx++) {
                        // Checks if ticket in group
                        if (projects[projectIdx].uniqueIdentifier == groups[groupIdx].tickets[groupTicketIdx].projectID &&
                                projects[projectIdx].tickets[ticketIdx].creationTime == groups[groupIdx].tickets[groupTicketIdx].ticketID) {
                            if (!projects[projectIdx].tickets[ticketIdx].isOpen) { continue; } // Checks if ticket is archived
                            // Draws new ticket button
                            QPushButton *button = new QPushButton(this);
                            button->setObjectName("groupTicket" + QString::number(groupID));
                            button->setText(projects[projectIdx].tickets[ticketIdx].title);
                            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
                            int projectID = projects[projectIdx].uniqueIdentifier;
                            int ticketID = projects[projectIdx].tickets[ticketIdx].creationTime;
                            connect(button, &QPushButton::clicked, [this, projectID, ticketID] { openTicket(projectID, ticketID); });
                            // Draws ticket metadata
                            QLabel *label = new QLabel("metadata", button);
                            QString metadataString = "Created on: 9/12/22 - ";
                            metadataString += projects[projectIdx].tickets[ticketIdx].system + " - ";
                            metadataString += projects[projectIdx].name + " - ";
                            metadataString += projects[projectIdx].tickets[ticketIdx].progress;
                            label->setText(metadataString);
                            label->setObjectName("groupTicket" + QString::number(groupID));
                            label->setStyleSheet("font-family: Inter; font-size: 18px; text-align: right; margin-left:550px; font-weight: normal; margin-top:16px;");
                            // Adds ticket to UI
                            groupLayout->addWidget(button);
                        }
                    }
                }
            }
        }
    } else { // Hides group tickets
        groupArrow->setText("►");
        // Hides all ticket buttons in group
        QVector<QPushButton*> buttons = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < buttons.size(); widIdx++) {
            if (buttons.at(widIdx)->objectName() == "groupTicket" + QString::number(groupID)) { delete buttons.at(widIdx); }
        }
        // Hides all ticket labels in group
        QVector<QLabel*> labels = ui->assignedItems->findChildren<QLabel *>(QString(), Qt::FindChildrenRecursively);
        for (int widIdx = 0; widIdx < labels.size(); widIdx++) {
            if (labels.at(widIdx)->objectName() == "groupTicket" + QString::number(groupID)) { delete labels.at(widIdx); }
        }
    }
}

// Hides / shows all assigned projects
void Assignments::on_projectsButton_toggled(bool checked) {
    if (checked == false) { // Hides projects
        ui->projectsButton->setText("Projects                                                                                                           ►");
        // Deletes all displayed projects
        QObjectList list = ui->assignedItems->widget()->children();
        for (int i = 0; i < list.size(); i++) {
            QString name = list.at(i)->objectName();
            if (name.contains("displayedProject")) {
                delete list.at(i);
            }
        }
    } else { // Shows projects
        ui->projectsButton->setText("Projects                                                                                                           ▼");
        // Loops through all projects
        FileManager myFiles;
        QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
        QVector<FileManager::Group> groups = myFiles.loadGroups();
        QVector<FileManager::UserRelations> userRelations = myFiles.loadUserRelations();
        FileManager::StateData state = myFiles.loadState();
        for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
            bool assigned = false;
            // Checks if project in group that user assigned too
            for (int groupIdx = 0; groupIdx < groups.size() && !assigned; groupIdx++) {
                if (groups[groupIdx].projects.contains(projects[projectIdx].uniqueIdentifier)
                    && groups[groupIdx].users.contains(state.userID)) { assigned = true; }
            }
            // Checks if project assigned to user
            for (int userRelationIdx = 0; userRelationIdx < userRelations.size() && !assigned; userRelationIdx++) {
                if (userRelations[userRelationIdx].uniqueIdentifier == state.userID) {
                    if (userRelations[userRelationIdx].projects.contains(projects[projectIdx].uniqueIdentifier)) { assigned = true; }
                    break;
                }
            }
            if (!assigned) { continue; }
            // Draws new project button
            QPushButton *button = new QPushButton(this);
            button->setObjectName("displayedProject" + QString::number(projectIdx));
            button->setText(projects[projectIdx].name);
            button->setStyleSheet("background-color: #32ACBE; color: white; height: 50px; font-family: Inter; font-size: 24px; font-weight: bold; text-align: left; padding-left: 10px; border:none;");
            int projectIdentifer = projects[projectIdx].uniqueIdentifier;
            connect(button, &QPushButton::clicked, [this, projectIdentifer] { on_projectButton_triggered(projectIdentifer); });
            // Adds project to UI
            ui->projectsLayout->addWidget(button);
        }
    }
}

// Opens project page
void Assignments::on_projectButton_triggered(int id) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = id;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void Assignments::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void Assignments::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void Assignments::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens ticket page
void Assignments::openTicket(int projectID, int ticketID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 4;
    state.pageData = projectID;
    state.secondaryPageData = ticketID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

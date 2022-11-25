#include "projectmanagement.h"
#include "ui_projectmanagement.h"

// ProjectManagement constructor
ProjectManagement::ProjectManagement(QWidget *parent) : QWidget(parent), ui(new Ui::ProjectManagement) {
    ui->setupUi(this);
    reloadProjects();
}

// Loads project information
void ProjectManagement::reloadProjects() {
    // Deletes existing project information
    QVector<QPushButton*> listB = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < listB.size(); widIdx++) {
        if (listB.at(widIdx)->objectName() == "projectInfo") { delete listB.at(widIdx); }
    }
    // Loads new information
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    // Loops through all projects
    for (int projectIdx = 0; projects.size() > projectIdx; projectIdx++) {
        int projectIdentifer = projects[projectIdx].uniqueIdentifier;
        // Draws new project
        QHBoxLayout* projectLayout = new QHBoxLayout;

        QPushButton* projectButton = new QPushButton;
        QPushButton* groupsButton = new QPushButton;
        QPushButton* usersButton = new QPushButton;
        QPushButton* deleteButton = new QPushButton;
        // Formats projectButton
        projectButton->setText(projects[projectIdx].name);
        projectButton->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        projectButton->setMinimumHeight(50);
        projectButton->setObjectName("projectInfo");
        connect(projectButton, &QPushButton::clicked, [this, projectIdentifer] { openProject(projectIdentifer); });
        // Formats groupsButton
        groupsButton->setText("Groups");
        groupsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        groupsButton->setMaximumWidth(100);
        groupsButton->setMinimumHeight(50);
        groupsButton->setObjectName("projectInfo");
        connect(groupsButton, &QPushButton::clicked, [this, projectIdentifer] { openProjectGroups(projectIdentifer); });
        // Formats userButton
        usersButton->setText("Users");
        usersButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
        usersButton->setMaximumWidth(100);
        usersButton->setMinimumHeight(50);
        usersButton->setObjectName("projectInfo");
        connect(usersButton, &QPushButton::clicked, [this, projectIdentifer] { openProjectUsers(projectIdentifer); });
        // Formats deleteButton
        deleteButton->setIcon(QIcon(":/Image/Images/trashIcon.png"));
        deleteButton->setStyleSheet("background-color:transparent; border:0px;");
        deleteButton->setIconSize(QSize(50, 50));
        deleteButton->setMaximumWidth(50);
        deleteButton->setObjectName("projectInfo");
        connect(deleteButton, &QPushButton::clicked, [this, projectIdentifer] { deleteProject(projectIdentifer); });
        // Adds project items to layout
        projectLayout->addWidget(projectButton);
        projectLayout->addWidget(groupsButton);
        projectLayout->addWidget(usersButton);
        projectLayout->addWidget(deleteButton);
        // Adds layout to UI
        ui->pageFrame_2->addLayout(projectLayout);
    }
}

// ProjectManagement destructor
ProjectManagement::~ProjectManagement() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}

// Opens managementSelection page for project groups
void ProjectManagement::openProjectGroups(int projectID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 3;
    state.secondaryPageData = projectID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens managementSelection page for project users
void ProjectManagement::openProjectUsers(int projectID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 11;
    state.pageData = 4;
    state.secondaryPageData = projectID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Creates new project
void ProjectManagement::on_createProjectButton_clicked() {
    if (ui->newProjectName->text().size() == 0) { // Stops project with no name from being created
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }
    // Saves new project
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    FileManager::Project newProject;
    newProject.description = "A new project";
    newProject.name = ui->newProjectName->text();
    newProject.uniqueIdentifier = projects.size() == 0 ? 0 : projects[projects.size()-1].uniqueIdentifier+1;
    newProject.tickets = {};
    projects.push_back(newProject);
    // Writes new project to disk
    myFiles.saveProjects(myFiles.compileProjects(projects));
    // Updates page information
    reloadProjects();
}

// Deletes project
void ProjectManagement::deleteProject(int projectID) {
    // Loads projects
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier == projectID) {
            // Removes given project
            projects.removeAt(projectIdx);
            // Removes project from assigned groups
            QVector<FileManager::Group> groups = myFiles.loadGroups();
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                for (int groupProjectIdx = 0; groupProjectIdx < groups[groupIdx].projects.size(); groupProjectIdx++) {
                    if (groups[groupIdx].projects[groupProjectIdx] == projectID) {
                        groups[groupIdx].projects.removeAt(groupProjectIdx);
                        break;
                    }
                }
                for (int groupTicketIdx = 0; groupTicketIdx < groups[groupIdx].tickets.size(); groupTicketIdx++) {
                    if (groups[groupIdx].tickets[groupTicketIdx].projectID == projectID) {
                        groups[groupIdx].tickets.removeAt(groupTicketIdx);
                        break;
                    }
                }
            }
            // Writes group changes to disk
            myFiles.saveGroups(groups);
        }
    }
    // Writes project changes to disk
    myFiles.saveProjects(myFiles.compileProjects(projects));
    // Updates page information
    reloadProjects();
}

// Opens assignments page
void ProjectManagement::on_assignButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens profile page
void ProjectManagement::on_profileButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens management page
void ProjectManagement::on_managementButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Logs out user
void ProjectManagement::on_logoutButton_clicked() {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

// Opens given project page
void ProjectManagement::openProject(int projectID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = projectID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

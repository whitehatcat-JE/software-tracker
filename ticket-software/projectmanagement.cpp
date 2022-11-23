#include "projectmanagement.h"
#include "ui_projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectManagement)
{
    ui->setupUi(this);
    reloadProjects();
}

void ProjectManagement::reloadProjects() {
    QVector<QPushButton*> listB = ui->assignedItems->findChildren<QPushButton *>(QString(), Qt::FindChildrenRecursively);
    for (int widIdx = 0; widIdx < listB.size(); widIdx++) {
        if (listB.at(widIdx)->objectName() == "projectInfo") { delete listB.at(widIdx); }
    }
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projects.size() > projectIdx; projectIdx++) {
        int projectIdentifer = projects[projectIdx].uniqueIdentifier;

        QHBoxLayout* projectLayout = new QHBoxLayout;

        QPushButton* projectButton = new QPushButton;
        QPushButton* groupsButton = new QPushButton;
        QPushButton* usersButton = new QPushButton;
        QPushButton* deleteButton = new QPushButton;

        projectButton->setText(projects[projectIdx].name);
        projectButton->setStyleSheet("background-color:#CA0736; color:white; font-weight:bold; font-size:24px; border:0px; text-align:left; padding-left:10px;");
        projectButton->setMinimumHeight(50);
        projectButton->setObjectName("projectInfo");
        connect(projectButton, &QPushButton::clicked, [this, projectIdentifer] { openProject(projectIdentifer); });

        groupsButton->setText("Groups");
        groupsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        groupsButton->setMaximumWidth(100);
        groupsButton->setMinimumHeight(50);
        groupsButton->setObjectName("projectInfo");
        connect(groupsButton, &QPushButton::clicked, [this, projectIdentifer] { openProjectGroups(projectIdentifer); });

        usersButton->setText("Users");
        usersButton->setStyleSheet("background-color:#32ACBE; border:0px; color:white; font-weight: bold; font-size:24px;");
        usersButton->setMaximumWidth(100);
        usersButton->setMinimumHeight(50);
        usersButton->setObjectName("projectInfo");

        deleteButton->setIcon(QIcon(":/Image/Images/trashIcon.png"));
        deleteButton->setStyleSheet("background-color:transparent; border:0px;");
        deleteButton->setIconSize(QSize(50, 50));
        deleteButton->setMaximumWidth(50);
        deleteButton->setObjectName("projectInfo");
        connect(deleteButton, &QPushButton::clicked, [this, projectIdentifer] { deleteProject(projectIdentifer); });

        projectLayout->addWidget(projectButton);
        projectLayout->addWidget(groupsButton);
        projectLayout->addWidget(usersButton);
        projectLayout->addWidget(deleteButton);

        ui->pageFrame_2->addLayout(projectLayout);
    }
}

ProjectManagement::~ProjectManagement()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

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

void ProjectManagement::on_createProjectButton_clicked()
{
    if (ui->newProjectName->text().size() == 0) {
        QMessageBox::warning(
            this,
            tr("Missing Fields"),
            tr("Please fill in all fields first") );
        return;
    }

    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    FileManager::Project newProject;
    newProject.description = "A new project";
    newProject.name = ui->newProjectName->text();
    newProject.uniqueIdentifier = projects.size() == 0 ? 0 : projects[projects.size()-1].uniqueIdentifier+1;
    newProject.tickets = {};
    projects.push_back(newProject);
    myFiles.saveProjects(myFiles.compileProjects(projects));
    reloadProjects();
}

void ProjectManagement::deleteProject(int projectID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier == projectID) {
            projects.removeAt(projectIdx);
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
            myFiles.saveGroups(groups);
        }
    }
    myFiles.saveProjects(myFiles.compileProjects(projects));
    reloadProjects();
}

void ProjectManagement::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProjectManagement::on_profileButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 1;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProjectManagement::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void ProjectManagement::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

void ProjectManagement::openProject(int projectID) {
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 3;
    state.pageData = projectID;
    myFiles.saveState(state);
    closing = false;
    this->close();
}

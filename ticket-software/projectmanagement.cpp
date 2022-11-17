#include "projectmanagement.h"
#include "ui_projectmanagement.h"
#include "filemanager.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

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

        groupsButton->setText("Groups");
        groupsButton->setStyleSheet("background-color:white; border:0px; color:#32ACBE; font-weight: bold; font-size:24px;");
        groupsButton->setMaximumWidth(100);
        groupsButton->setMinimumHeight(50);
        groupsButton->setObjectName("projectInfo");

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
    FileManager myFiles;
    FileManager::StateData currentState;
    currentState.newPage = 0;
    myFiles.saveState(currentState);
    delete ui;
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
    newProject.uniqueIdentifier = projects[projects.size()-1].uniqueIdentifier+1;
    newProject.tickets = {};
    projects.push_back(newProject);
    myFiles.saveProjects(myFiles.compileProjects(projects));
    reloadProjects();
}

void ProjectManagement::deleteProject(int projectID) {
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    QVector<FileManager::Project> newProjects = {};
    for (int projectIdx = 0; projectIdx < projects.size(); projectIdx++) {
        if (projects[projectIdx].uniqueIdentifier == projectID) { continue; }
        newProjects.push_back(projects[projectIdx]);
    }
    myFiles.saveProjects(myFiles.compileProjects(newProjects));
    reloadProjects();
}

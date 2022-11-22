#ifndef PROJECTMANAGEMENT_H
#define PROJECTMANAGEMENT_H

#include <QWidget>
#include <QMessageBox>

#include "filemanager.h"

namespace Ui {
class ProjectManagement;
}

class ProjectManagement : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectManagement(QWidget *parent = nullptr);
    ~ProjectManagement();

private slots:
    void on_createProjectButton_clicked();

    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::ProjectManagement *ui;
    void reloadProjects();
    void deleteProject(int projectID);
    void openProject(int projectID);
    void openProjectGroups(int projectID);
    void openProjectUsers(int projectID);
    bool closing = true;
};

#endif // PROJECTMANAGEMENT_H

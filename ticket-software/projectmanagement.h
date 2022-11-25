#ifndef PROJECTMANAGEMENT_H
#define PROJECTMANAGEMENT_H
// Includes Qt types
#include <QWidget>
#include <QMessageBox>
// Includes file management system
#include "filemanager.h"

// Declares ProjectManagement class
namespace Ui { class ProjectManagement; }
class ProjectManagement : public QWidget {
    Q_OBJECT
public:
    explicit ProjectManagement(QWidget *parent = nullptr); // ProjectManagement class constructor
    ~ProjectManagement(); // ProjectManagement class destructor

private slots: // All slot connections from UI
    void on_createProjectButton_clicked();
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();

private: // Declarations used by ProjectManagement class methods
    Ui::ProjectManagement *ui;
    void reloadProjects();
    bool closing = true;
    // Methods used by dynamically created buttons
    void deleteProject(int projectID);
    void openProject(int projectID);
    void openProjectGroups(int projectID);
    void openProjectUsers(int projectID);
};
#endif // PROJECTMANAGEMENT_H

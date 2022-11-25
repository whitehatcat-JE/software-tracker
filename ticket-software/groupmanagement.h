#ifndef GROUPMANAGEMENT_H
#define GROUPMANAGEMENT_H
// Includes Qt types
#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
// Includes file management system
#include "filemanager.h"

// Declares GroupManagement class
namespace Ui { class GroupManagement; }
class GroupManagement : public QWidget {
    Q_OBJECT
public:
    explicit GroupManagement(QWidget *parent = nullptr); // GroupManagement class constructor
    ~GroupManagement(); // GroupManagement class destructor

private slots: // All slot connections from UI
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();
    void on_createGroupButton_clicked();

private: // Declarations used by GroupManagement class methods
    Ui::GroupManagement *ui;
    bool closing = true;
    void reloadGroups();
    // Methods used by dynamically created buttons
    void openGroupProjects(int groupID);
    void openGroupUsers(int groupID);
    void openGroupTickets(int groupID);
    void editGroup(int groupID, QLineEdit* textField, QPushButton* editButton);
    void deleteGroup(int groupID);
};
#endif // GROUPMANAGEMENT_H

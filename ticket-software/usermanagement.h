#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H
// Includes Qt types
#include <QWidget>
#include <QMessageBox>
// Includes file management system
#include "filemanager.h"

// Declares UserManagement class
namespace Ui { class UserManagement; }
class UserManagement : public QWidget {
    Q_OBJECT
public:
    explicit UserManagement(QWidget *parent = nullptr); // UserManagement class constructor
    ~UserManagement(); // UserManagement class destructor

private slots: // All slot connections from UI
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();
    void on_createUserButton_clicked();

private: // Declarations used by UserManagement class methods
    Ui::UserManagement *ui;
    bool closing = true;

    void reloadUsers();

    // Methods used by dynamically created buttons
    void deleteUser(int userID);
    void assignUserProjects(int userID);
    void assignUserGroups(int userID);
    void assignUserTickets(int userID);
    void incrementAccessLevel(int userID);
};
#endif // USERMANAGEMENT_H

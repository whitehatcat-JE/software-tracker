#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QWidget>
#include <QMessageBox>

#include "filemanager.h"

namespace Ui {
class UserManagement;
}

class UserManagement : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();

private slots:
    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

    void on_createUserButton_clicked();

private:
    Ui::UserManagement *ui;
    bool closing = true;

    void reloadUsers();
    void deleteUser(int userID);
    void assignUserProjects(int userID);
    void assignUserGroups(int userID);
    void assignUserTickets(int userID);
    void incrementAccessLevel(int userID);
};

#endif // USERMANAGEMENT_H

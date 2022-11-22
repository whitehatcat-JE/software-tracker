#ifndef GROUPMANAGEMENT_H
#define GROUPMANAGEMENT_H

#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>

#include "filemanager.h"

namespace Ui {
class GroupManagement;
}

class GroupManagement : public QWidget
{
    Q_OBJECT

public:
    explicit GroupManagement(QWidget *parent = nullptr);
    ~GroupManagement();

private slots:
    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

    void on_createGroupButton_clicked();

private:
    Ui::GroupManagement *ui;
    bool closing = true;
    void reloadGroups();
    void openGroupProjects(int groupID);
    void openGroupUsers(int groupID);
    void openGroupTickets(int groupID);
    void editGroup(int groupID, QLineEdit* textField, QPushButton* editButton);
    void deleteGroup(int groupID);
};

#endif // GROUPMANAGEMENT_H

#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QWidget>

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

private:
    Ui::UserManagement *ui;
    bool closing = true;
};

#endif // USERMANAGEMENT_H

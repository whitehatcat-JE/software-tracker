#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>

#include "filemanager.h"

namespace Ui {
class Management;
}

class Management : public QWidget
{
    Q_OBJECT

public:
    explicit Management(QWidget *parent = nullptr);
    ~Management();

private slots:
    void on_assignedButton_clicked();

    void on_profileButton_clicked();

    void on_logoutButton_clicked();

    void on_usersButton_clicked();

    void on_groupsButton_clicked();

    void on_projectsButton_clicked();

private:
    bool closing = true;

    Ui::Management *ui;
};

#endif // MANAGEMENT_H

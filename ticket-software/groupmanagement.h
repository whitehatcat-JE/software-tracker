#ifndef GROUPMANAGEMENT_H
#define GROUPMANAGEMENT_H

#include <QWidget>

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

private:
    Ui::GroupManagement *ui;
    bool closing = true;
};

#endif // GROUPMANAGEMENT_H

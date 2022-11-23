<<<<<<< Updated upstream
#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "filemanager.h"

namespace Ui {
class Assignments;
}

class Assignments : public QWidget
{
    Q_OBJECT
public:
    explicit Assignments(QWidget *parent = nullptr);
    ~Assignments();
private slots:
    void on_ticketsButton_toggled(bool checked);

    void on_groupsButton_toggled(bool checked);

    void on_projectsButton_toggled(bool checked);


    void on_logoutButton_clicked();

    void on_managementButton_clicked();

    void on_profileButton_clicked();

private:
    Ui::Assignments *ui;
    bool closing = true;
    void on_projectButton_triggered(int id);
    void openTicket(int projectID, int ticketID);
    void openGroup(int groupID, QLabel* groupArrow, QVBoxLayout* groupLayout);
};

#endif // ASSIGNMENTS_H
=======
#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QWidget>

namespace Ui {
class Assignments;
}

class Assignments : public QWidget
{
    Q_OBJECT

public:
    explicit Assignments(QWidget *parent = nullptr);
    ~Assignments();

private:
    Ui::Assignments *ui;
};

#endif // ASSIGNMENTS_H
>>>>>>> Stashed changes

#ifndef PROJECT_H
#define PROJECT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>

#include "filemanager.h"

namespace Ui {
class Project;
}

class Project : public QWidget
{
    Q_OBJECT

public:
    explicit Project(int projectID, QWidget *parent = nullptr);
    ~Project();

private slots:
    void on_lineEditPassword_textChanged(const QString &query);

    void on_detailsButton_toggled(bool checked);

    void on_detailsButton_2_toggled(bool checked);

    void on_assignButton_clicked();

    void on_profileButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

    void on_createTicketButton_clicked();

    void on_archiveButton_clicked();

private:
    Ui::Project *ui;
    int assignedIdentifier;
    bool closing = true;
    QVector<QPushButton*> displayedTickets;

    void openTicket(int ticketID);
};

#endif // PROJECT_H

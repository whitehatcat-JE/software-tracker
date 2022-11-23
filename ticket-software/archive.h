#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDateTime>

#include "filemanager.h"

namespace Ui {
class Archive;
}

class Archive : public QWidget
{
    Q_OBJECT

public:
    explicit Archive(int projectID, QWidget *parent = nullptr);
    ~Archive();

private slots:
    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::Archive *ui;
    int IDProject;

    void reloadTickets();
    bool closing = true;

    void reOpenTicket(int ticketID);
    void deleteTicket(int ticketID);
    void openTicket(int ticketID);
};

#endif // ARCHIVE_H

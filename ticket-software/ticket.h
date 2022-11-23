#ifndef TICKET_H
#define TICKET_H

#include <QWidget>
#include <QDateTime>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>

#include "filemanager.h"

namespace Ui {
class Ticket;
}

class Ticket : public QWidget
{
    Q_OBJECT

public:
    explicit Ticket(int projectID, int ticketID, QWidget *parent = nullptr);
    ~Ticket();

private slots:
    void on_postButton_clicked();
    void reloadLogs();

    void on_profileButton_clicked();

    void on_assignButton_clicked();

    void on_managementButton_clicked();

    void on_logoutButton_clicked();

    void on_archiveButton_clicked();

    void on_assignGroupButton_clicked();

private:
    Ui::Ticket *ui;
    int IDProject;
    int IDTicket;

    bool closing = true;
};

#endif // TICKET_H

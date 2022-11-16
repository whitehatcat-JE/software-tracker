#ifndef TICKET_H
#define TICKET_H

#include "filemanager.h"

#include <QWidget>
#include <QDateTime>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>

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
    void on_archiveButton_toggled(bool checked);

    void on_postButton_clicked();
    void reloadLogs();

private:
    Ui::Ticket *ui;
    int IDProject;
    int IDTicket;
};

#endif // TICKET_H

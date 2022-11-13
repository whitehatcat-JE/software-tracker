#ifndef TICKET_H
#define TICKET_H

#include <QWidget>
#include "filemanager.h"
#include <QDateTime>
#include <QByteArray>

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

private:
    Ui::Ticket *ui;
    int IDProject;
    int IDTicket;
};

#endif // TICKET_H

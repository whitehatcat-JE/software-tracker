#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QWidget>
#include "filemanager.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDateTime>

namespace Ui {
class Archive;
}

class Archive : public QWidget
{
    Q_OBJECT

public:
    explicit Archive(int projectID, QWidget *parent = nullptr);
    ~Archive();

private:
    Ui::Archive *ui;
    int IDProject;

    void reloadTickets();

    void reOpenTicket(int ticketID);
    void deleteTicket(int ticketID);
    void openTicket(int ticketID);
};

#endif // ARCHIVE_H

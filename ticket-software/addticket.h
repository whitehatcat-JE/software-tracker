#ifndef ADDTICKET_H
#define ADDTICKET_H

#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QByteArray>
#include <QMessageBox>

#include "filemanager.h"

namespace Ui {
class AddTicket;
}

class AddTicket : public QWidget
{
    Q_OBJECT

public:
    explicit AddTicket(int projectID, QWidget *parent = nullptr);
    ~AddTicket();

private slots:
    void on_createTicket_clicked();

    void on_backButton_clicked();

private:
    Ui::AddTicket *ui;
    int assignedIdentifier;
    bool closing = true;
};

#endif // ADDTICKET_H

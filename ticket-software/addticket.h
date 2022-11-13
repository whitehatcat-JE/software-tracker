#ifndef ADDTICKET_H
#define ADDTICKET_H

#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QByteArray>
#include <QMessageBox>

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

private:
    Ui::AddTicket *ui;
    int assignedIdentifier;
};

#endif // ADDTICKET_H

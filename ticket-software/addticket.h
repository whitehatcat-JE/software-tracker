#ifndef ADDTICKET_H
#define ADDTICKET_H

#include <QWidget>

namespace Ui {
class AddTicket;
}

class AddTicket : public QWidget
{
    Q_OBJECT

public:
    explicit AddTicket(QWidget *parent = nullptr);
    ~AddTicket();

private:
    Ui::AddTicket *ui;
};

#endif // ADDTICKET_H

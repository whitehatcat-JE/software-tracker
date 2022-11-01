#ifndef TICKET_H
#define TICKET_H

#include <QWidget>

namespace Ui {
class Ticket;
}

class Ticket : public QWidget
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = nullptr);
    ~Ticket();

private:
    Ui::Ticket *ui;
};

#endif // TICKET_H

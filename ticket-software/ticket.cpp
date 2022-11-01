#include "ticket.h"
#include "ui_ticket.h"

Ticket::Ticket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
}

Ticket::~Ticket()
{
    delete ui;
}

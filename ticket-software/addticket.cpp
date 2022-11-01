#include "addticket.h"
#include "ui_addticket.h"

AddTicket::AddTicket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTicket)
{
    ui->setupUi(this);
}

AddTicket::~AddTicket()
{
    delete ui;
}

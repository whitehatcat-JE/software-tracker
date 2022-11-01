#include "management.h"
#include "ui_management.h"

Management::Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Management)
{
    ui->setupUi(this);
}

Management::~Management()
{
    delete ui;
}

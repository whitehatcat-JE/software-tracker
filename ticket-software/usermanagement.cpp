#include "usermanagement.h"
#include "ui_usermanagement.h"

UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);
}

UserManagement::~UserManagement()
{
    delete ui;
}

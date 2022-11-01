#include "groupmanagement.h"
#include "ui_groupmanagement.h"

GroupManagement::GroupManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupManagement)
{
    ui->setupUi(this);
}

GroupManagement::~GroupManagement()
{
    delete ui;
}

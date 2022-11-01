#include "managementselection.h"
#include "ui_managementselection.h"

ManagementSelection::ManagementSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagementSelection)
{
    ui->setupUi(this);
}

ManagementSelection::~ManagementSelection()
{
    delete ui;
}

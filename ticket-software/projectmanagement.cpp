#include "projectmanagement.h"
#include "ui_projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectManagement)
{
    ui->setupUi(this);
}

ProjectManagement::~ProjectManagement()
{
    delete ui;
}

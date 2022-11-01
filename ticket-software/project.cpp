#include "project.h"
#include "ui_project.h"

Project::Project(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Project)
{
    ui->setupUi(this);
}

Project::~Project()
{
    delete ui;
}

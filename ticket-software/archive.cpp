#include "archive.h"
#include "ui_archive.h"

Archive::Archive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archive)
{
    ui->setupUi(this);
}

Archive::~Archive()
{
    delete ui;
}

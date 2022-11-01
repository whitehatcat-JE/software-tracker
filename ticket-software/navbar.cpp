#include "navbar.h"
#include "ui_navbar.h"

NavBar::NavBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavBar)
{
    ui->setupUi(this);
}

NavBar::~NavBar()
{
    delete ui;
}

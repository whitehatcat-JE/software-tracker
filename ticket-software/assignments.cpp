<<<<<<< Updated upstream
#include "assignments.h"
#include "ui_assignments.h"

Assignments::Assignments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Assignments)
{
    ui->setupUi(this);
}

Assignments::~Assignments()
{
    delete ui;
}
=======
#include "assignments.h"
#include "ui_assignments.h"

Assignments::Assignments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Assignments)
{
    ui->setupUi(this);
}

Assignments::~Assignments()
{
    delete ui;
}
>>>>>>> Stashed changes

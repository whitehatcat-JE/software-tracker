#include "archive.h"
#include "ticket.h"
#include "project.h"
#include "projectmanagement.h"
#include <QApplication>
#include <QDebug>
#include "assignments.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Ticket w(0, 1668371875);
    ProjectManagement w;
    //Archive w(0);
    //Ticket w(0, 1667343548);
    //Project w(0);
    //Assignments w;
    w.show();
    return a.exec();
}

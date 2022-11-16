#include "archive.h"
#include "ticket.h"
#include "project.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticket w(0, 1668371875);
    //Archive w(0);
    //Ticket w(0, 1667343548);
    //Project w(0);
    w.show();
    return a.exec();
}

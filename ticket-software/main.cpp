#include "ticket.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticket w(0, 1668372117);
    w.show();
    return a.exec();
}

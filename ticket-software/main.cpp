#include "addticket.h".h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AddTicket w(0);
    w.show();
    return a.exec();
}

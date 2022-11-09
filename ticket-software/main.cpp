#include "assignments.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Assignments w;
    w.show();
    return a.exec();
}

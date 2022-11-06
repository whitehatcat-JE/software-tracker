#include "login.h"
#include "profile.h""
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Profile p;
    Login w;
    p.show();
    return a.exec();
}

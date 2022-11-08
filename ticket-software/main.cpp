#include "assignments.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.loadProjects());
    qInfo() << projects[0].uniqueIdentifier;
    qInfo() << projects[0].name;
    qInfo() << projects[0].description;

    qInfo() << projects[0].tickets[0].title;
    qInfo() << projects[0].tickets[0].logs[0].description;
    qInfo() << projects[0].tickets[0].logs[1].description;

    qInfo() << projects[1].name;
    qInfo() << projects[1].description;

    qInfo() << projects[1].tickets[0].title;
    qInfo() << projects[1].tickets[0].description;
    QApplication a(argc, argv);
    Assignments w;
    w.show();
    return a.exec();
}

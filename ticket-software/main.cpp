#include "login.h"
#include <QApplication>
#include <QDebug>
#include "filemanager.h"
int main(int argc, char *argv[])
{
    QString projectData = "0/,UntitledMMO/,An MMO/,/~0/,1667343548/,0/,Crash on load/,Save System/,Actively Worked On/,Game crashes when trying to save, big problem/,1/,/`0/,1667343548/,Ticket created/,1/`/`0/,1667843654/,This needs to be fixed asap./,0/`/~/,0/,Project Pinecone/,Top secret/,/~0/,1667343548/,0/,Too many eggs in basket/,Save System/,Actively Worked On/,Needs more horizontal intergration/,1/,/`0/,1667343548/,Ticket created/,1/`/`0/,1667843654/,This needs to be fixed asap./,0/`/~/,";
    FileManager myFiles;
    QVector<FileManager::Project> projects = myFiles.interpretProjects(myFiles.compileProjects(myFiles.interpretProjects(projectData)));

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
    Login w;
    w.show();
    return a.exec();
}

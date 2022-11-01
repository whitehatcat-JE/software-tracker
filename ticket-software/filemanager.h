#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>
#include <QVector>


class FileManager
{
public:
    FileManager();

    struct Log {
        int uniqueIdentifier;
        int creationTime;
        QString description;
    };

    struct Ticket {
        int uniqueIdentifier;
        int creationTime;
        int priority;
        QString title;
        QString system;
        QString progress;
        QString description;
        bool isOpen;

        QVector<Log> logs;
    };

    struct Project {
        int uniqueIdentifier;
        QString name;
        QString description;

        QVector<Ticket> tickets;
    };

    QVector<Project> formatProjects(QString projectData) {
        projectData = "0/,UntitledMMO/,An MMO/~0/,1667343548/,0/,Crash on load/,Save System/,Actively Worked On/,Game crashes when trying to save, big problem/,\
                        1/,";
    };

};

#endif // FILEMANAGER_H

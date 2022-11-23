<<<<<<< Updated upstream
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>
#include <QVector>

#include <QFile>
#include <QTextStream>

class FileManager
{
public:
    FileManager();
    // Stores all information related to specified log
    struct Log {
        int uniqueIdentifier; // User whom created log
        int creationTime; // Unix time during log creation
        QString description; // Log text
        bool isConsole; // Indicates whether log was auto-generated
    };
    // Stores all information related to specified ticket
    struct Ticket {
        int uniqueIdentifier; // User whom created ticket
        int creationTime; // Unix time during ticket creation
        int priority; // Priority level of ticket (0-2)
        QString title;
        QString system; // System / Category ticket relates to
        QString progress; // Progress towards completing ticket
        QString description;
        bool isOpen; // Indicates whether ticket is archived

        QVector<Log> logs; // List of logs associated with ticket
    };
    // Stores all information related to specified project
    struct Project {
        int uniqueIdentifier; // Project ID
        QString name;
        QString description;

        QVector<Ticket> tickets; // List of tickets associated with project
    };

   /* struct User {
        QString username;
        QString password;
        QString job;
        QString activeTimes;
        QString location;
        QString email;
        QString phone;
        int accessLevel;
        int profilePicID;
        int uniqueIdentifier;

    };*/

    struct StateData {
        int userID;
        int newPage;
        int pageData;
        int secondaryPageData;
        QString password;
    };

    struct TicketIDs {
        int projectID;
        int ticketID;
    };

    struct Group {
        int ID;
        QString name;
        QVector<TicketIDs> tickets = {};
        QVector<int> projects = {};
        QVector<int> users = {};
    };

    // Loads projects data from disk
    QString loadProjects();
    // Saves projects data to disk
    void saveProjects(QString projectData);
    // Compiles all projects data into QString
    QString compileProjects(QVector<Project> projects);
    // Stores all project data contained within QString as Structs / Vectors, for easier access
    QVector<Project> interpretProjects(QString projectData);

    void WriteFile(QString fileName, QVector<QString> fileContent);
    QVector<QVector<QString>> ReadFile(QString fileName, int columns);

    bool CheckValidUser(QString username, QString fileName);

public slots:

private:
    bool nameFound = false;

    void saveState(StateData state);
    void clearState();
    StateData loadState();

    QVector<Group> loadGroups();
    void saveGroups(QVector<Group>);
};

#endif // FILEMANAGER_H
=======
#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager
{
public:
    FileManager();
};

#endif // FILEMANAGER_H
>>>>>>> Stashed changes

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <String>

#include "SHA256.h"

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

    struct User {
        QString username;
        QString password;
        QString job = "Unspecified Job";
        QString activeTimes = "Unspecified Active Times";
        QString location = "Private Location";
        QString email = "Unknown Email Address";
        QString phone = "Unknown Phone Number";
        int accessLevel = 0;
        int profilePicID = 0;
        int uniqueIdentifier;
    };

    struct StateData {
        int userID = 0;
        int newPage = 0;
        int pageData = 0;
        int secondaryPageData = 0;
        QString password = "";
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

    void saveState(StateData state);
    void clearState();
    StateData loadState();

    QVector<Group> loadGroups();
    void saveGroups(QVector<Group>);

    QVector<User> loadUsers();
    void saveUsers(QVector<User>);
    bool validateUser(int userID, QString userPassword);
    int getAccessLevel(int userID);
    QString hash(int salt, QString str);

    QString getAvatar(int profilePicID);

private:
    bool nameFound = false;
};

#endif // FILEMANAGER_H

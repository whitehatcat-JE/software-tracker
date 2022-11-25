#ifndef FILEMANAGER_H
#define FILEMANAGER_H
// Includes Qt types
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <String>
// Includes SHA256 files for password hashing
#include "SHA256.h"

class FileManager {
public:
    FileManager();
    // Stores all information related to a log
    struct Log {
        int uniqueIdentifier; // User whom created log
        int creationTime; // Unix time during log creation
        QString description; // Log text
        bool isConsole; // Indicates whether log was auto-generated
    };
    // Stores all information related to a ticket
    struct Ticket {
        int uniqueIdentifier; // User whom created ticket
        int creationTime; // Unix time during ticket creation
        int priority; // Priority level of ticket (0-2)
        QString title;
        QString system;
        QString progress;
        QString description;
        bool isOpen; // Indicates whether ticket is archived

        QVector<Log> logs; // List of logs associated with ticket
    };
    // Stores all information related to a project
    struct Project {
        int uniqueIdentifier; // Project ID
        QString name;
        QString description;

        QVector<Ticket> tickets; // List of tickets associated with project
    };
    // Stores all information relating to a user
    struct User {
        QString username;
        QString password; // Hashed
        QString job = "Unspecified Job";
        QString activeTimes = "Unspecified Active Times";
        QString location = "Private Location";
        QString email = "Unknown Email Address";
        QString phone = "Unknown Phone Number";
        int accessLevel = 0;
        int profilePicID = 0;
        int uniqueIdentifier;
    };
    // Stores all information about current page cache
    struct StateData {
        int userID = 0; // UserID of currently logged in user
        int newPage = 0; // Page redirecting too
        // Data being sent to new page
        int pageData = 0;
        int secondaryPageData = 0;
        // Plaintext password of logged in user
        QString password = "";
    };
    // Stores both IDs used to identify a ticket
    struct TicketIDs {
        int projectID;
        int ticketID; // Ticket Creation Time
    };
    // Stores all tickets / projects assigned to a user
    struct UserRelations {
        int uniqueIdentifier; // UserID
        QVector<TicketIDs> tickets;
        QVector<int> projects;
    };
    // Stores all tickets / projects / users assigned to a group
    struct Group {
        int ID;
        QString name;
        QVector<TicketIDs> tickets = {};
        QVector<int> projects = {};
        QVector<int> users = {};
    };

    // Loads projects data from disk
    QString loadProjects();
    // Writes projects data to disk
    void saveProjects(QString projectData);
    // Compiles all projects data into QString
    QString compileProjects(QVector<Project> projects);
    // Stores all project data contained within QString as Structs / Vectors, for easier access
    QVector<Project> interpretProjects(QString projectData);

    // Writes cached state to disk
    void saveState(StateData state);
    // Wipes cached state from disk
    void clearState();
    // Loads cached state from disk
    StateData loadState();

    // Loads group data from disk
    QVector<Group> loadGroups();
    // Writes group data to disk
    void saveGroups(QVector<Group>);

    // Loads all ticket-user / project-user relations from disk
    QVector<UserRelations> loadUserRelations();
    // Writes all ticket-user / project-user relations to disk
    void saveUserRelations(QVector<UserRelations> userRelations);

    // Loads user data from disk
    QVector<User> loadUsers();
    // Writes user data to disk
    void saveUsers(QVector<User>);
    // Checks if user credentials are valid
    bool validateUser(int userID, QString userPassword);
    // Gets access level of given user
    int getAccessLevel(int userID);
    // Hashes plaintext string
    QString hash(int salt, QString str);
    // Gets profile picture of user
    QString getAvatar(int profilePicID);

private: // Declarations used by filemanager class methods
    bool nameFound = false;
};
#endif // FILEMANAGER_H

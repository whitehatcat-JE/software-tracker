#include "filemanager.h"
// Included Qt modules
#include <QDebug>

FileManager::FileManager(){}

// Loads project data from disk
QString FileManager::loadProjects() {
    // Open file from disk
    QFile file("projectsDB.txt");
    file.open(QIODevice::ReadOnly);
    // Reads file data
    QTextStream stream(&file);
    QString projectData = stream.readAll();
    file.close();
    return projectData;
};

// Saves project data to disk
void FileManager::saveProjects(QString projectData) {
    // Open file from disk
    QFile file("projectsDB.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    // Writes project data to disk
    QTextStream stream(&file);
    stream << projectData;
    file.close();
};

// Converts projects vector into a single string
QString FileManager::compileProjects(QVector<Project> projects) {
    QString compiledData = ""; // Complete project data string
    for (Project currentProject : projects) { // Goes through all projects in vector
        // Converts project info into string
        compiledData += QString::number(currentProject.uniqueIdentifier) + "/," +
            currentProject.name + "/," + currentProject.description + "/,";
        // Goes through all tickets in current project
        for (Ticket currentTicket : currentProject.tickets) {
            // Converts ticket info into string
            compiledData += "/~" + QString::number(currentTicket.uniqueIdentifier) + "/," +
                QString::number(currentTicket.creationTime) + "/," +
                QString::number(currentTicket.priority) + "/," + currentTicket.title + "/," +
                currentTicket.system + "/," + currentTicket.progress + "/," +
                currentTicket.description + "/," + (currentTicket.isOpen ? "1" : "0") + "/,";
            // Goes through all logs in current ticket
            for (Log currentLog : currentTicket.logs) {
                // Converts log info into string
                compiledData += "/`" + QString::number(currentLog.uniqueIdentifier) + "/," +
                    QString::number(currentLog.creationTime) + "/," + currentLog.description +
                    "/," + (currentLog.isConsole ? '1' : '0') + "/`";
            } compiledData += "/~"; // Indicates end of log
        } compiledData += "/,"; // Indicates end of ticket
    } return compiledData;
};

// Converts string of projects data into projects vector
QVector<FileManager::Project> FileManager::interpretProjects(QString projectData) {
    // Variable Initalizations
    QVector<Project> projects;

    bool readingSpecial = false;
    QVector<int> columns = {0};
    QString itemStr = "";

    Log currentLog;
    Ticket currentTicket;
    Project currentProject;
    // Goes through all chars in project data string
    for (QChar const &c: projectData) {
        if (c == '/') readingSpecial = true; // Checks if next char in string is for formatting
        else if (readingSpecial) { // Stores latest item of data from string
            readingSpecial = false;
            if (c == ',') { // Adds new column
                switch (columns.size()) { // Determines what type item is
                case 1: // Adds item to project data
                    switch (columns[0]) {
                    case 0: // Project ID int
                        currentProject.uniqueIdentifier = itemStr.toInt();
                        break;
                    case 1: // Name string
                        currentProject.name = itemStr;
                        break;
                    case 2: // Description string
                        currentProject.description = itemStr;
                        break;
                    case 3: // Saves project data to projects vector
                        projects.push_back(currentProject);
                        Project newProject;
                        currentProject = newProject;
                        columns[0] = 0;
                        continue;
                    }
                    break;
                case 2: // Adds item to ticket data
                    switch (columns[0]) { // Determines what type item is
                        case 0: // User ID int
                            currentTicket.uniqueIdentifier = itemStr.toInt();
                            break;
                        case 1: // Unix time on creation int
                            currentTicket.creationTime = itemStr.toInt();
                            break;
                        case 2: // Priority int (0-2)
                            currentTicket.priority = itemStr.toInt();
                            break;
                        case 3: // Title string
                            currentTicket.title = itemStr;
                            break;
                        case 4: // System string
                            currentTicket.system = itemStr;
                            break;
                        case 5: // Progress string
                            currentTicket.progress = itemStr;
                            break;
                        case 6: // Description string
                            currentTicket.description = itemStr;
                            break;
                        case 7: // Archived boolean
                            currentTicket.isOpen = (itemStr[0] == '1');
                    }
                    break;
                case 3: // Adds item to log data
                    switch (columns[0]) {
                        case 0: // User ID int
                            currentLog.uniqueIdentifier = itemStr.toInt();
                            break;
                        case 1:// Unix time on creation int
                            currentLog.creationTime = itemStr.toInt();
                            break;
                        case 2: // Description string
                            currentLog.description = itemStr;
                            break;
                        case 3: // Auto-generated boolean
                            currentLog.isConsole = (itemStr[0] == '1');
                    }
                } columns[0]++;
            } else if (c == '~') { // Adds new ticket to project
                if (columns.size() == 2) { // Places ticket data in project
                    columns.pop_front();
                    currentProject.tickets.push_back(currentTicket);

                    Ticket newTicket;
                    currentTicket = newTicket;
                } else columns.push_front(0); // Starts new ticket
            } else if (c == '`') { // Adds new log to ticket
                if (columns.size() == 3) { // Places log data in ticket
                    columns.pop_front();
                    currentLog.isConsole = (itemStr[0] == '1');
                    currentTicket.logs.push_back(currentLog);

                    Log newLog;
                    currentLog = newLog;
                } else columns.push_front(0); // Starts new log
            } itemStr = ""; // Resets item string
        } else itemStr.append(c); // Adds new char to current item
    } return projects;
};

// Writes user data to disk
void FileManager::saveUsers(QVector<FileManager::User> users) {
    // Opens user data file
    QFile file("users.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream stream(&file);
    if (!file.isOpen()) { return; }
    // Writes all user data
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        stream << users[userIdx].username << "`" <<
            users[userIdx].password << "`" <<
            users[userIdx].job << "`" <<
            users[userIdx].activeTimes << "`" <<
            users[userIdx].location << "`" <<
            users[userIdx].email << "`" <<
            users[userIdx].phone << "`" <<
            users[userIdx].accessLevel << "`" <<
            users[userIdx].profilePicID << "`" <<
            users[userIdx].uniqueIdentifier << "`\n";
    }

    file.close();
}

// Loads all user data from disk
QVector<FileManager::User> FileManager::loadUsers() {
    // Opens user data file
    QFile file("users.csv");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) { return {}; }

    // Reads each line of file
    QVector<FileManager::User> users = {};
    while (!file.atEnd()) {
        // Stores user data read
        QByteArray line = file.readLine();
        QVector<QByteArray> lineVec = line.split('`').toVector();
        FileManager::User newUser;
        newUser.username = lineVec[0];
        newUser.password = lineVec[1];
        newUser.job = lineVec[2];
        newUser.activeTimes = lineVec[3];
        newUser.location = lineVec[4];
        newUser.email = lineVec[5];
        newUser.phone = lineVec[6];
        newUser.accessLevel = lineVec[7].toInt();
        newUser.profilePicID = lineVec[8].toInt();
        newUser.uniqueIdentifier = lineVec[9].toInt();
        users.push_back(newUser);
    }

    file.close();
    return users;
}

// Checks if user credentials are valid
bool FileManager::validateUser(int userId, QString userPassword) {
    // Finds user ID
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userId) {
            // Checks if password matches
            if (users[userIdx].password == hash(userId, userPassword)) { return true; }
            return false;
        }
    } return false;
}

// Gets access level of given user
int FileManager::getAccessLevel(int userID) {
    // Finds userID
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) { return users[userIdx].accessLevel; } // Returns access level
    } return 0; // Default return value
}

// Hashes a given QString, applying given salt
QString FileManager::hash(int salt, QString str) {
    // Creates salted plaintext password
    std::string saltedPassword = std::to_string(salt) + str.toStdString();
    // Hashes password
    SHA256 sha;
    sha.update(saltedPassword);
    // Returns hashed password
    return QString::fromStdString(SHA256::toString(sha.digest()));
}

// Gets image file name of given image file id
QString FileManager::getAvatar(int profilePicID) {
    switch (profilePicID) {
    case 0:
        return "bear";
    case 1:
        return "cat";
    case 2:
        return "chicken";
    case 3:
        return "GrayDog";
    case 4:
        return "dog";
    case 5:
        return "koala";
    case 6:
        return "panda";
    case 7:
        return "rabbit";
    default:
        return "YellowRabbit";
    }
}

// Writes cached state to disk
void FileManager::saveState(StateData state) {
    // Open file from disk
    FileManager::StateData oldState = FileManager::loadState();
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    // Writes state to disk
    QTextStream stream(&file);
    if (state.password == "") {
        state.userID = oldState.userID;
        state.password = oldState.password;
    }
    stream << state.userID << ',' << state.password << ',' <<
          state.newPage << ',' << state.pageData << ',' <<
          state.secondaryPageData << "\n";
    file.close();
}

// Loads cached state from disk
FileManager::StateData FileManager::loadState() {
    // Open file from disk
    FileManager::StateData myState;
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) { return myState; }
    // Reads state and constructs state vector
    QTextStream stream(&file);
    QString stateInfo = stream.readLine();
    QVector<QString> stateInfoVec;
    stateInfoVec.append(stateInfo.split(","));
    if (stateInfoVec.size() < 5) { return myState; }
    myState.userID = stateInfoVec[0].toInt();
    myState.password = stateInfoVec[1];
    myState.newPage = stateInfoVec[2].toInt();
    myState.pageData = stateInfoVec[3].toInt();
    myState.secondaryPageData = stateInfoVec[4].toInt();

    file.close();
    return myState;
}

// Wipes cachedState from disk
void FileManager::clearState() {
    QFile file ("cachedState.csv");
    file.remove();
}

// Loads user relations from disk
QVector<FileManager::UserRelations> FileManager::loadUserRelations() {
    // Oopens file
    QFile file("userRelations.csv");
    file.open(QIODevice::ReadOnly);

    if (!file.isOpen()) { return {}; }

    // Creates new userRelations struct for each existing user
    QVector<FileManager::UserRelations> userRelations = {};
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        FileManager::UserRelations newUserRelations;
        newUserRelations.uniqueIdentifier = users[userIdx].uniqueIdentifier;
        userRelations.push_back(newUserRelations);
    }
    // Adds all userRelations to relevant struct
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QVector<QByteArray> lineVec = line.split('`').toVector();
        for (int userRelationIdx = 0; userRelationIdx < userRelations.size(); userRelationIdx++) {
            if (userRelations[userRelationIdx].uniqueIdentifier == lineVec[0].toInt()) {
                if (lineVec[1].toInt() == 0) {
                    userRelations[userRelationIdx].projects.push_back(lineVec[2].toInt());
                } else {
                    FileManager::TicketIDs newTicket;
                    newTicket.projectID = lineVec[2].toInt();
                    newTicket.ticketID = lineVec[3].toInt();
                    userRelations[userRelationIdx].tickets.push_back(newTicket);
                }
            }
        }
    }

    file.close();
    return userRelations;
}

// Writes userRelations to disk
void FileManager::saveUserRelations(QVector<FileManager::UserRelations> userRelations) {
    // Opens file
    QFile file("userRelations.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    if (!file.isOpen()) { return; }
    // Loops through all users in userRelations QVector
    QTextStream stream(&file);
    for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
        // Writes all user-project relations
        for (int projectRelationIdx = 0; projectRelationIdx < userRelations[userIdx].projects.size(); projectRelationIdx++) {
            stream << userRelations[userIdx].uniqueIdentifier << "`0`" <<
                userRelations[userIdx].projects[projectRelationIdx] << "`\n";
        }
        // Writes all user-ticket relations
        for (int ticketRelationIdx = 0; ticketRelationIdx < userRelations[userIdx].tickets.size(); ticketRelationIdx++) {
            stream << userRelations[userIdx].uniqueIdentifier << "`1`" <<
                userRelations[userIdx].tickets[ticketRelationIdx].projectID << "`" <<
                userRelations[userIdx].tickets[ticketRelationIdx].ticketID << "`\n";
        }
    }
    file.close();
}

// Loads all groups from disk
QVector<FileManager::Group> FileManager::loadGroups() {
    // Opens groups file
    QFile groupFile("groups.csv");
    groupFile.open(QIODevice::ReadOnly);
    // Opens groupRelations file
    QFile relationFile("groupRelations.csv");
    relationFile.open(QIODevice::ReadOnly);
    if (!groupFile.isOpen() || !relationFile.isOpen()) { return {}; }
    // Adds all groups
    QVector<FileManager::Group> groups = {};
    QVector<int> groupIDs;
    while (!groupFile.atEnd()) {
        QByteArray line = groupFile.readLine();
        FileManager::Group newGroup;
        QVector<QByteArray> lineVec = line.split(',').toVector();
        newGroup.ID = lineVec[0].toInt();
        newGroup.name = lineVec[1];
        groups.push_back(newGroup);
        groupIDs.push_back(newGroup.ID);
    }
    // Adds all group relation data
    bool missingData = false; // Checks if group is missing
    while (!relationFile.atEnd()) {
        QByteArray line = relationFile.readLine();
        QVector<QByteArray> lineVec = line.split(',').toVector();
        if (!groupIDs.contains(lineVec[0].toInt())) { // Triggers if group is missing
            missingData = true; // Stops attempt at writing to group
            continue;
        }

        if (lineVec[1].toInt() == 0) { // Adds group-ticket relation
            FileManager::TicketIDs newTicket;
            newTicket.projectID = lineVec[2].toInt();
            newTicket.ticketID = lineVec[3].toInt();
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].tickets.push_back(newTicket);
                    break;
                }
            }
        } else if (lineVec[1].toInt() == 1) { // Adds group-project relation
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].projects.push_back(lineVec[2].toInt());
                    break;
                }
            }
        } else if (lineVec[1].toInt() == 2) { // Adds group-user relation
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].users.push_back(lineVec[2].toInt());
                    break;
                }
            }
        }
    }
    // Closes files
    groupFile.close();
    relationFile.close();
    // Fixes any missing data
    if (missingData) { saveGroups(groups); }
    // Returns group data
    return groups;
}

// Writes group data to disk
void FileManager::saveGroups(QVector<FileManager::Group> groups) {
    // Opens group file
    QFile groupFile("groups.csv");
    groupFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    // Opens group relation file
    QFile relationFile("groupRelations.csv");
    relationFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    if (!groupFile.isOpen() || !relationFile.isOpen()) { return; }
    QTextStream rStream(&relationFile);
    QTextStream gStream(&groupFile);
    // Loops through all groups
    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
        gStream << groups[groupIdx].ID << "," << groups[groupIdx].name << ",\n";
        // Writes group-ticket relations
        for (int ticketIdx = 0; ticketIdx < groups[groupIdx].tickets.size(); ticketIdx++) {
            rStream << groups[groupIdx].ID << ",0," << groups[groupIdx].tickets[ticketIdx].projectID
                    << "," << groups[groupIdx].tickets[ticketIdx].ticketID << "\n";
        }
        // Writes group-project relations
        for (int projectIdx = 0; projectIdx < groups[groupIdx].projects.size(); projectIdx++) {
            rStream << groups[groupIdx].ID << ",1," << groups[groupIdx].projects[projectIdx] << "\n";
        }
        // Writes group-user relations
        for (int userIdx = 0; userIdx < groups[groupIdx].users.size(); userIdx++) {
            rStream << groups[groupIdx].ID << ",2," << groups[groupIdx].users[userIdx] << "\n";
        }
    }
    // Closes files
    groupFile.close();
    relationFile.close();
}

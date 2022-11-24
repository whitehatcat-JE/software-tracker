#include "filemanager.h"
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

void FileManager::saveUsers(QVector<FileManager::User> users) {
    QFile file("users.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream stream(&file);
    if (!file.isOpen()) { return; }

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

QVector<FileManager::User> FileManager::loadUsers() {
    QFile file("users.csv");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) { return {}; }

    QVector<FileManager::User> users = {};
    while (!file.atEnd()) {
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

bool FileManager::validateUser(int userId, QString userPassword) {
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userId) {
            if (users[userIdx].password == hash(userId, userPassword)) { return true; }
            return false;
        }
    } return false;
}

int FileManager::getAccessLevel(int userID) {
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].uniqueIdentifier == userID) { return users[userIdx].accessLevel; }
    } return 0;
}

QString FileManager::hash(int salt, QString str) {
    std::string saltedPassword = std::to_string(salt) + str.toStdString();
    SHA256 sha;
    sha.update(saltedPassword);
    return QString::fromStdString(SHA256::toString(sha.digest()));
}

QString FileManager::getAvatar(int profilePicID) {
    switch (profilePicID) {
    case 0:
        return "bear";
    case 1:
        return "cat";
    case 2:
        return "chicken";
    case 3:
        return "GreyDog";
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

void FileManager::saveState(StateData state) {
    FileManager::StateData oldState = FileManager::loadState();
    // Open file from disk
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    // Writes project data to disk
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

FileManager::StateData FileManager::loadState() {
    FileManager::StateData myState;
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) { return myState; }
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

void FileManager::clearState() {
    QFile file ("cachedState.csv");
    file.remove();
}


QVector<FileManager::UserRelations> FileManager::loadUserRelations() {
    QFile file("userRelations.csv");
    file.open(QIODevice::ReadOnly);

    if (!file.isOpen()) { return {}; }

    QVector<FileManager::UserRelations> userRelations = {};
    QVector<FileManager::User> users = loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        FileManager::UserRelations newUserRelations;
        newUserRelations.uniqueIdentifier = users[userIdx].uniqueIdentifier;
        userRelations.push_back(newUserRelations);
    }

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

void FileManager::saveUserRelations(QVector<FileManager::UserRelations> userRelations) {
    QFile file("userRelations.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    if (!file.isOpen()) { return; }
    QTextStream stream(&file);
    for (int userIdx = 0; userIdx < userRelations.size(); userIdx++) {
        for (int projectRelationIdx = 0; projectRelationIdx < userRelations[userIdx].projects.size(); projectRelationIdx++) {
            stream << userRelations[userIdx].uniqueIdentifier << "`0`" <<
                userRelations[userIdx].projects[projectRelationIdx] << "`\n";
        }
        for (int ticketRelationIdx = 0; ticketRelationIdx < userRelations[userIdx].tickets.size(); ticketRelationIdx++) {
            stream << userRelations[userIdx].uniqueIdentifier << "`1`" <<
                userRelations[userIdx].tickets[ticketRelationIdx].projectID << "`" <<
                userRelations[userIdx].tickets[ticketRelationIdx].ticketID << "`\n";
        }
    }
    file.close();
}

QVector<FileManager::Group> FileManager::loadGroups() {
    QFile groupFile("groups.csv");
    groupFile.open(QIODevice::ReadOnly);

    QFile relationFile("groupRelations.csv");
    relationFile.open(QIODevice::ReadOnly);
    if (!groupFile.isOpen() || !relationFile.isOpen()) { return {}; }

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
    bool missingData = false;
    while (!relationFile.atEnd()) {
        QByteArray line = relationFile.readLine();
        QVector<QByteArray> lineVec = line.split(',').toVector();
        if (!groupIDs.contains(lineVec[0].toInt())) {
            missingData = true;
            continue;
        }
        if (lineVec[1].toInt() == 0) {
            FileManager::TicketIDs newTicket;
            newTicket.projectID = lineVec[2].toInt();
            newTicket.ticketID = lineVec[3].toInt();
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].tickets.push_back(newTicket);
                    break;
                }
            }
        } else if (lineVec[1].toInt() == 1) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].projects.push_back(lineVec[2].toInt());
                    break;
                }
            }
        } else if (lineVec[1].toInt() == 2) {
            for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
                if (groups[groupIdx].ID == lineVec[0].toInt()) {
                    groups[groupIdx].users.push_back(lineVec[2].toInt());
                    break;
                }
            }
        }
    }

    groupFile.close();
    relationFile.close();

    if (missingData) { saveGroups(groups); }

    return groups;
}

void FileManager::saveGroups(QVector<FileManager::Group> groups) {
    QFile groupFile("groups.csv");
    groupFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QFile relationFile("groupRelations.csv");
    relationFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    if (!groupFile.isOpen() || !relationFile.isOpen()) { return; }
    QTextStream rStream(&relationFile);
    QTextStream gStream(&groupFile);

    for (int groupIdx = 0; groupIdx < groups.size(); groupIdx++) {
        gStream << groups[groupIdx].ID << "," << groups[groupIdx].name << ",\n";
        for (int ticketIdx = 0; ticketIdx < groups[groupIdx].tickets.size(); ticketIdx++) {
            rStream << groups[groupIdx].ID << ",0," << groups[groupIdx].tickets[ticketIdx].projectID
                    << "," << groups[groupIdx].tickets[ticketIdx].ticketID << "\n";
        }
        for (int projectIdx = 0; projectIdx < groups[groupIdx].projects.size(); projectIdx++) {
            rStream << groups[groupIdx].ID << ",1," << groups[groupIdx].projects[projectIdx] << "\n";
        }
        for (int userIdx = 0; userIdx < groups[groupIdx].users.size(); userIdx++) {
            rStream << groups[groupIdx].ID << ",2," << groups[groupIdx].users[userIdx] << "\n";
        }
    }
    groupFile.close();
    relationFile.close();
}

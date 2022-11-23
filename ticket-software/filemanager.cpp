<<<<<<< Updated upstream
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

void FileManager::WriteFile(QString fileName, QVector<QString> fileContent){
    fileName.append(".csv");
    QFile file(fileName);
    //We use ReadWrite here, otherwise as write includes the truncate flag, which will clear all date from the file
    file.open(QIODevice::ReadWrite | QIODevice::Append);

    if(!file.isOpen()){
        qDebug() << "File Not open";
        return;
    }
    QTextStream stream(&file);
    for(int i = 0; i < fileContent.size(); i++){
        stream << fileContent.at(i);
        if(i != fileContent.size()-1){
            stream << ",";
        }
        else{
            stream << "\n";
        }
    }
    file.close();
    if(!file.isOpen()){
    }
}

bool FileManager::CheckValidUser(QString username, QString fileName){
    nameFound = false;
    QVector<QVector<QString>> content = ReadFile(fileName, 3);

    for(int i = 0; i < content.size(); i++){
        if(content.at(i).at(0) == username){
            nameFound = true;
            return false;
        }
        else{
            continue;
        }
    }
    if(!nameFound){
        return true;
    }
    return false;
}

//Read File from location with reference to columns in the file
QVector<QVector<QString>> FileManager::ReadFile(QString fileName, int numColumns){
    fileName.append(".csv");

    QVector<QVector<QString>> columns;
    QVector<QString> rows;

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        qDebug() << "No File Open";
        return columns;
    }

    //for(QVector<QString> : fileContent)

    QTextStream stream(&file);

    while(!stream.atEnd()){
        QString str = stream.readLine();
        rows.append(str.split(","));
        for(int i = 0; i < numColumns; i++){
            if(i == numColumns-1){
                columns.append(rows);
                rows.clear();
            }
        }
    }

    file.close();
    return columns;

void FileManager::saveState(StateData state) {
    // Open file from disk
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    // Writes project data to disk
    QTextStream stream(&file);
    stream << state.userID << ',' << state.password << ',' <<
          state.newPage << ',' << state.pageData << ',' <<
          state.secondaryPageData << "\n";
    file.close();
}

FileManager::StateData FileManager::loadState() {
    FileManager::StateData myState;
    QFile file("cachedState.csv");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen()) {
        myState.newPage = 2;
        myState.userID = 0;
        myState.password = "";
        myState.pageData = 0;
        myState.secondaryPageData = 0;
        return myState;
    }
    QTextStream stream(&file);
    QString stateInfo = stream.readLine();
    QVector<QString> stateInfoVec;
    stateInfoVec.append(stateInfo.split(","));
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
    QTextStream gStream(&groupFile);
    QFile relationFile("groupRelations.csv");
    relationFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream rStream(&relationFile);
    if (!groupFile.isOpen() || !relationFile.isOpen()) { return; }

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
=======
#include "filemanager.h"

FileManager::FileManager()
{

}
>>>>>>> Stashed changes

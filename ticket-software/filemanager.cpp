#include "filemanager.h"

FileManager::FileManager(){}
// Loads project data from disk
QString FileManager::loadProjects() {
    // Open file from disk
    QFile file("projectsDB.txt");
    file.open(QIODevice::ReadOnly);
    // Reads file data
    QTextStream stream(&file);
    QString projectData = stream.readLine();
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
                    currentTicket.logs.push_back(currentLog);

                    Log newLog;
                    currentLog = newLog;
                } else columns.push_front(0); // Starts new log
            } itemStr = ""; // Resets item string
        } else itemStr.append(c); // Adds new char to current item
    } return projects;
};

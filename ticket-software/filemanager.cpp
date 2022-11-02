#include "filemanager.h"

FileManager::FileManager()
{

}

QString FileManager::loadProjects() {
    QFile file("projectsDB.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString projectData = stream.readLine();
    file.close();
    return projectData;
};

void FileManager::saveProjects(QString projectData) {
    QFile file("projectsDB.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << projectData;
    file.close();
};

QString FileManager::compileProjects(QVector<Project> projects) {
    QString compiledData = "";
    for (Project currentProject : projects) {
        compiledData += QString::number(currentProject.uniqueIdentifier) + "/," +
            currentProject.name + "/," + currentProject.description + "/,";

        for (Ticket currentTicket : currentProject.tickets) {
            compiledData += "/~" + QString::number(currentTicket.uniqueIdentifier) + "/," +
                QString::number(currentTicket.creationTime) + "/," +
                QString::number(currentTicket.priority) + "/," + currentTicket.title + "/," +
                currentTicket.system + "/," + currentTicket.progress + "/," +
                currentTicket.description + "/," + (currentTicket.isOpen ? "1" : "0") + "/,";

            for (Log currentLog : currentTicket.logs) {
                compiledData += "/`" + QString::number(currentLog.uniqueIdentifier) + "/," +
                    QString::number(currentLog.creationTime) + "/," + currentLog.description +
                    "/," + (currentLog.isConsole ? '1' : '0') + "/`";
            } compiledData += "/~";
        } compiledData += "/,";
    } return compiledData;
};

QVector<FileManager::Project> FileManager::interpretProjects(QString projectData) {
    QVector<Project> projects;

    bool readingSpecial = false;
    QVector<int> columns = {0};
    QString itemStr = "";

    Log currentLog;
    Ticket currentTicket;
    Project currentProject;

    for (QChar const &c: projectData) {
        if (c == '/') readingSpecial = true;
        else if (readingSpecial) {
            readingSpecial = false;
            if (c == ',') {
                switch (columns.size()) {
                case 1:
                    switch (columns[0]) {
                    case 0:
                        currentProject.uniqueIdentifier = itemStr.toInt();
                        break;
                    case 1:
                        currentProject.name = itemStr;
                        break;
                    case 2:
                        currentProject.description = itemStr;
                        break;
                    case 3:
                        projects.push_back(currentProject);
                        Project newProject;
                        currentProject = newProject;
                        columns[0] = 0;
                        continue;
                    }
                    break;
                case 2:
                    switch (columns[0]) {
                        case 0:
                            currentTicket.uniqueIdentifier = itemStr.toInt();
                            break;
                        case 1:
                            currentTicket.creationTime = itemStr.toInt();
                            break;
                        case 2:
                            currentTicket.priority = itemStr.toInt();
                            break;
                        case 3:
                            currentTicket.title = itemStr;
                            break;
                        case 4:
                            currentTicket.system = itemStr;
                            break;
                        case 5:
                            currentTicket.progress = itemStr;
                            break;
                        case 6:
                            currentTicket.description = itemStr;
                            break;
                        case 7:
                            currentTicket.isOpen = (itemStr[0] == '1');
                    }
                    break;
                case 3:
                    switch (columns[0]) {
                        case 0:
                            currentLog.uniqueIdentifier = itemStr.toInt();
                            break;
                        case 1:
                            currentLog.creationTime = itemStr.toInt();
                            break;
                        case 2:
                            currentLog.description = itemStr;
                            break;
                        case 3:
                            currentLog.isConsole = (itemStr[0] == '1');
                    }
                } columns[0]++;
            } else if (c == '~') {
                if (columns.size() == 2) {
                    columns.pop_front();
                    currentProject.tickets.push_back(currentTicket);

                    Ticket newTicket;
                    currentTicket = newTicket;
                } else columns.push_front(0);
            } else if (c == '`') {
                if (columns.size() == 3) {
                    columns.pop_front();
                    currentTicket.logs.push_back(currentLog);

                    Log newLog;
                    currentLog = newLog;
                } else columns.push_front(0);
            } itemStr = "";
        } else itemStr.append(c);
    } return projects;
};

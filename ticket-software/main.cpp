#include "archive.h"
#include "ticket.h"
#include "project.h"
#include "projectmanagement.h"
#include <QApplication>
#include <QDebug>
#include "assignments.h"
#include "filemanager.h"

int main(int argc, char *argv[])
{
    FileManager myFiles;
    do {
        FileManager::StateData state = myFiles.loadState();
        QApplication a(argc, argv);
        Assignments assignment;
        ProjectManagement projectManage;
        switch (state.newPage) {
            case 0:
                assignment.show();
                break;
            case 1:
                projectManage.show();
                break;
        }
        a.exec();
    } while(myFiles.loadState().newPage != 0);
    //QApplication b(argc, argv);
    //x.show();
    //b.exec();
    //return a.exec();
}

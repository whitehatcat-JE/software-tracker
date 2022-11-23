#include <QApplication>

#include "filemanager.h"
#include "login.h"
#include "profile.h"
#include "assignments.h"
#include "project.h"
#include "ticket.h"
#include "addticket.h"
#include "archive.h"
#include "management.h"
#include "usermanagement.h"
#include "groupmanagement.h"
#include "projectmanagement.h"
#include "managementselection.h"

int main(int argc, char *argv[])
{
    FileManager myFiles;
    QApplication a(argc, argv);
    do {
        FileManager::StateData state = myFiles.loadState();
        // 0:login 1:profile 2:assignments 3:project 4:ticket 5:addTicket 6:archive 7:management
        // 8:userManagement 9: groupManagement 10:projectManagement 11:managementSelection
        // 12:profileViewing

        // NOTE: SWITCH STATEMENT DOESN'T WORK HERE
        if (state.newPage == 0) {
            Login page;
            page.show();
            a.exec();
        } else if (state.newPage == 1) {
            Profile page;
            page.show();
            a.exec();
        } else if (state.newPage == 2) {
            Assignments page;
            page.show();
            a.exec();
        }  else if (state.newPage == 3) {
            Project page(state.pageData);
            page.show();
            a.exec();
        } else if (state.newPage == 4) {
            Ticket page(state.pageData, state.secondaryPageData);
            page.show();
            a.exec();
        } else if (state.newPage == 5) {
            AddTicket page(state.pageData);
            page.show();
            a.exec();
        } else if (state.newPage == 6) {
            Archive page(state.pageData);
            page.show();
            a.exec();
        } else if (state.newPage == 7) {
            Management page;
            page.show();
            a.exec();
        } else if (state.newPage == 8) {
            UserManagement page;
            page.show();
            a.exec();
        } else if (state.newPage == 9) {
            GroupManagement page;
            page.show();
            a.exec();
        } else if (state.newPage == 10) {
            ProjectManagement page;
            page.show();
            a.exec();
        } else if (state.newPage == 11) {
            ManagementSelection page(state.pageData, state.secondaryPageData);
            page.show();
            a.exec();
        }
    } while(myFiles.loadState().newPage != -1);
    myFiles.clearState();
    return 1;
}
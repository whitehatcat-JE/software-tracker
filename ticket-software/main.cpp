// Included Qt modules
#include <QApplication>
// Page headers
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
#include "profileviewer.h"

// Main loop
int main(int argc, char *argv[])
{
    // Loads user information
    FileManager myFiles;
    QApplication a(argc, argv);

    QVector<FileManager::User> users = myFiles.loadUsers();
    // Checks an admin account exists
    bool foundAdmin = false;
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].accessLevel == 2) {
            foundAdmin = true;
            break;
        }
    }
    // Adds admin account if none exist
    if (!foundAdmin) {
        FileManager::User newUser;
        newUser.username = "admin";
        newUser.uniqueIdentifier = users.size() == 0 ? 0 : users[users.size()-1].uniqueIdentifier+1;
        newUser.password = myFiles.hash(newUser.uniqueIdentifier, "password");
        newUser.accessLevel = 2;
        users.push_back(newUser);
        myFiles.saveUsers(users);
    }
    // Loops page loading until user quits program
    do {
        FileManager::StateData state = myFiles.loadState();
        // State newPage ids:
        // 0:login 1:profile 2:assignments 3:project 4:ticket 5:addTicket 6:archive 7:management
        // 8:userManagement 9: groupManagement 10:projectManagement 11:managementSelection
        // 12:profileViewing

        // Determines which page to open
        // NOTE: SWITCH STATEMENT DOESN'T WORK HERE
        if (state.newPage == 0 || !myFiles.validateUser(state.userID, state.password)) {
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
        } else {
            ProfileViewer page;
            page.show();
            a.exec();
        }
    } while(myFiles.loadState().newPage != -1);
    // Quits program
    myFiles.clearState();
    return 1;
}

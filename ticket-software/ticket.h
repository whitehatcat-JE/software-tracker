#ifndef TICKET_H
#define TICKET_H
// Includes Qt types
#include <QWidget>
#include <QDateTime>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>
// Includes file management system
#include "filemanager.h"

// Declares Ticket class
namespace Ui { class Ticket; }
class Ticket : public QWidget {
    Q_OBJECT
public:
    explicit Ticket(int projectID, int ticketID, QWidget *parent = nullptr); // Ticket class constructor
    ~Ticket(); // Ticket class destructor

private slots: // All slot connections from UI
    void on_postButton_clicked();
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();
    void on_archiveButton_clicked();
    void on_assignGroupButton_clicked();
    void on_priorityButton_clicked();
    void on_assignUserButton_clicked();
    void on_assignSelfButton_clicked();

private: // Declarations used by Ticket class methods
    Ui::Ticket *ui;
    int IDProject;
    int IDTicket;

    bool closing = true;
    void reloadLogs();
    // Method used by dynamically created buttons
    void openUser(int userID);
};
#endif // TICKET_H

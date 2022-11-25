#ifndef ADDTICKET_H
#define ADDTICKET_H
// Includes Qt types
#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QByteArray>
#include <QMessageBox>
// Includes file management system
#include "filemanager.h"

// Declares AddTicket class
namespace Ui { class AddTicket; }
class AddTicket : public QWidget {
    Q_OBJECT
public:
    explicit AddTicket(int projectID, QWidget *parent = nullptr); // AddTicket class constructor
    ~AddTicket(); // AddTicket class destructor

private slots: // All slot connections from UI
    void on_createTicket_clicked();
    void on_backButton_clicked();
    void on_logoutButton_clicked();
    void on_managementButton_clicked();
    void on_assignButton_clicked();
    void on_profileButton_clicked();

private: // Declariations used by AddTicket class methods
    Ui::AddTicket *ui;
    int assignedIdentifier; // ProjectID
    bool closing = true; // Determines whether to quit program
};
#endif // ADDTICKET_H

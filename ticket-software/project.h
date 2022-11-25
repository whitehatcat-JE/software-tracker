#ifndef PROJECT_H
#define PROJECT_H
// Includes Qt types
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
// Includes file management system
#include "filemanager.h"

// Declares Project class
namespace Ui { class Project; }
class Project : public QWidget {
    Q_OBJECT
public:
    explicit Project(int projectID, QWidget *parent = nullptr); // Project class constructor
    ~Project(); // Project class destructor

private slots: // All slot connections from UI
    void on_lineEditPassword_textChanged(const QString &query);
    void on_detailsButton_toggled(bool checked);
    void on_detailsButton_2_toggled(bool checked);
    void on_assignButton_clicked();
    void on_profileButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();
    void on_createTicketButton_clicked();
    void on_archiveButton_clicked();

private: // Declarations for Project class methods
    Ui::Project *ui;
    int assignedIdentifier;
    bool closing = true;
    QVector<QPushButton*> displayedTickets;
    // Method used by dynamically created buttons
    void openTicket(int ticketID);
};
#endif // PROJECT_H

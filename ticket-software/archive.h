#ifndef ARCHIVE_H
#define ARCHIVE_H
// Includes Qt types
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDateTime>
// Includes file management system
#include "filemanager.h"

// Declares archive class
namespace Ui { class Archive; }
class Archive : public QWidget {
    Q_OBJECT
public:
    explicit Archive(int projectID, QWidget *parent = nullptr); // Archive class constructor
    ~Archive(); // Archive class destructor

private slots: // All slot connections from UI
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();

private: // Declarations used by Archive class method
    Ui::Archive *ui;
    int IDProject;

    void reloadTickets();
    bool closing = true;
    // Methods called by dynamically created buttons
    void reOpenTicket(int ticketID);
    void deleteTicket(int ticketID);
    void openTicket(int ticketID);
};
#endif // ARCHIVE_H

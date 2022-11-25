#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H
// Includes Qt types
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QDateTime>
// Includes file management system
#include "filemanager.h"

// Declares assignments class
namespace Ui { class Assignments; }
class Assignments : public QWidget {
    Q_OBJECT
public:
    explicit Assignments(QWidget *parent = nullptr); // Assignments class constructor
    ~Assignments(); // Assignments class destructor

private slots: // All slot connections from UI
    void on_ticketsButton_toggled(bool checked);
    void on_groupsButton_toggled(bool checked);
    void on_projectsButton_toggled(bool checked);
    void on_logoutButton_clicked();
    void on_managementButton_clicked();
    void on_profileButton_clicked();

private: // Declarations used by Assigments class methods
    Ui::Assignments *ui;
    bool closing = true;
    // Methods used by dynamically created buttons
    void on_projectButton_triggered(int id);
    void openTicket(int projectID, int ticketID);
    void openGroup(int groupID, QLabel* groupArrow, QVBoxLayout* groupLayout);
};
#endif // ASSIGNMENTS_H

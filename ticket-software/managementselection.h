#ifndef MANAGEMENTSELECTION_H
#define MANAGEMENTSELECTION_H
// Includes Qt types
#include <QWidget>
#include <QLabel>
#include <QPushButton>
// Includes file management system
#include "filemanager.h"

// Declares ManagementSelection class
namespace Ui { class ManagementSelection; }
class ManagementSelection : public QWidget {
    Q_OBJECT
public:
    explicit ManagementSelection(int selectionType, int id, QWidget *parent = nullptr); // ManagementSelection class constructor
    ~ManagementSelection(); // ManagementSelection class destructor

private slots: // All slot connections from UI
    void on_profileButton_clicked();
    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();
    void on_backButton_clicked();

private: // Declarations used by ManagementSelection class methods
    Ui::ManagementSelection *ui;
    bool closing = true;
    int type;
    int objID;
    // Method used by dynamically created buttons
    void changeListing(int id, QPushButton* button, int secondaryID = 0);
};
#endif // MANAGEMENTSELECTION_H

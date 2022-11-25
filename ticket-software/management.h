#ifndef MANAGEMENT_H
#define MANAGEMENT_H
// Includes Qt types
#include <QWidget>
// Includes file management system
#include "filemanager.h"

// Declares Management class
namespace Ui { class Management; }
class Management : public QWidget {
    Q_OBJECT
public:
    explicit Management(QWidget *parent = nullptr); // Management class constructor
    ~Management(); // Management class destructor

private slots: // All slot connections from UI
    void on_assignedButton_clicked();
    void on_profileButton_clicked();
    void on_logoutButton_clicked();
    void on_usersButton_clicked();
    void on_groupsButton_clicked();
    void on_projectsButton_clicked();

private: // Declarations used by Management class methods
    bool closing = true;
    Ui::Management *ui;
};
#endif // MANAGEMENT_H

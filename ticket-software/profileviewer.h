#ifndef PROFILEVIEWER_H
#define PROFILEVIEWER_H
// Includes Qt types
#include <QMainWindow>
// Includes file management system
#include "filemanager.h"

// Declares ProfileViewer class
namespace Ui { class ProfileViewer; }
class ProfileViewer : public QMainWindow {
    Q_OBJECT
public:
    explicit ProfileViewer(QWidget *parent = nullptr); // ProfileViewer class constructor
    ~ProfileViewer(); // ProfileViewer class destructor

private slots: // All slot connections from UI
    void on_managementButton_2_clicked();
    void on_assignButton_2_clicked();
    void on_profileButton_2_clicked();
    void on_logoutButton_2_clicked();

private: // Declarations used by ProfileViewer class methods
    Ui::ProfileViewer *ui;
    bool closing = true;
};
#endif // PROFILEVIEWER_H

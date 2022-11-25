#ifndef LOGIN_H
#define LOGIN_H
// Includes Qt types
#include <QMainWindow>
#include <string>
#include <array>
#include <QObject>
#include <QLineEdit>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QVector>
// Includes file management system
#include "filemanager.h"

// Declares Login class
namespace Ui { class Login; }
class Login : public QMainWindow {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr); // Login class constructor
    ~Login(); // Login class destructor

private slots: // All slot connections from UI
    void on_logInBtn_clicked();
    void on_hidePasswordButton_clicked();

private: // Declarations used by Login class methods
    Ui::Login *ui;
    FileManager fManager;
    bool signedIn = false;
    int userIndex;
    bool closing = true;
};
#endif // LOGIN_H

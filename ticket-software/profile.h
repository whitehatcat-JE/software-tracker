#ifndef PROFILE_H
#define PROFILE_H
// Includes Qt types
#include <QWidget>
#include <QMainWindow>
#include <QFileInfo>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
// Includes file management system
#include "filemanager.h"

// Declares Profile class
namespace Ui { class Profile; }
class Profile : public QWidget {
    Q_OBJECT
public:
    explicit Profile(QWidget *parent = nullptr); // Profile class constructor
    ~Profile(); // Profile class destructor

private slots: // All slot connections from UI
    void on_EditDetails_clicked(bool checked);
    void on_changePassword_clicked();

    void on_EditProfilePic_clicked(bool checked);
    void on_ProfileOp1_clicked();
    void on_ProfileOp2_clicked();
    void on_ProfileOp3_clicked();
    void on_ProfileOp4_clicked();
    void on_ProfileOp5_clicked();
    void on_ProfileOp6_clicked();
    void on_ProfileOp7_clicked();
    void on_ProfileOp8_clicked();
    void on_ProfileOp9_clicked();
    void on_profileButton_clicked();

    void on_assignButton_clicked();
    void on_managementButton_clicked();
    void on_logoutButton_clicked();

private: // Declarations used by Profile class methods
    Ui::Profile *ui;
    bool closing = true;

    // Methods used by dynamically created buttons
    void hidePassword(QPushButton* echoSwitch, QLineEdit* password);
    void confirmButtonPressed(QDialog* popup, QLineEdit* newPassword);
    void cancelButtonPressed(QDialog* popup);

    void updateInfo();
    void updateProfilePic(int profilePicID);
};
#endif // PROFILE_H

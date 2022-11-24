#ifndef PROFILE_H
#define PROFILE_H

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

#include "filemanager.h"

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:

    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

private slots:

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

    void hidePassword(QPushButton* echoSwitch, QLineEdit* password);
    void confirmButtonPressed(QDialog* popup, QLineEdit* newPassword);
    void cancelButtonPressed(QDialog* popup);

    void updateInfo();

    void updateProfilePic(int profilePicID);

private:

    Ui::Profile *ui;
    bool closing = true;
    //Access Central widget on popup window
    //Assign a vertical layout group
    //Access central widget and use function

};

#endif // PROFILE_H

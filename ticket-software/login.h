#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "profile.h"
#include "filemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_logInBtn_clicked();
    void on_BTNSign_clicked();

private:
    Ui::Login *ui;
    Profile *profile = new Profile();
    FileManager fManager;
    //MainScreen mScreen();
    bool signedIn = false;
    int userIndex;
};
#endif // LOGIN_H

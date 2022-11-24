#include "login.h"
#include "ui_login.h"
#include "filemanager.h"
#include "SHA256.h"

#include <cstring>
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QVector>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void Login::on_logInBtn_clicked()
{
    QString username = ui->lineEditUsername->text();
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].username == username) {
            if (myFiles.validateUser(users[userIdx].uniqueIdentifier, ui->lineEditPassword->text())) {
                FileManager::StateData state;
                state.newPage = 1;
                state.userID = users[userIdx].uniqueIdentifier;
                state.password = ui->lineEditPassword->text();
                myFiles.saveState(state);
                closing = false;
                this->close();
                return;
            }
        }
    }
    QMessageBox::warning(this, "Login", "Incorrect username or password. Please try again");
}

void Login::on_hidePasswordButton_clicked()
{
    if (ui->lineEditPassword->echoMode() == QLineEdit::Password) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
        ui->hidePasswordButton->setIcon(QIcon(":/Images/Images/showPasswordIcon.png"));
    }
    else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
        ui->hidePasswordButton->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
    }
}


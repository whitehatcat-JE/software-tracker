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
    delete ui;
}

void Login::on_logInBtn_clicked()
{
    bool signedIn = false;
    QLineEdit* username = ui->lineEditUsername;
    QLineEdit* password = ui->lineEditPassword;
    std::string hashedPassword = username->text().toStdString() + password->text().toStdString();
       SHA256 sha;
       sha.update(hashedPassword);
       uint8_t* digest = sha.digest();
       std::string userPass = SHA256::toString(digest);
    //qDebug() << QString::fromStdString(userPass);
    QVector<QVector<QString>> loginAccess = fManager.ReadFile("LoginInformation", 100);
    for(int i = 0; i < loginAccess.size(); i++){
        if(username->text() == loginAccess.at(i).at(0)){

            if( QString::fromStdString(userPass) == loginAccess.at(i).at(1)){
                signedIn = true;
                userIndex = i;
                //Determine messagebox button pressed
                QMessageBox box(this);
                box.setIcon(QMessageBox::Information);
                box.setText("Login Successful");
                box.setWindowTitle("Sign Up");
                box.setStandardButtons(QMessageBox::Ok);
                int returnVal = box.exec();

                //Determine messagebox button pressed
                switch(returnVal){
                case QMessageBox::Ok:
                //QMessageBox::information(this, "Login", "Login Successful");
                hide();
                profile->show();
            }

                }
        }
        else{
            continue;
        }
    }
    if(!signedIn){
        QMessageBox::warning(this, "Login", "Incorrect username or password. Please try again");
    }
}

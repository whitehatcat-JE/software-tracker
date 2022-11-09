#include "login.h"
#include "ui_login.h"
#include "filemanager.h"

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
    QVector<QVector<QString>> loginAccess = fManager.ReadFile("LoginInformation", 3);
    for(int i = 0; i < loginAccess.size(); i++){
        if(username->text() == loginAccess.at(i).at(0)){
            if(password->text() == loginAccess.at(i).at(1)){
                signedIn = true;
                userIndex = i;
                //Determine messagebox button pressed

                QMessageBox::information(this, "Login", "Login Successful");
                hide();
                profile->show();
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
//void Login::on_BTNSign_clicked(){
//    QLineEdit* username = ui->lineEditUsername;
//    QLineEdit* password = ui->lineEditPassword;
//    QVector<QString> content;
//    QVector<QVector<QString>> fileToCheck;

//    content.append(username->text());
//    content.append(password->text());
//    content.append("1");

//    if(fManager.CheckValidUser(username->text(), "LoginInformation")){
//        fManager.WriteFile("LoginInformation", content);

//        //Define message box content
//        QMessageBox box(this);
//        box.setIcon(QMessageBox::Information);
//        box.setText("You have successfully signed up");
//        box.setWindowTitle("Sign Up");
//        box.setStandardButtons(QMessageBox::Ok);
//        int returnVal = box.exec();

//        //Determine messagebox button pressed
//        switch(returnVal){
//        QMessageBox::information(this, "Login", "Login Successful");
//        hide();
//        profile->show();
//        };

//    }
//    else{
//        QMessageBox::warning(this, "Sign Up", "User with this name already exists");
//    }
//}

/*{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if(username == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Login Successful");
        hide();
        profile->show();
    }
    else {
        QMessageBox::warning(this, "Login", "Username and/or password not recognised");
    }
}*/


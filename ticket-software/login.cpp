#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

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
}


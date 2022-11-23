#include "ui_profile.h"
#include "profile.h"

#include <QMessageBox>
#include <QPixmap>
#include <QDialog>
#include <QButtonGroup>
#include <QSize>
#include <QLineEdit>
#include <QLabel>
#include <QBoxLayout>
#include <QAbstractButton>

Profile::Profile(QWidget *parent) :

    QWidget(parent),
    ui(new Ui::Profile) {
        ui->setupUi(this);

        ui->NameEdit->setVisible(false);
        ui->JobEdit->setVisible(false);
        ui->TimeEdit->setVisible(false);
        ui->LocationEdit->setVisible(false);
        ui->EmailEdit->setVisible(false);
        ui->NumberEdit->setVisible(false);

        ui->ProfileOp1->setVisible(false);
        ui->ProfileOp2->setVisible(false);
        ui->ProfileOp3->setVisible(false);
        ui->ProfileOp4->setVisible(false);
        ui->ProfileOp5->setVisible(false);
        ui->ProfileOp6->setVisible(false);
        ui->ProfileOp7->setVisible(false);
        ui->ProfileOp8->setVisible(false);
        ui->ProfileOp9->setVisible(false);



        ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/empty.png);");


        ui->EditDetails->setIcon(QIcon(":/Images/Images/editIcon.png"));
        ui->EditDetails->setIconSize(QSize(40,40));
        ui->EditProfilePic->setIcon(QIcon(":/Images/Images/editIcon.png"));
        ui->EditProfilePic->setIconSize(QSize(40,40));


        ui->ProfileOp1->setIcon(QIcon(":/Images/Images/PFP/bear.png"));
        ui->ProfileOp1->setIconSize(QSize(100,100));

        ui->ProfileOp2->setIcon(QIcon(":/Images/Images/PFP/cat.png"));
        ui->ProfileOp2->setIconSize(QSize(100,100));

        ui->ProfileOp3->setIcon(QIcon(":/Images/Images/PFP/chicken.png"));
        ui->ProfileOp3->setIconSize(QSize(100,100));

        ui->ProfileOp4->setIcon(QIcon(":/Images/Images/PFP/GrayDog.png"));
        ui->ProfileOp4->setIconSize(QSize(100,100));

        ui->ProfileOp5->setIcon(QIcon(":/Images/Images/PFP/dog.png"));
        ui->ProfileOp5->setIconSize(QSize(100,100));

        ui->ProfileOp6->setIcon(QIcon(":/Images/Images/PFP/koala.png"));
        ui->ProfileOp6->setIconSize(QSize(100,100));

        ui->ProfileOp7->setIcon(QIcon(":/Images/Images/PFP/panda.png"));
        ui->ProfileOp7->setIconSize(QSize(100,100));

        ui->ProfileOp8->setIcon(QIcon(":/Images/Images/PFP/rabbit.png"));
        ui->ProfileOp8->setIconSize(QSize(100,100));

        ui->ProfileOp9->setIcon(QIcon(":/Images/Images/PFP/YellowRabbit.png"));
        ui->ProfileOp9->setIconSize(QSize(100,100));
    }


void Profile::on_EditDetails_clicked(bool checked)
{
    if (checked == true) {

        ui->EditDetails->setIcon(QIcon(":/Images/Images/Checkmark.png"));
        ui->EditDetails->setIconSize(QSize(40,40));

        QString nameStr = ui->NameEdit->text();
        QString jobStr = ui->JobEdit->text();
        QString timeStr = ui->TimeEdit->text();
        QString locationStr = ui->LocationEdit->text();
        QString emailStr = ui->EmailEdit->text();
        QString numberStr = ui->NumberEdit->text();

        ui->NameEdit->setVisible(true);
        ui->JobEdit->setVisible(true);
        ui->TimeEdit->setVisible(true);
        ui->LocationEdit->setVisible(true);
        ui->EmailEdit->setVisible(true);
        ui->NumberEdit->setVisible(true);
    }
    else {

        ui->EditDetails->setIcon(QIcon(":/Images/Images/editIcon.png"));
        ui->EditDetails->setIconSize(QSize(40,40));

        ui->NameEdit->setVisible(false);
        ui->JobEdit->setVisible(false);
        ui->TimeEdit->setVisible(false);
        ui->LocationEdit->setVisible(false);
        ui->EmailEdit->setVisible(false);
        ui->NumberEdit->setVisible(false);
    }
}

void Profile::on_EditProfilePic_clicked(bool checked)
{
    if (checked == true) {

        ui->EditProfilePic->setIcon(QIcon(":/Images/Images/Checkmark.png"));
        ui->EditProfilePic->setIconSize(QSize(40,40));

        ui->ProfileOp1->setVisible(true);
        ui->ProfileOp2->setVisible(true);
        ui->ProfileOp3->setVisible(true);
        ui->ProfileOp4->setVisible(true);
        ui->ProfileOp5->setVisible(true);
        ui->ProfileOp6->setVisible(true);
        ui->ProfileOp7->setVisible(true);
        ui->ProfileOp8->setVisible(true);
        ui->ProfileOp9->setVisible(true);

    }
    else {

        ui->EditProfilePic->setIcon(QIcon(":/Images/Images/editIcon.png"));
        ui->EditProfilePic->setIconSize(QSize(40,40));

        ui->ProfileOp1->setVisible(false);
        ui->ProfileOp2->setVisible(false);
        ui->ProfileOp3->setVisible(false);
        ui->ProfileOp4->setVisible(false);
        ui->ProfileOp5->setVisible(false);
        ui->ProfileOp6->setVisible(false);
        ui->ProfileOp7->setVisible(false);
        ui->ProfileOp8->setVisible(false);
        ui->ProfileOp9->setVisible(false);
    }
}

void Profile::on_ProfileOp1_clicked() {
//    QPixmap profilePic(":/Images/Images/PFP/bear.png");
//    QLabel label("PFP");
//    label.setPixmap(profilePic);
//    label.show();
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/bear.png);");
}
void Profile::on_ProfileOp2_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/cat.png);");
}
void Profile::on_ProfileOp3_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/chicken.png);");
}
void Profile::on_ProfileOp4_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/GrayDog.png);");
}
void Profile::on_ProfileOp5_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/dog.png);");
}
void Profile::on_ProfileOp6_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/koala.png);");
}
void Profile::on_ProfileOp7_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/panda.png);");
}
void Profile::on_ProfileOp8_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/rabbit.png);");
}
void Profile::on_ProfileOp9_clicked() {
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/YellowRabbit.png);");
}

void Profile::on_changePassword_clicked()
{
    QDialog* popup = new QDialog();
    QRect passwordPopupSize(0,0,500,300);


    popup->setStyleSheet("background-color: qlineargradient(spread:pad, x0:1, y2:1, x2:0, y2:1, stop:0 rgba(1, 15, 17, 255), stop:1 rgba(4, 15, 101, 255)); height: 300px; width 500px");


    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* hLayout1 = new QHBoxLayout();
    QHBoxLayout* hLayout2 = new QHBoxLayout();
    QHBoxLayout* hLayout3 = new QHBoxLayout();
    //QHBoxLayout* hLayout4 = new QHBoxLayout();
    QSpacerItem* spacer = new QSpacerItem(30,0,QSizePolicy::Expanding);

    QLabel* Title = new QLabel(popup);
    Title->setText("Hello");
    QPushButton* echoSwitchBtn = new QPushButton();
    echoSwitchBtn->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
    echoSwitchBtn->setIconSize(QSize(50,50));
    echoSwitchBtn->setStyleSheet("height: 50px; width 50px");
    QPushButton* echoSwitchBtn2 = new QPushButton();
    echoSwitchBtn->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
    echoSwitchBtn->setIconSize(QSize(50,50));
    QLineEdit* passwordField = new QLineEdit(popup);
    passwordField->setStyleSheet("height: 50px; width 100px");
    QLineEdit* oldPassword = new QLineEdit(popup);
    oldPassword->setText("World");
    oldPassword->setStyleSheet("height: 50px; width 100px");


    popup->setLayout(vLayout);

    popup->setGeometry(passwordPopupSize);

    vLayout->addSpacerItem(spacer);

    hLayout1->addSpacerItem(spacer);
    hLayout1->addWidget(Title);
    hLayout1->addSpacerItem(spacer);
    vLayout->addLayout(hLayout1);

    hLayout2->addSpacerItem(spacer);
    hLayout2->addWidget(oldPassword);
    hLayout2->addWidget(echoSwitchBtn);
    hLayout2->addSpacerItem(spacer);
    vLayout->addLayout(hLayout2);

    hLayout3->addSpacerItem(spacer);
    hLayout3->addWidget(passwordField);
    hLayout3->addWidget(echoSwitchBtn2);
    hLayout3->addSpacerItem(spacer);
    vLayout->addLayout(hLayout3);

    vLayout->addSpacerItem(spacer);



    popup->exec();


    //Needs Label with current password
    //Line Edit for new password
    //2 Buttons to hide passwords (Need help getting them on popup)
    //Cancel & Confirm Button (Same propety for now)

}


Profile::~Profile()
{
    delete ui;
}

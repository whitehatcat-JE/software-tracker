#include "ui_profile.h"
#include "profile.h"

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

        updateInfo();
    }


void Profile::updateInfo() {
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    FileManager::StateData state = myFiles.loadState();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (state.userID == users[userIdx].uniqueIdentifier) {
            ui->Name->setText(users[userIdx].username);
            ui->NameEdit->setText(users[userIdx].username);
            ui->JobTitle->setText(users[userIdx].job);
            ui->JobEdit->setText(users[userIdx].job);
            ui->workHours->setText(users[userIdx].activeTimes);
            ui->TimeEdit->setText(users[userIdx].activeTimes);
            ui->location->setText(users[userIdx].location);
            ui->LocationEdit->setText(users[userIdx].location);
            ui->number->setText(users[userIdx].phone);
            ui->NumberEdit->setText(users[userIdx].phone);
            ui->email->setText(users[userIdx].email);
            ui->EmailEdit->setText(users[userIdx].email);

            updateProfilePic(users[userIdx].profilePicID);
            return;
        }
    }
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
    } else {

        ui->EditDetails->setIcon(QIcon(":/Images/Images/editIcon.png"));
        ui->EditDetails->setIconSize(QSize(40,40));

        ui->NameEdit->setVisible(false);
        ui->JobEdit->setVisible(false);
        ui->TimeEdit->setVisible(false);
        ui->LocationEdit->setVisible(false);
        ui->EmailEdit->setVisible(false);
        ui->NumberEdit->setVisible(false);

        FileManager myFiles;
        QVector<FileManager::User> users = myFiles.loadUsers();
        FileManager::StateData state = myFiles.loadState();
        for (int userIdx = 0; userIdx < users.size(); userIdx++) {
            if (state.userID == users[userIdx].uniqueIdentifier) {
                users[userIdx].username = ui->NameEdit->text();
                users[userIdx].job = ui->JobEdit->text();
                users[userIdx].activeTimes = ui->TimeEdit->text();
                users[userIdx].location = ui->LocationEdit->text();
                users[userIdx].phone = ui->NumberEdit->text();
                users[userIdx].email = ui->EmailEdit->text();
            }
        }
        myFiles.saveUsers(users);
        updateInfo();
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

    } else {
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

void Profile::updateProfilePic(int profilePicID) {
    FileManager myFiles;
    ui->PFP->setStyleSheet("border-image:url(:/Images/Images/PFP/" + myFiles.getAvatar(profilePicID) + ".png);");
    QVector<FileManager::User> users = myFiles.loadUsers();
    FileManager::StateData state = myFiles.loadState();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (state.userID == users[userIdx].uniqueIdentifier) {
            users[userIdx].profilePicID = profilePicID;
        }
    }
    myFiles.saveUsers(users);
}

void Profile::on_ProfileOp1_clicked() { updateProfilePic(0); }
void Profile::on_ProfileOp2_clicked() { updateProfilePic(1); }
void Profile::on_ProfileOp3_clicked() { updateProfilePic(2); }
void Profile::on_ProfileOp4_clicked() { updateProfilePic(3); }
void Profile::on_ProfileOp5_clicked() { updateProfilePic(4); }
void Profile::on_ProfileOp6_clicked() { updateProfilePic(5); }
void Profile::on_ProfileOp7_clicked() { updateProfilePic(6); }
void Profile::on_ProfileOp8_clicked() { updateProfilePic(7); }
void Profile::on_ProfileOp9_clicked() { updateProfilePic(8); }

void Profile::hidePassword(QPushButton* echoSwitch, QLineEdit* password) {
    if (password->echoMode() == QLineEdit::Password) {
        password->setEchoMode(QLineEdit::Normal);
    }
    else {
        password->setEchoMode(QLineEdit::Password);
    }
}

void Profile::confirmButtonPressed(QDialog* confirm) {
    confirm->close();
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
        QHBoxLayout* hLayout4 = new QHBoxLayout();
        QSpacerItem* spacer = new QSpacerItem(30,0,QSizePolicy::Expanding);

        QLabel* Title = new QLabel(popup);
        Title->setText("Change Password");
        Title->setStyleSheet("background: transparent; font-size: 20px;");

        QLineEdit* oldPassword = new QLineEdit(popup);
        oldPassword->setText("World");
        oldPassword->setReadOnly(true);
        oldPassword->setStyleSheet("height: 50px; width 100px; color: #FFFFFF;");
        QPushButton* echoSwitchBtn = new QPushButton();
        echoSwitchBtn->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
        echoSwitchBtn->setIconSize(QSize(50,50));
        echoSwitchBtn->setCheckable(true);
        echoSwitchBtn->setChecked(true);
        echoSwitchBtn->setStyleSheet("height: 50px; width 50px; background: transparent; color: #FFFFFF;");
        connect(echoSwitchBtn, &QPushButton::clicked, [this, echoSwitchBtn, oldPassword] { hidePassword(echoSwitchBtn, oldPassword); });

        QLineEdit* passwordField = new QLineEdit(popup);
        passwordField->setStyleSheet("height: 50px; width 100px; color: #FFFFFF;");
        QPushButton* echoSwitchBtn2 = new QPushButton();
        echoSwitchBtn2->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
        echoSwitchBtn2->setIconSize(QSize(50,50));
        echoSwitchBtn2->setStyleSheet("height: 50px; width 50px; background: transparent; color: #ffffff");
        connect(echoSwitchBtn, &QPushButton::clicked, [this, echoSwitchBtn2, passwordField] { hidePassword(echoSwitchBtn2, passwordField); });

        QPushButton* confirmBtn = new QPushButton();
        confirmBtn->setStyleSheet("height: 50px; width 120px; background: red; color: white;");
        confirmBtn->setText("Confirm");
        connect(confirmBtn, &QPushButton::clicked, [this, popup] { confirmButtonPressed(popup); });

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

        hLayout4->addSpacerItem(spacer);
        hLayout4->addWidget(confirmBtn);
        hLayout4->addSpacerItem(spacer);
        vLayout->addLayout(hLayout4);

        vLayout->addSpacerItem(spacer);

        popup->exec();
}


Profile::~Profile()
{
    if (closing) {
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    }
    delete ui;
}

void Profile::on_assignButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 2;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Profile::on_profileButton_clicked()
{
    return;
}


void Profile::on_managementButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 7;
    myFiles.saveState(state);
    closing = false;
    this->close();
}


void Profile::on_logoutButton_clicked()
{
    FileManager myFiles;
    FileManager::StateData state;
    state.newPage = 0;
    myFiles.saveState(state);
    closing = false;
    this->close();
}



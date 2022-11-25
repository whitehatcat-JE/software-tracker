#include "login.h"
#include "ui_login.h"

// Login constructor
Login::Login(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Login) {
    ui->setupUi(this);
}

// Login destructor
Login::~Login() {
    if (closing) { // Checks if user is trying to quit program
        FileManager myFiles;
        FileManager::StateData currentState;
        currentState.newPage = -1;
        myFiles.saveState(currentState);
    } delete ui; // Closes page
}
// Attempts to login user
void Login::on_logInBtn_clicked() {
    QString username = ui->lineEditUsername->text(); // Gets inputted username
    // Loops through all users
    FileManager myFiles;
    QVector<FileManager::User> users = myFiles.loadUsers();
    for (int userIdx = 0; userIdx < users.size(); userIdx++) {
        if (users[userIdx].username == username) {
            // Checks if user password matches
            if (myFiles.validateUser(users[userIdx].uniqueIdentifier, ui->lineEditPassword->text())) {
                // Changes to profile page
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
    // Error message were invalid login information has been inputted
    QMessageBox::warning(this, "Login", "Incorrect username or password. Please try again");
}

// Hides / shows password text
void Login::on_hidePasswordButton_clicked() {
    if (ui->lineEditPassword->echoMode() == QLineEdit::Password) { // Shows password text
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
        ui->hidePasswordButton->setIcon(QIcon(":/Images/Images/showPasswordIcon.png"));
    } else { // Hides password text
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
        ui->hidePasswordButton->setIcon(QIcon(":/Images/Images/hiddenPasswordIcon.png"));
    }
}

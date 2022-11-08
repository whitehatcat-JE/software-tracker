#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include <QMainWindow>
//#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>
#include <QLineEdit>
#include <QBoxLayout>

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
    //void on_Edit_clicked();
    void on_Edit_clicked();

private:


    Ui::Profile *ui;
    QDialog* popup = new QDialog(this);
    //Access Central widget on popup window
    //Assign a vertical layout group
    //Access central widget and use function
    //cWidget->addWidget(nameField);
    //cWidget->addWidget(timeZone);
    //cWidget->addWidget(contactInfo);
    QLineEdit* nameField = new QLineEdit(popup);
    QLineEdit* timeZone = new QLineEdit(popup);
    QLineEdit* EmailContact = new QLineEdit(popup);
    QLineEdit* PhoneContact = new QLineEdit(popup);

};

#endif // PROFILE_H

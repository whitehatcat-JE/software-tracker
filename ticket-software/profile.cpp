#include "ui_profile.h"
#include "profile.h"
#include <QMessageBox>
#include <QPixelMap>
#include <QDialog>
#include <QButtonGroup>


Profile::Profile(QWidget *parent) :

    QWidget(parent),
    ui(new Ui::Profile) {
        ui->setupUi(this);

        //QPixmap pfp = map.scaled(100, 100, Qt::KeepAspectRatio);
    }



void Profile::on_Edit_clicked()
{
//    QPixmap pixmap(":/Images/Images/editIcon.png");
//    QIcon ButtonIcon(pixmap);
//    button->setIcon(ButtonIcon);
//    button->setIconSize(pixmap.rect().size());
//    for(QObject* obj : popup->children()){
//        if(dynamic_cast<QObject>(QWidget)){

//        }
//    }
//    popup->c;
//    popup->exec();


}


Profile::~Profile()
{
    delete ui;
}

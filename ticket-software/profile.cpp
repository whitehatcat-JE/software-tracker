#include "profile.h"
#include "ui_profile.h"


Profile::Profile(QWidget *parent) :

    QWidget(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);

}




void Profile::on_Edit_clicked()
{
    qDebug() << "hit";
    for(QObject* obj : popup->children()){
        if(dynamic_cast<QObject>(QWidget)){

        }
    }
    popup->c
    popup->exec();


}


Profile::~Profile()
{
    delete ui;
}

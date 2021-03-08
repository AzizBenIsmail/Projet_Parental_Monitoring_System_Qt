#include "animal.h"
#include "ui_animal.h"
#include "menu.h"
#include <QPixmap>

Animal::Animal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Animal)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/a.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Animal::~Animal()
{
    delete ui;
}

void Animal::on_pushButton_R_clicked()
{
    hide();
    Menu m;
    m.exec();
}

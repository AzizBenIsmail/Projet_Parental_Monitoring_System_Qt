#include "cuisine.h"
#include "ui_cuisine.h"
#include <QPixmap>
#include "menu.h"
cuisine::cuisine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuisine)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/cui.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

cuisine::~cuisine()
{
    delete ui;
}

void cuisine::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

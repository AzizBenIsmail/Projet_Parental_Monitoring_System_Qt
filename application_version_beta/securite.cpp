#include "securite.h"
#include "ui_securite.h"
#include "menu.h"
#include <QPixmap>
#include "QString"
Securite::Securite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Securite)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/5.jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}




Securite::~Securite()
{
    delete ui;
}

void Securite::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}



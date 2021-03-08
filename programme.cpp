#include "programme.h"
#include "ui_programme.h"
#include "menu.h"
#include <QPixmap>

programme::programme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programme)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/pro.jpg");
    int w=ui->label_a->width();
    int h=ui->label_a->height();
    ui->label_a->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

programme::~programme()
{
    delete ui;
}

void programme::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

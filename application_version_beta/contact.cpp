#include "contact.h"
#include "ui_contact.h"
#include "menu.h"
#include <QPixmap>

Contact::Contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contact)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/c.jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Contact::~Contact()
{
    delete ui;
}

void Contact::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

#include "mailing.h"
#include "ui_mailing.h"
#include "menu.h"
Mailing::Mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mailing)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

Mailing::~Mailing()
{
    delete ui;
}

void Mailing::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}


void Mailing::on_sendBtn_clicked()
{

}

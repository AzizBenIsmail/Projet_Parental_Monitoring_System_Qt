#include "emploi.h"
#include "ui_emploi.h"
#include "programme.h"
emploi::emploi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emploi)
{
    ui->setupUi(this);
}

emploi::~emploi()
{
    delete ui;
}

void emploi::on_pushButton_clicked()
{
    hide();
    programme p;
    p.exec();
}

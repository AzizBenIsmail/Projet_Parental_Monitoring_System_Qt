#include "modifemp.h"
#include "ui_modifemp.h"

Modifemp::Modifemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifemp)
{
    ui->setupUi(this);
}

Modifemp::~Modifemp()
{
    delete ui;
}

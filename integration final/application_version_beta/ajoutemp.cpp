#include "ajoutemp.h"
#include "ui_ajoutemp.h"

Ajoutemp::Ajoutemp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajoutemp)
{
    ui->setupUi(this);
}

Ajoutemp::~Ajoutemp()
{
    delete ui;
}

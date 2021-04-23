#include "ajoutfourntiture.h"
#include "ui_ajoutfourntiture.h"

AjoutFourntiture::AjoutFourntiture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutFourntiture)
{
    ui->setupUi(this);
}

AjoutFourntiture::~AjoutFourntiture()
{
    delete ui;
}

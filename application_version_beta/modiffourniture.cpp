#include "modiffourniture.h"
#include "ui_modiffourniture.h"

Modiffourniture::Modiffourniture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modiffourniture)
{
    ui->setupUi(this);
}

Modiffourniture::~Modiffourniture()
{
    delete ui;
}

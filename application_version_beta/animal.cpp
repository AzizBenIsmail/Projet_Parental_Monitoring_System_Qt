#include "animal.h"
#include "ui_animal.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
Animal::Animal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Animal)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/a.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Animal::~Animal()
{
    delete ui;
}

void Animal::on_pushButton_R_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void Animal::on_pushButton_Q_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur esque tu est sur tu veux quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "bayy bayy", "Ala pouchane !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Helloo", "Alors bienvenue!");
        }
}

#include "sante.h"
#include "ui_sante.h"
#include "menu.h"
#include <QPixmap>
#include "suivie_medical.h"
#include "medicament.h"
#include "QMessageBox"
Sante::Sante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sante)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/s.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Sante::~Sante()
{
    delete ui;
}

void Sante::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void Sante::on_pushButton_S_clicked()
{
    hide();
    Suivie_medical s;
    s.exec();
}

void Sante::on_pushButton_2_clicked()
{
     hide();
     medicament me;
     me.exec();
}

void Sante::on_pushButton_Q_clicked()
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

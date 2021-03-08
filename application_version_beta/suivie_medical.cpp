#include "suivie_medical.h"
#include "ui_suivie_medical.h"
#include "sante.h"
#include "QMessageBox"
#include "QPixmap"
Suivie_medical::Suivie_medical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suivie_medical)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/..jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Suivie_medical::~Suivie_medical()
{
    delete ui;
}

void Suivie_medical::on_pushButton_R_clicked()
{
    hide();
    Sante m;
    m.exec();
}

void Suivie_medical::on_pushButton_Q_clicked()
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

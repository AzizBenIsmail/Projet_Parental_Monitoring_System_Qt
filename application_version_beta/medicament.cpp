#include "medicament.h"
#include "ui_medicament.h"
#include"sante.h"
#include "QMessageBox"
#include "QPixmap"
medicament::medicament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medicament)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/..jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

medicament::~medicament()
{
    delete ui;
}

void medicament::on_pushButton_R_clicked()
{
    hide();
    Sante s;
    s.exec();
}

void medicament::on_pushButton_Q_clicked()
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

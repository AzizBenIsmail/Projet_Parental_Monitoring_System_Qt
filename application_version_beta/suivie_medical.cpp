#include "suivie_medical.h"
#include "ui_suivie_medical.h"
#include "sante.h"
#include "QMessageBox"
#include "QPixmap"
#include"suivi.h"
#include <QIntValidator>
#include <QSqlQueryModel>
Suivie_medical::Suivie_medical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suivie_medical)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(e.afficher());
    ui->_id->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_idS->setValidator(new QIntValidator(0,9999999,this));

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

void Suivie_medical::on_pushButton_ajouter_clicked()
{
    int id=ui->_id->text().toInt();
        int taille=ui->_taille->text().toInt();
        int poid=ui->_poid->text().toInt();
       int tension=ui->_tenstion->text().toInt();
        int date=ui->_date->text().toInt();

        suivi E(id,taille,poid,tension,date);
        bool test=E.Ajouter();
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView_aff->setModel(E.afficher());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Suivie_medical::on_pushButton_S_clicked()
{
    suivi e1;
    e1.setid(ui->lineEdit_idS->text().toInt());
    bool test;
    test=e1.Supprime(e1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(e1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

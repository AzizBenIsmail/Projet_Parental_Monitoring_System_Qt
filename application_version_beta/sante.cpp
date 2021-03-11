#include "sante.h"
#include "ui_sante.h"
#include "menu.h"
#include <QPixmap>
#include "suivie_medical.h"
#include "QMessageBox"
#include"suivi.h"
#include <QIntValidator>
#include <QSqlQueryModel>
Sante::Sante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sante)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(e.afficher());

    ui->_id->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_idS->setValidator(new QIntValidator(0,9999999,this));

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


void Sante::on_pushButton_Sui_clicked()
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

void Sante::on_pushButton_ajout_clicked()
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

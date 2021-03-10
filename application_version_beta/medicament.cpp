#include "medicament.h"
#include "ui_medicament.h"
#include"sante.h"
#include "QMessageBox"
#include "QPixmap"
#include <QIntValidator>
#include <QSqlQueryModel>
#include "medic.h"
medicament::medicament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medicament)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(c.afficher());
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

void medicament::on_pushButton_ajouter_clicked()
{

    int id=ui->id->text().toInt();
        QString nom=ui->Nom->text();
        QString prenom=ui->prenom->text();
        Medic E(id,nom,prenom);
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

void medicament::on_pushButton_S_clicked()
{
    Medic e1;
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

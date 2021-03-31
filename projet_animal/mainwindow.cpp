#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animal.h"
#include "Fiche_animal.h"
#include<iostream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_Ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
     int age=ui->lineEdit_age->text().toInt();
           float prix = ui->lineEdit_prix->text().toFloat();
       QString nom = ui->lineEdit_nom->text();
       QString race = ui->lineEdit_race->text();
       QString sexe = ui->lineEdit_sexe->text();
       if (id < 0 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem id"),
                       QObject::tr("verifier id\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (age < 0 || age > 50 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem age"),
                       QObject::tr("verifier age\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
      else  if (prix < 0  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem prix"),
                       QObject::tr("verifier prix\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (nom==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                       QObject::tr("verifier nom\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (race==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem race"),
                       QObject::tr("verifier race\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (sexe==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem sexe"),
                       QObject::tr("verifier sexe\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           Animal a(id,age,prix,nom,race,sexe);

            a.ajouter();


           ui->tableView->setModel(a.afficher());
       }

}

void MainWindow::on_Afficher_clicked()
{
    Animal a(1,1,1,"","","");
    ui->tableView->setModel(a.afficher());
}

void MainWindow::on_Supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
     Animal a(1,1,1,"","","");
     a.supprimer(id);
         ui->tableView->setModel(a.afficher());
}



void MainWindow::on_Modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
     int age=ui->lineEdit_age->text().toInt();
           float prix = ui->lineEdit_prix->text().toFloat();
       QString nom = ui->lineEdit_nom->text();
       QString race = ui->lineEdit_race->text();
       QString sexe = ui->lineEdit_sexe->text();
       if (id < 0 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem id"),
                       QObject::tr("verifier id\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (age < 0 || age > 50 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem age"),
                       QObject::tr("verifier age\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
      else  if (prix < 0  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem prix"),
                       QObject::tr("verifier prix\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (nom==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                       QObject::tr("verifier nom\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (race==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem race"),
                       QObject::tr("verifier race\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (sexe==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem sexe"),
                       QObject::tr("verifier sexe\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {

           Animal a(id,age,prix,nom,race,sexe);
           a.modifier();
                 ui->tableView->setModel(a.afficher());
       }

}

void MainWindow::on_Afficher_2_clicked()
{
    Fiche_animal a(1,1,1,1,1,"");
    ui->tableView_2->setModel(a.afficher());
}

void MainWindow::on_Supprimer_fiche_clicked()
{
    int id = ui->lineEdit_id_Fiche_animal->text().toInt();
   Fiche_animal a(1,1,1,1,1,"");
     a.supprimer(id);
         ui->tableView_2->setModel(a.afficher());
}

void MainWindow::on_Ajouter_FICHE_clicked()
{

    int id=ui->lineEdit_id_Fiche_animal->text().toInt();
     int poid=ui->lineEdit_poid_fiche->text().toInt();
           int taille = ui->lineEdit_taille_fiche->text().toInt();
               int nbr = ui->lineEdit_nbr_fiche->text().toInt();
       QString date = ui->date_fiche->text();
     int id_animal = ui->lineEdit_id_animal_fiche->text().toInt();
     if (id < 0 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id"),
                     QObject::tr("verifier id\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (poid < 0 || poid > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                     QObject::tr("verifier poid\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
    else  if (taille < 0 || taille > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                     QObject::tr("verifier taille\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (nbr==0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem nbr"),
                     QObject::tr("verifier nom\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (id_animal<0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id_animal"),
                     QObject::tr("verifier id_animal\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
   else
     {Fiche_animal a(id,poid,taille,nbr,id_animal,date);

         a.ajouter();
          ui->tableView_2->setModel(a.afficher());
     }

}

void MainWindow::on_Modifier_fiche_clicked()
{
    int id=ui->lineEdit_id_Fiche_animal->text().toInt();
     int poid=ui->lineEdit_poid_fiche->text().toInt();
           int taille = ui->lineEdit_taille_fiche->text().toInt();
               int nbr = ui->lineEdit_nbr_fiche->text().toInt();
       QString date = ui->date_fiche->text();
     int id_animal = ui->lineEdit_id_animal_fiche->text().toInt();
     if (id < 0 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id"),
                     QObject::tr("verifier id\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (poid < 0 || poid > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                     QObject::tr("verifier poid\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
    else  if (taille < 0 || taille > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                     QObject::tr("verifier taille\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (nbr==0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem nbr"),
                     QObject::tr("verifier nbr\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (id_animal<0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id_animal"),
                     QObject::tr("verifier id_animal\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
     {
         Fiche_animal a(id,poid,taille,nbr,id_animal,date);

          a.modifier();
           ui->tableView_2->setModel(a.afficher());
     }

}

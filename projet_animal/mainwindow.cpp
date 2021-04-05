#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animal.h"
#include "Fiche_animal.h"
#include<iostream>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/asus/Desktop/projet_animal/123.jpg");
        int w=ui->label_p->width();
        int h=ui->label_p->height();
               ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pix1("C:/Users/asus/Desktop/projet_animal/123.jpg");
            int w1=ui->label_p_3->width();
            int h1=ui->label_p_3->height();
        ui->label_p_3->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    ui->lineEdit_id->setPlaceholderText("Put ID");
    ui->lineEdit_age->setPlaceholderText("Put age");
    ui->lineEdit_prix->setPlaceholderText("Put Prix");
    ui->lineEdit_nom->setPlaceholderText("Put nom");
    ui->lineEdit_race->setPlaceholderText("Put race");
    ui->lineEdit_sexe->setPlaceholderText("Put sex");
    ui->txt_recherche_animal->setPlaceholderText("Put critère");
    ui->lineEdit_id_Fiche_animal->setPlaceholderText("Put ID");
    ui->lineEdit_poid_fiche->setPlaceholderText("Put poids");
    ui->lineEdit_taille_fiche->setPlaceholderText("Put taille");
    ui->lineEdit_nbr_fiche->setPlaceholderText("Put nombre_fiche ");
    ui->lineEdit_id_animal_fiche->setPlaceholderText("Put ID");
    ui->etat_text->setPlaceholderText("Put etat");
    ui->nom_maladie->setPlaceholderText("Put maladie");
    ui->lineEdit_id_Fiche_animal->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_poid_fiche->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_nbr_fiche->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_id_animal_fiche->setStyleSheet("QLineEdit { color: grey;}");
    ui->etat_text->setStyleSheet("QLineEdit { color: grey;}");
    ui->nom_maladie->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_taille_fiche->setStyleSheet("QLineEdit { color: grey;}");

    ui->lineEdit_id->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_age->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_prix->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_nom->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_race->setStyleSheet("QLineEdit { color: grey;}");
    ui->lineEdit_sexe->setStyleSheet("QLineEdit { color: grey;}");
    ui->txt_recherche_animal->setStyleSheet("QLineEdit { color: grey;}");
    ui->label_id->setStyleSheet ("Font : 12pt");
    ui->label_id->setStyleSheet ("Font : bold");
    ui->label_age->setStyleSheet ("Font : 12pt");
    ui->label_age->setStyleSheet ("Font : bold");
    ui->label_prix->setStyleSheet ("Font : 12pt");
    ui->label_prix->setStyleSheet ("Font : bold");
    ui->label_nom->setStyleSheet ("Font : 12pt");
    ui->label_nom->setStyleSheet ("Font : bold");
    ui->label_race->setStyleSheet ("Font : 12pt");
    ui->label_race->setStyleSheet ("Font : bold");
    ui->label_sexe->setStyleSheet ("Font : 12pt");
    ui->label_sexe->setStyleSheet ("Font : bold");
    ui->label_animal->setStyleSheet ("Font : 12pt");
    ui->label_animal->setStyleSheet ("Font : bold");
    ui->label_date->setStyleSheet ("Font : 12pt");
    ui->label_date->setStyleSheet ("Font : bold");
    ui->label_3->setStyleSheet ("Font : 12pt");
    ui->label_3->setStyleSheet ("Font : bold");
    ui->label_critere->setStyleSheet ("Font : 12pt");
    ui->label_critere->setStyleSheet ("Font : bold");

    ui->label_id_2->setStyleSheet ("Font : 12pt");
    ui->label_id_2->setStyleSheet ("Font : bold");
    ui->label_4->setStyleSheet ("Font : 12pt");
    ui->label_4->setStyleSheet ("Font : bold");
    ui->label_prix_2->setStyleSheet ("Font : 12pt");
    ui->label_prix_2->setStyleSheet ("Font : bold");
    ui->label_nom_2->setStyleSheet ("Font : 12pt");
    ui->label_nom_2->setStyleSheet ("Font : bold");
    ui->label_nom_3->setStyleSheet ("Font : 12pt");
    ui->label_nom_3->setStyleSheet ("Font : bold");
    ui->label_nom_4->setStyleSheet ("Font : 12pt");
    ui->label_nom_4->setStyleSheet ("Font : bold");
    ui->label_6->setStyleSheet ("Font : 12pt");
    ui->label_6->setStyleSheet ("Font : bold");
    ui->label_7->setStyleSheet ("Font : 12pt");
    ui->label_7->setStyleSheet ("Font : bold");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
     int age=ui->lineEdit_age->text().toInt();
           float prix = ui->lineEdit_prix->text().toFloat();
       QString nom = ui->lineEdit_nom->text();
       QString race = ui->lineEdit_race->text();
       QString sexe = ui->lineEdit_sexe->text();
       QString date_achat = ui->date_achat->text();
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

           Animal a(id,age,prix,nom,race,sexe,date_achat);

            a.ajouter();


           ui->tableView->setModel(a.afficher());
       }

}

void MainWindow::on_Afficher_clicked()
{
    Animal a(1,1,1,"","","","");
    ui->tableView->setModel(a.afficher());
}

void MainWindow::on_Supprimer_clicked()
{

     Animal a(1,1,1,"","","","");
     a.supprimer()->removeRow(ui->tableView->currentIndex().row());

         ui->tableView->setModel(a.afficher());
}






void MainWindow::on_Supprimer_fiche_clicked()
{


   Fiche_animal a(1,1,1,1,1,"","","");
     a.supprimer()->removeRow(ui->tableView_2->currentIndex().row());
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
     QString etat = ui->etat_text->text();
     QString nom_malade = ui->nom_maladie->text();
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
     else if (etat=="" )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem etat"),
                     QObject::tr("verifier etat\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (nom_malade=="" )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem nom_malade"),
                     QObject::tr("verifier nom_malade\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
   else
     {Fiche_animal a(id,poid,taille,nbr,id_animal,date,etat,nom_malade);

         a.ajouter();
          ui->tableView_2->setModel(a.afficher());
     }

}


void MainWindow::on_Tr_Animal_clicked()
{

    Animal a(1,1,1,"","","","");
    ui->tableView->setModel(a.tri(ui->tableView->currentIndex().column()));

}

void MainWindow::on_txt_recherche_animal_textChanged(const QString &arg1)
{
   Animal c(1,1,1,"","","","");
        c.cleartable(ui->tableView);
        QString cas =ui->txt_recherche_animal->text();
        c.rechercher(ui->tableView,cas);

        if(ui->txt_recherche_animal->text().isEmpty())
        {
            ui->tableView->setModel(c.afficher());
        }
}


void MainWindow::on_Afficher_Fiche_clicked()
{
    Fiche_animal a(1,1,1,1,1,"","","");

          ui->tableView_2->setModel(a.afficher());
}

void MainWindow::on_PDF_clicked()
{

    QSqlQueryModel model;
       model.setQuery("SELECT * FROM FICHE_ANIMAL");

        QString html = "<table  border='2'> <thead> <tr> <th>#</th> <th>Poid</th> <th>Taille</th> <th>NBR consultation</th> <th> ID Animal</th> <th> Date Vacc</th> <th> Etat</th><th> Nom Maladie </th>  </tr> </thead><tbody > ";


       for (int i = 0; i < model.rowCount(); ++i) {

           QString id = model.record(i).value("ID").toString();
                    QString poid = model.record(i).value("POID").toString();
                             QString taille = model.record(i).value("TAILLE").toString();
                              QString NBR_CONSULTATION = model.record(i).value("NBR_CONSULTATION").toString();
                                QString ID_ANNIMAL = model.record(i).value("ID_ANNIMAL").toString();
                                  QString DATE_VACC = model.record(i).value("DATE_VACC").toString();
                                          QString ETAT = model.record(i).value("ETAT").toString();
           QString name = model.record(i).value("NOM_MALADE").toString();
html += "<tr > <td>"+id+"</td> <td>"+poid+"</td> <td>"+taille+"</td><td>"+NBR_CONSULTATION+"</td><td>"+DATE_VACC+"</td><td>"+DATE_VACC+"</td><td>"+ETAT+"</td> <td>"+name+"</td></tr>";
       }
    html+="</tbody></table>";

      QTextDocument document;
      document.setHtml(html);

      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("Fiche.pdf");

      document.print(&printer);
}

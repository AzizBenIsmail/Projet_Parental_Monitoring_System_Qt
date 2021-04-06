#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "prestataire.h"
#include "enfant.h"
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>
#include <QDate>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0,9999999,this));
    ui->tableView_aff_2->setModel(e.afficher());
    ui->idpres->setValidator(new QIntValidator(0,9999999,this));
    ui->tableView_aff->setModel(P.afficher_pres());

QPixmap pix("C:/Users/LENOVO/OneDrive/Documents/prestataire_service/5.png");
   int w=ui->label_pic->width();
   int h=ui->label_pic->height();
   ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
   int a=ui->label_19->width();
       int b=ui->label_19->height();
       ui->label_19->setPixmap(pix.scaled(a,b,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

    int idpres=ui->idpres->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nompres=ui->nompres->text();
        QString prenompres=ui->prenompres->text();
        int salairepres=ui->salairepres->text().toInt();
        QString specialitepres=ui->specialitepres->text();
        QString dateembauchepres=ui->dateembauchepres->text();
        int nbr_heurespres=ui->nbr_heurespres->text().toInt();
        int telpres=ui->telpres->text().toInt();
        QString adressepres=ui->adressepres->text();
        QString sexepres=ui->sexepres->text();
         //prestataire P;
       prestataire P(idpres,nompres,prenompres,salairepres,specialitepres,dateembauchepres,nbr_heurespres,telpres,adressepres,sexepres);
       
        bool test=P.Ajouter_pres();
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff->setModel(P.afficher_pres());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_pushButton_3_clicked()
{
    {
        prestataire P1;
        P1.setidpres(ui->lineEdit_11->text().toInt());
        bool test;
        test=P1.Supprime_pres(P1.getidpres());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_aff->setModel(P1.afficher_pres());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void MainWindow::on_pushButton_clicked()
{
    int idpres=ui->idpres->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nompres=ui->nompres->text();
        QString prenompres=ui->prenompres->text();
        int salairepres=ui->salairepres->text().toInt();
        QString specialitepres=ui->specialitepres->text();
        QString dateembauchepres=ui->dateembauchepres->text();
        int nbr_heurespres=ui->nbr_heurespres->text().toInt();
        int telpres=ui->telpres->text().toInt();
        QString adressepres=ui->adressepres->text();
        QString sexepres=ui->sexepres->text();
         //prestataire P;
       prestataire P(idpres,nompres,prenompres,salairepres,specialitepres,dateembauchepres,nbr_heurespres,telpres,adressepres,sexepres);

        bool test=P.modifier_pres(idpres);
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("modifier avec succes"),
                                     QObject::tr("modifier successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff->setModel(P.afficher_pres());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("modifier errer"),
                                     QObject::tr("modifier failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }

void MainWindow::on_pushButton_4_clicked()
{
    prestataire P(1,"","",1,"","",1,1,"","");
      // e.cleartable(ui->tableView_aff);
       QString cas =ui->lineEdit_r->text();
       P.rechercher(ui->tableView_aff,cas);

       if(ui->lineEdit_r->text().isEmpty())
       {
           ui->tableView_aff->setModel(P.afficher_pres());
       }
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->id->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nom_prenom=ui->nom_prenom->text();
        QString etat_psycologique=ui->etat_psycologique->text();
        QString talent=ui->talent->text();
        QString sexe=ui->sexe->text();
         enfant E(id,nom_prenom,etat_psycologique,talent,sexe);
        bool test=E.Ajouter();
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff_2->setModel(E.afficher());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_6_clicked()
{

    int id=ui->id->text().toInt();
          // QString date_naissance=ui->date_naissance->date();
           QString nom_prenom=ui->nom_prenom->text();
           QString etat_psycologique=ui->etat_psycologique->text();
           QString talent=ui->talent->text();
           QString sexe=ui->sexe->text();
            enfant E(id,nom_prenom,etat_psycologique,talent,sexe);
           bool test=E.modifier(id);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_2->setModel(E.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_10_clicked()
{
    {
         enfant e1;
        e1.setid(ui->lineEdit_idS_2->text().toInt());
        bool test;
        test=e1.Supprime(e1.getid());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_aff_2->setModel(e1.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tableView_aff_2->setModel(e.afficher_nom_prenom());
}


void MainWindow::on_pushButton_7_clicked()
{
    QSqlQueryModel model;
       model.setQuery("SELECT * FROM enfant");

        QString html = "<table  border='2'> <thead> <tr> <th>#</th> <th>nom_prenom</th> <th>etat_psycologique</th> <th>talent</th> <th> sexe</th> <th> id</th> <th> Etat</th><th> Nom Maladie </th>  </tr> </thead><tbody > ";


       for (int i = 0; i < model.rowCount(); ++i) {
           /*this->id=id;
          // this-> date_naissance= date_naissance;
           this->nom_prenom=nom_prenom;
           this->etat_psycologique=etat_psycologique;
           this->talent=talent;
           this->sexe=sexe;*/
           QString id = model.record(i).value("id").toString();
                    QString nom_prenom = model.record(i).value("nom_prenom").toString();
                             QString etat_psycologique = model.record(i).value("etat_psycologique").toString();
                              QString talent = model.record(i).value("talent").toString();
                                QString sexe = model.record(i).value("sexe").toString();

           QString name = model.record(i).value("nom_prenom").toString();
html += "<tr > <td>"+id+"</td> <td>"+nom_prenom+"</td> <td>"+etat_psycologique+"</td><td>"+talent+"</td><td>"+sexe+"</td></tr>";
       }
    html+="</tbody></table>";

      QTextDocument document;
      document.setHtml(html);

      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName("Fiche.pdf");

     document.print(&printer);
}





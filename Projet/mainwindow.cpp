#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boutique.h"
#include "vetement.h"
#include<iostream>
#include <QtMultimedia/QSound>
#include <QPixmap>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QLineEdit>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Yacin/Desktop/Projet/a.jpg");
        int w=ui->label_p->width();
        int h=ui->label_p->height();
        ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

        /*QSound newMessage("C:/Users/Yacin/Desktop/Projet/Drake.wav");
           newMessage.play();*/



                        /*ref&taille&prix pattern*/
    ui->ref->setValidator(new QIntValidator(0,9999,this));
    QRegularExpression rx2("\\b[0-9]{6}\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->prix->setValidator(new QRegularExpressionValidator(rx2, this));
    QRegularExpression rx3("\\b[A-Z0-9]{1,5}\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->taille->setValidator(new QRegularExpressionValidator(rx3, this));
                             /*maxlenght*/
                    ui->saison->setMaxLength(15);
                    ui->genre->setMaxLength(12);
                    ui->type->setMaxLength(25);
                    ui->marque->setMaxLength(50);

                    /*placeholder*/
     ui->ref->setPlaceholderText("Reference");
     ui->saison->setPlaceholderText("Saison");
     ui->genre->setPlaceholderText("Genre");
     ui->type->setPlaceholderText("Type de Vetement");
     ui->taille->setPlaceholderText("Taille");
     ui->marque->setPlaceholderText("Marque");
     ui->prix->setPlaceholderText("Prix");
     ui->nomsuppv->setPlaceholderText("Ref :");
     ui->refmodif->setPlaceholderText("Ref :");
     ui->findv->setPlaceholderText("Chercher celon :");


                     /*tel&id pattern*/
    ui->id->setValidator(new QIntValidator(0,999,this)); 
    QRegularExpression rx1("\\b[0-9]{8}\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->tel->setValidator(new QRegularExpressionValidator(rx1, this));


                    /*email pattern*/
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z.-]+\\.[A-Z]{2,4}\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->mail->setValidator(new QRegularExpressionValidator(rx, this));
                      /*maxlenght*/
               ui->nom->setMaxLength(20);
               ui->adr->setMaxLength(50);
               ui->mail->setMaxLength(50);
                  /*placeholder*/
   ui->id->setPlaceholderText("Id Boutique");
   ui->nom->setPlaceholderText("Nom Complet");
   ui->adr->setPlaceholderText("Adresse Local");
   ui->tel->setPlaceholderText("N° Telephone");
   ui->mail->setPlaceholderText("Contact@mail.com");
   ui->nomsupp->setPlaceholderText("Id :");
   ui->idmodif->setPlaceholderText("Id :");
   ui->mailing->setPlaceholderText("Mettre Votre E-mail içi :");




}

MainWindow::~MainWindow()
{
    delete ui;


}


/******************************************* tableau boutique ******************************************************/
                                     /*CRUD*/
void MainWindow::on_ajoutb_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString adr=ui->adr->text();
    QString mail=ui->mail->text();
    int tel=ui->tel->text().toInt();
    boutique B(id,nom,adr,mail,tel);
    bool test=B.ajouter();

  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("Boutique est ajoutée"),
                                 QObject::tr("Ajout Terminer.\n"
                                             "Cliquer Ok pour Continuer."), QMessageBox::Ok);
      ui->afficheb->setModel(B.afficher());
      {  /*clear after ajouter*/
           ui->id->clear();
           ui->nom->clear();
           ui->adr->clear();
           ui->tel->clear();
           ui->mail->clear();}

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Boutique N'est pas Ajoutée"),
                                 QObject::tr("Echec D'Ajout.\n"
                                             "Cliquer Retry Pour Ajouter à Nouveau "), QMessageBox::Retry);


}




void MainWindow::on_annulerb_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->adr->clear();
    ui->tel->clear();
    ui->mail->clear();
}



void MainWindow::on_suppb_clicked()
{
    boutique B1;
    B1.setid(ui->nomsupp->text().toInt());
    bool test;
    test=B1.supprimer(B1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("Suppression effectué "),
                                   QObject::tr("Boutique a été Supprimée .\n"
                                               "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->afficheb->setModel(B1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression Echoué"),
                                   QObject::tr("Boutique n'a pas été  Supprimée .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);

}

void MainWindow::on_reset_clicked()
{
        bool test1;
        test1=B.reset();
        if(test1)
         {    QMessageBox::information(nullptr, QObject::tr("toutes les boutiques ont été  Supprimées"),
                                       QObject::tr("Liste est Vide.\n"
                                                    "Cliquer OK Pour Verifier."), QMessageBox::Ok);
    ui->afficheb->setModel(B.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("Suppression echoué"),
                                       QObject::tr("Liste n'est pas vide .\n"
                                                   "Cliquer OK Pour Continuer."), QMessageBox::Ok);

}

void MainWindow::on_actualiserb_clicked()
{
    ui->afficheb->setModel(B.afficher());
}

void MainWindow::on_modifierb_clicked()
{
          int id=ui->idmodif->text().toInt();
          QString nom=ui->nom->text();
          QString adr=ui->adr->text();
          int tel=ui->tel->text().toInt();
          QString mail=ui->mail->text();


              boutique a(id,nom,adr,mail,tel);
              bool test=a.modifier(id);
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                         QObject::tr("modify successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
              ui->afficheb->setModel(a.afficher());

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                         QObject::tr("modify failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

}
                                                /*metiers*/

/******************************************* tableau vetement ******************************************************/
                                              /*CRUD*/
void MainWindow::on_ajouterv_clicked()
{
    int ref=ui->ref->text().toInt();
    QString saison=ui->saison->text();
    QString genre=ui->genre->text();
    QString type=ui->type->text();
    QString taille=ui->taille->text();
    QString marque=ui->marque->text();
    float prix=ui->prix->text().toInt();
    vetement V(ref,saison,genre,type,taille,marque,prix);
    bool test=V.ajouter();

  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("vetement est ajoutée"),
                                 QObject::tr("Ajout Terminer.\n"
                                             "Cliquer Ok pour Continuer."), QMessageBox::Ok);
      ui->affichev->setModel(V.afficher());
      {  /*clear after ajouter*/
          ui->ref->clear();
          ui->saison->clear();
          ui->genre->clear();
          ui->type->clear();
          ui->taille->clear();
          ui->marque->clear();
          ui->prix->clear();}

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Boutique N'est pas Ajoutée"),
                                 QObject::tr("Echec D'Ajout.\n"
                                             "Cliquer Retry Pour Ajouter à Nouveau "), QMessageBox::Retry);
}


void MainWindow::on_annulerv_clicked()
{
    ui->ref->clear();
    ui->saison->clear();
    ui->genre->clear();
    ui->type->clear();
    ui->taille->clear();
    ui->marque->clear();
    ui->prix->clear();
}
void MainWindow::on_suppv_clicked()
{
    vetement V1;
    V1.setref(ui->nomsuppv->text().toInt());
    bool test;
    test=V1.supprimer(V1.getref());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("Suppression effectué "),
                                   QObject::tr("Boutique a été Supprimée .\n"
                                               "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->affichev->setModel(V1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression Echoué"),
                                   QObject::tr("Boutique n'a pas été  Supprimée .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);
}


void MainWindow::on_resetv_clicked()
{
    bool test1;
    test1=V.reset();
    if(test1)
     {    QMessageBox::information(nullptr, QObject::tr("toutes les boutiques ont été  Supprimées"),
                                   QObject::tr("Liste est Vide.\n"
                                                "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->affichev->setModel(V.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression echoué"),
                                   QObject::tr("Liste n'est pas vide .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);
}

void MainWindow::on_actualiserv_clicked()
{
    ui->affichev->setModel(V.afficher());
}

                                       /*metiers*/

void MainWindow::on_triref_clicked()
{
    ui->affichev->setModel(V.afficher_ref());
}

void MainWindow::on_triprix_clicked()
{
    ui->affichev->setModel(V.afficher_prix());

}

void MainWindow::on_findv_textChanged(const QString &arg1 )
{
    QSqlQueryModel *model= new QSqlQueryModel();
       QSqlQuery   *query= new QSqlQuery();
       query->prepare("SELECT * FROM vetement WHERE ref  LIKE'"+arg1+"%' or prix  LIKE'"+arg1+"%' or marque  LIKE'"+arg1+"%' or type LIKE'"+arg1+"%' ");
        query->exec();
        if (query->next()) {
        model->setQuery(*query);
        ui->affichev->setModel(model);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                            QObject::tr("NO MATCH FOUND !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->findv->clear();}
}



void MainWindow::on_modifierv_clicked()
{
    int ref=ui->refmodif->text().toInt();
    QString saison=ui->saison->text();
    QString genre=ui->genre->text();
    QString type=ui->type->text();
    QString taille=ui->taille->text();
    QString marque=ui->marque->text();
    float prix=ui->prix->text().toFloat();



        vetement e(ref,saison,genre,type,taille,marque,prix);
        bool test=e.modifier(ref);
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                   QObject::tr("modify successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->affichev->setModel(e.afficher());

               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                   QObject::tr("modify failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}



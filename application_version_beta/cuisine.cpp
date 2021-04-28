#include "cuisine.h"
#include "ui_cuisine.h"
#include <QPixmap>
#include "menu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>
#include <QDataStream>
#include <QTextDocument>
#include "ingredient.h"
#include "ingr.h"
#include <QFile>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QRegularExpressionValidator>
#include <QPainter>

#include <QMessageBox>
cuisine::cuisine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuisine)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/cui.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
            QPixmap pix1("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/cui.jpg");
            int w1=ui->label_8->width();
            int h1=ui->label_8->height();
            ui->label_8->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
            QPixmap pix2("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/cui.jpg");
            int w2=ui->label_ph_2->width();
            int h2=ui->label_ph_2->height();
            ui->label_ph_2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
            ui->tableView_ingr_activated->setModel(i.afficher());
            ui->tableView_repas->setModel(r.afficher());
}

cuisine::~cuisine()
{
    delete ui;
}

void cuisine::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void cuisine::on_pushButton_Q_clicked()
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

void cuisine::on_pushButton_ajouter_5_clicked()
{
    if(ui->lineEdit_nom->text().isEmpty()||ui->lineEdit_type->text().isEmpty()||ui->lineEdit_heure->text().isEmpty()|| ui->lineEdit_categorie->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
        QObject::tr("Information incomplete.\n""Click Cancel to exit."), QMessageBox::Cancel);
}else{
        int count=0;
         QSqlQuery query;
         query.prepare("SELECT * FROM  INGREDIENT where NOM_R = :NOM ");

         query.bindValue(":NOM", ui->lineEdit_nom->text() );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {

                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                 QObject::tr(" NOM de repas existe deja !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             if(count==0)

             {
                 int count2=0 ;
                  QSqlQuery query2 ;
                  query2.prepare("SELECT * FROM  INGREDIENT where TYPE_R = :TYPE ");

                  query2.bindValue(":TYPE", ui->lineEdit_type->text());
                 query2.exec();
                  while(query2.next())

                  {

                      count2++;

                  }

                  if(count2!=0)

                  {

                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr(" le type de repas exsite deja !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                  if(count2==0 )

                  {

                 QString nom=ui->lineEdit_nom->text() ;
                 QString type=ui->lineEdit_type->text() ;
                 QString heure=ui->lineEdit_heure->text() ;
                 QString categorie=ui->lineEdit_categorie->text() ;





                 Ingredient i(nom,type,heure,categorie);





                  if(i.ajouter()) {
                      QMessageBox::information(nullptr, QObject::tr("OK "),
                      QObject::tr("repas ajouter avec succes ok.\n""Click Cancel to exit."), QMessageBox::Cancel);
                     // ui->adm_tab_aff->setModel(e.afficher());
                  }
                  else {
                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Probleme de connexion.\n""Click Cancel to exit."), QMessageBox::Cancel);

                  }


             }

             }


         }




     }
}

void cuisine::on_pushButton_quitter_clicked()
{
    if(ui->lineEdit_nom_suppr->text().isEmpty()) {

        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Information incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {



            QSqlQuery query;


        int count =0;

            query.prepare("SELECT * FROM  INGREDIENT where NOM_R = :NOM_R ");

            query.bindValue(":NOM_R", ui->lineEdit_nom_suppr->text());

            if(query.exec())

            {


                while(query.next())

                {

                    count++;

                }

                if(count!=0)

                {

                      Ingredient i ;
                     QString NOM=ui->lineEdit_nom_suppr->text() ;
                      if(i.supprimer(NOM))  {



                          QMessageBox::information(nullptr, QObject::tr(" OK"),
                          QObject::tr("REPAS supprimer avec succes !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                      ui->tableView_repas->setModel(i.afficher());
                      }
                      else {
                          QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                          QObject::tr("Probleme de conixion !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);


                      }

                }

                if(count==0 )

                {

                    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("NOM NOT FOUND !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }



            }



 }
}

void cuisine::on_pushButton_afficher_clicked()
{
    Ingredient i;
    ui->tableView_repas->setModel(i.afficher());
}


void cuisine::on_pushButton_suppr_clicked()
{
    if (ui->lineEdit_nom_suppr->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr(" LE Nom EST VIDE !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{


            int count=0 ;
             QSqlQuery query ;
             query.prepare("SELECT * FROM INGREDIENT where NOM_R = :NOM_R ");

             query.bindValue(":NOM_R", ui->lineEdit_nom_suppr->text() );

             if(query.exec())

             {


                 while(query.next())

                 {

                     count++;

                 }

                 if(count!=0)

                 {
                     Ingredient i ;
                  QString NOM_R=ui->lineEdit_nom_suppr->text() ;
                 if(  i.supprimer(NOM_R))  {
                     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Agence supprimer avec succes !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                                ui->tableView_repas->setModel(i.afficher());
                 }
                 else {
                                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("probleme de connexion !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 }

                 }

                 if (count == 0 )

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("NOM nexiste pas !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
                 }


                 }

        }
}

void cuisine::on_pushButton_modifier_i_clicked()
{
    if (ui->lineEdit_nom->text().isEmpty()||ui->lineEdit_type->text().isEmpty()||ui->lineEdit_heure->text().isEmpty()||ui->lineEdit_categorie->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr(" Inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

    query.prepare("UPDATE  INGREDIENT SET  NOM_R=:NOM_R, TYPE_R=:TYPE_R,HEURE_R=:HEURE_R,CATEGORIE_R=:CATEGORIE_R WHERE NOM_R=:NOM_R");
    query.bindValue(":NOM_R",ui->lineEdit_nom->text()) ;
    query.bindValue(":TYPE_R", ui->lineEdit_type->text());
    query.bindValue(":HEURE_R", ui->lineEdit_heure->text());
    query.bindValue(":CATEGORIE_R",ui->lineEdit_categorie->text());


    if(query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr(" Agence modifier avec succes !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        Ingredient i ;
        ui->tableView_repas->setModel(i.afficher());
 }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Probleme de conixion !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    }
}

void cuisine::on_tableView_repas_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_repas->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from INGREDIENT where NOM_R='"+val+"' or TYPE_R='"+val+"' or HEURE_R='"+val+"'or CATEGORIE_R ='"+val+"' ");
    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_nom->setText(qry.value(0).toString());
           ui->lineEdit_type->setText(qry.value(1).toString());
           ui->lineEdit_heure->setText(qry.value(2).toString());
           ui->lineEdit_categorie->setText(qry.value(3).toString());
       }
    }else{
           QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }

}

void cuisine::on_pushButton_trier_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_R"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_R "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_R"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CATEGORIE_R"));
    ui->tableView_repas->setModel(model);
    QSqlQuery query;

     if (ui->comboBox->currentText()=="CATEGORIE_REPAS")
     query.prepare("SELECT *  FROM INGREDIENT ORDER BY CATEGORIE_R ASC ") ;
else
         if (ui->comboBox->currentText()==" TYPE REPAS")
         query.prepare("SELECT *  FROM INGREDIENT ORDER BY TYPE_R ASC ") ;
  else
             if (ui->comboBox->currentText()=="HEURE_REPAS")
             query.prepare("SELECT *  FROM INGREDIENT ORDER BY HEURE_R ASC ") ;



    if (query.exec()&&query.next()) {
        model->setQuery(query);

        ui->tableView_repas->setModel(model);
}

}

void cuisine::on_pushButton_rechercher_clicked()
{
    Ingredient i;
         ui->tableView_repas->setModel(i.recherche(ui->lineEdit_nom_I->text(),ui->lineEdit_type_I->text(),ui->lineEdit_categorie_I->text()));
         ui->lineEdit_nom_I->clear();
            ui->lineEdit_type_I->clear();
            ui->lineEdit_categorie_I->clear();
}







void cuisine::on_pushButton_ajouter_clicked()
{
    if(ui->lineEdit_nom->text().isEmpty()||ui->lineEdit_type->text().isEmpty()||ui->lineEdit_heure->text().isEmpty()|| ui->lineEdit_categorie->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
        QObject::tr("Information incomplete.\n""Click Cancel to exit."), QMessageBox::Cancel);
}else{
        int count=0;
         QSqlQuery query;
         query.prepare("SELECT * FROM  INGREDIENT where NOM_R = :NOM ");

         query.bindValue(":NOM", ui->lineEdit_nom->text() );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {

                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                 QObject::tr(" NOM de repas existe deja !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             if(count==0)

             {
                 int count2=0 ;
                  QSqlQuery query2 ;
                  query2.prepare("SELECT * FROM  INGREDIENT where TYPE_R = :TYPE ");

                  query2.bindValue(":TYPE", ui->lineEdit_type->text());
                 query2.exec();
                  while(query2.next())

                  {

                      count2++;

                  }

                  if(count2!=0)

                  {

                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr(" le type de repas exsite deja !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                  if(count2==0 )

                  {

                 QString nom=ui->lineEdit_nom->text() ;
                 QString type=ui->lineEdit_type->text() ;
                 QString heure=ui->lineEdit_heure->text() ;
                 QString categorie=ui->lineEdit_categorie->text() ;





                 Ingredient i(nom,type,heure,categorie);





                  if(i.ajouter()) {
                      QMessageBox::information(nullptr, QObject::tr("OK "),
                      QObject::tr("repas ajouter avec succes ok.\n""Click Cancel to exit."), QMessageBox::Cancel);
                     // ui->adm_tab_aff->setModel(e.afficher());
                  }
                  else {
                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Probleme de connexion.\n""Click Cancel to exit."), QMessageBox::Cancel);

                  }


             }

             }


         }




     }
}





void cuisine::on_ajouteringr_clicked()
{
    if (ui->lineEdit_nom_ingr->text().isEmpty()|| ui->lineEdit_valeur_ingr->text().isEmpty()||ui->lineEdit_type_ingr->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
        QObject::tr("Information incomplete.\n""Click Cancel to exit."), QMessageBox::Cancel);
}else{
        int count=0;
         QSqlQuery query;
         query.prepare("SELECT * FROM  INGR  where NOMING = :NOMING");

         query.bindValue(":NOMING", ui->lineEdit_nom_ingr->text() );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {

                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                 QObject::tr("le nom de l'ingredient  existe deja !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             if(count==0)

             {
                 int count2=0 ;
                  QSqlQuery query2 ;
                  query2.prepare("SELECT * FROM  INGR where TYPE = :TYPE ");

                  query2.bindValue(":TYPE", ui->lineEdit_type_ingr->text());
                 query2.exec();
                  while(query2.next())

                  {

                      count2++;

                  }

                  if(count2!=0)

                  {

                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr(" le type de ingredient existe deja !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                  if(count2==0 )

                  {

                 QString noming=ui->lineEdit_nom_ingr->text() ;
               //  QString duree_consommation= ui->lineEdit_duree_ingr->text();
                 QString type=ui->lineEdit_type_ingr->text();
                // QString prix=ui->lineEdit_prix_ingr->text() ;
                 QString valeur_alimentaire=ui->lineEdit_valeur_ingr->text();





                 ingr i(noming,type,valeur_alimentaire);





                  if(i.ajouter()) {
                      QMessageBox::information(nullptr, QObject::tr("OK "),
                      QObject::tr("ingredient ajouter avec succes ok.\n""Click Cancel to exit."), QMessageBox::Cancel);
                      ui->tableView_ingr_activated->setModel(i.afficher());
                  }
                  else {
                      QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Probleme de connexion.\n""Click Cancel to exit."), QMessageBox::Cancel);

                  }


             }

             }


         }




     }
}

void cuisine::on_pushButton_modieri_clicked()
{

    if  (ui->lineEdit_nom_ingr->text().isEmpty()|| ui->lineEdit_valeur_ingr->text().isEmpty()||ui->lineEdit_type_ingr->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr(" Inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

    query.prepare("UPDATE  INGR SET  NOMING=:NOMING, TYPE=:TYPE ,DUREE_CONSOMMATION:=DUREE_CONSOMMATION WHERE NOMING=:NOMING");
    query.bindValue(":NOMING",ui->lineEdit_nom_ingr->text()) ;
  //  query.bindValue(":DUREE_CONSOMMATION", ui->lineEdit_type_ingr->text());
    query.bindValue(":TYPE", ui->lineEdit_type_ingr->text());
   // query.bindValue(":PRIX",ui->lineEdit_prix_ingr->text());
    query.bindValue(":VALEUR_ALIMENTAIRE",ui->lineEdit_valeur_ingr->text());
    if(query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr(" ingrdeint on modifier avec succes !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ingr i  ;
        ui->tableView_ingr_activated->setModel(i.afficher());
 }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Probleme de connexion !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    }
}

void cuisine::on_tableView_ingr_activated_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_ingr_activated->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from INGR where NOMING='"+val+"' or TYPE='"+val+"' or  VALEUR_ALIMENTAIRE ='"+val+"'");
    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_nom_ingr->setText(qry.value(0).toString());
         //  ui->lineEdit_duree_ingr->setText(qry.value(1).toString());
           ui->lineEdit_type_ingr->setText(qry.value(1).toString());
         //  ui->lineEdit_prix_ingr->setText(qry.value(3).toString());
           ui->lineEdit_valeur_ingr->setText(qry.value(2).toString());
       }
    }else{
           QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }
}

void cuisine::on_modif_ing_clicked()
{
    if  (ui->lineEdit_nom_ingr->text().isEmpty()|| ui->lineEdit_valeur_ingr->text().isEmpty()||ui->lineEdit_type_ingr->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr(" Inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

    query.prepare("UPDATE  INGR SET  NOMING=:NOMING, TYPE=:TYPE ,VALEUR_ALIMENTAIRE=:VALEUR_ALIMENTAIRE WHERE NOMING=:NOMING");
    query.bindValue(":NOMING",ui->lineEdit_nom_ingr->text()) ;
  //  query.bindValue(":DUREE_CONSOMMATION", ui->lineEdit_type_ingr->text());
    query.bindValue(":TYPE", ui->lineEdit_type_ingr->text());
   // query.bindValue(":PRIX",ui->lineEdit_prix_ingr->text());
    query.bindValue(":VALEUR_ALIMENTAIRE",ui->lineEdit_valeur_ingr->text());
    if(query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr(" ingrdeint on modifier avec succes !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ingr i  ;
        ui->tableView_ingr_activated->setModel(i.afficher());
 }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Probleme de connexion !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    }
}

void cuisine::on_pushButton_afficher_ngr_clicked()
{
    ingr i;
    ui->tableView_ingr_activated->setModel(i.afficher());

}

void cuisine::on_pushButton_suprimer_ingr_clicked()
{
    if (ui->lineEdit_ingr_suppr->text().isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr(" LE Nom EST VIDE !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{


            int count=0 ;
             QSqlQuery query ;
             query.prepare("SELECT * FROM INGR where NOMING = :NOMING ");

             query.bindValue(":NOMING", ui->lineEdit_ingr_suppr->text());

             if (query.exec())

             {


                 while(query.next())

                 {

                     count++;

                 }

                 if(count!=0)

                 {
                     ingr i;
                  QString NOMING=ui->lineEdit_ingr_suppr->text() ;
                 if( i.supprimer(NOMING))  {
                     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppimer avec succes !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                                ui->tableView_ingr_activated->setModel(i.afficher());
                 }
                 else{
                                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("probleme de connexion !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 }

                 }

                 if (count == 0 )

                 {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("NOMING n'existe pas !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
                 }


                 }

        }
}

void cuisine::on_pushButton_recherche_ingr_clicked()
{
    ingr i;
    ui->tableView_ingr_activated->setModel(i.recherche(ui->lineEdit_rech_ingr->text(),ui->lineEdit_type_ingr_2->text(),ui->lineEdit_val_ingr->text()));
    ui->lineEdit_rech_ingr->clear();
    ui->lineEdit_type_ingr_2->clear();
    ui->lineEdit_valeur_ingr->clear();

}

void cuisine::on_pushButton_trier_ingr_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMING"));
   // model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE_CONSOMMATION "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
   // model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("VALEUR_ALIMENTAIRE"));
    ui->tableView_ingr_activated->setModel(model);
    QSqlQuery query;


    if (ui->comboBox_2->currentText()=="NOMING")
    query.prepare("SELECT *  FROM INGR ORDER BY NOMING ASC ") ;
else
        if (ui->comboBox_2->currentText()=="TYPE")
        query.prepare("SELECT *  FROM INGR ORDER BY TYPE ASC ") ;
 else
            if (ui->comboBox_2->currentText()=="VALEUR _ALIMENTAIRE")
            query.prepare("SELECT *  FROM INGR ORDER BY VALEUR_ALIMENTAIRE ASC ");


    if (query.exec()&&query.next()) {
        model->setQuery(query);

        ui->tableView_ingr_activated->setModel(model);
}
}

void cuisine::on_imprim_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableView_ingr_activated->model()->rowCount();
                const int columnCount = ui->tableView_ingr_activated->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableView_ingr_activated->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_ingr_activated->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView_ingr_activated->isColumnHidden(column)) {
                            QString data = ui->tableView_ingr_activated->model()->data(ui->tableView_ingr_activated->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}

void cuisine::on_pushButton_2_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_repas->model()->rowCount();
                     const int columnCount = ui->tableView_repas->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_repas->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_repas->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_repas->isColumnHidden(column)) {
                                 QString data = ui->tableView_repas->model()->data(ui->tableView_repas->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);

printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);

                 doc.print(&printer);



}

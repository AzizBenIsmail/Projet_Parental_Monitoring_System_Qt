#include "sante.h"
#include "ui_sante.h"
#include "menu.h"
#include <QPixmap>
#include "QMessageBox"
#include"suivi.h"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <medicament.h>
Sante::Sante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sante)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(e.afficher());
    ui->tableView_aff_m->setModel(m.afficher());
    ui->_id->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_idS->setValidator(new QIntValidator(0,9999999,this));

    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/s.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    int a=ui->label_ph_2->width();
    int b=ui->label_ph_2->height();
    ui->label_ph_2->setPixmap(pix.scaled(a,b,Qt::KeepAspectRatio));
    int aa=ui->label_ph3->width();
    int bb=ui->label_ph3->height();
    ui->label_ph3->setPixmap(pix.scaled(aa,bb,Qt::KeepAspectRatio));
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
            double taille=ui->_taille->text().toDouble();
            double poid=ui->_poid->text().toDouble();
           double tension=ui->_tenstion->text().toDouble();
            QString date=ui->_date->text();

            if (id <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem id"),
                            QObject::tr("verifier id\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (taille <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                            QObject::tr("verifier taille\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
           else  if (poid <= 0  )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                            QObject::tr("verifier poid\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (tension <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem tension"),
                            QObject::tr("verifier tension\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (date== ""  )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem date"),
                            QObject::tr("verifier date\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
            {
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


}

void Sante::on_pushButton_ajout_m_clicked()
{
    int id=ui->_id_m->text().toInt();
        double Quantite=ui->_Quantite->text().toDouble();
        double Prix=ui->Prix->text().toDouble();
        QString date=ui->_date_m->text();
        if (id <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem id"),
                        QObject::tr("verifier id\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (Quantite < 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem age"),
                        QObject::tr("verifier age\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       else  if (Prix < 0  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem prix"),
                        QObject::tr("verifier prix\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (date==""  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                        QObject::tr("verifier nom\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            MEDICAMENT m(id,Quantite,Prix,date);
            bool test=m.Ajouter();
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                         QObject::tr("ajout successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_aff_m->setModel(m.afficher());

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                         QObject::tr("ajout failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void Sante::on_pushButton_Sui_m_clicked()
{
    MEDICAMENT m1;
    m1.setid(ui->lineEdit_idS_m->text().toInt());
    bool test;
    test=m1.Supprime(m1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_m->setModel(m1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup error"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_Modifier_clicked()
{
    int id=ui->_id->text().toInt();
        double taille=ui->_taille->text().toDouble();
        double poid=ui->_poid->text().toDouble();
       double tension=ui->_tenstion->text().toDouble();
        QString date=ui->_date->text();
        if (id <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem id"),
                        QObject::tr("verifier id\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (taille <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                        QObject::tr("verifier taille\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       else  if (poid <= 0  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                        QObject::tr("verifier poid\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (tension <= 0 )
        {
            QMessageBox::information(nullptr, QObject::tr("problem tension"),
                        QObject::tr("verifier tension\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (date== ""  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem date"),
                        QObject::tr("verifier date\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
        suivi m(id,taille,poid,tension,date);
        bool test=m.modifier(id,date);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff->setModel(m.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
      }
}
void Sante::on_Tri_IdE_clicked()
{
    ui->tableView_aff->setModel(e.afficher_id());
}

void Sante::on_Tri_Taille_clicked()
{
    ui->tableView_aff->setModel(e.afficher_taille());
}

void Sante::on_Tri_Poid_clicked()
{
    ui->tableView_aff->setModel(e.afficher_poid());

}


void Sante::on_pushButton_2_clicked()
{
    ui->tableView_aff->setModel(e.test());

}


void Sante::on_pushB_clicked()
{
    bool t;
    t=e.reset();
    if(t)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(e.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_pushB_2_clicked()
{    MEDICAMENT m1;

    bool t1;
    t1=m1.reset();
    if(t1)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_m->setModel(m1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_Tri_IdE_2_clicked()
{
    ui->tableView_aff_m->setModel(m.afficher_prix());
}

void Sante::on_Tri_Taille_2_clicked()
{
    ui->tableView_aff_m->setModel(m.afficher_qt());
}
void Sante::on_pushm_clicked()
{
    int id=ui->_id_m->text().toInt();
        double Quantite=ui->_Quantite->text().toDouble();
        double Prix=ui->Prix->text().toDouble();
        QString date=ui->_date_m->text();
         if (id <= 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem id"),
                         QObject::tr("verifier id\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else if (Quantite < 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem Quantite"),
                         QObject::tr("verifier taille\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
        else  if (Prix < 0  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem Prix"),
                         QObject::tr("verifier poid\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else if (date== ""  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem date"),
                         QObject::tr("verifier date\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         {
          MEDICAMENT m1(id,Quantite,Prix,date);
          bool test=m1.modifier(id,date);

         if(test)
          {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                        QObject::tr("modify successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_m->setModel(m.afficher());

                    }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                        QObject::tr("modify failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void Sante::on_pushButton_3_clicked()
{
       ui->tableView_aff_m->setModel(m.recherche_faible());

}

void Sante::on_pushButton_Moyenne_clicked()
{
    ui->tableView_aff_m->setModel(m.recherche_moye());
}


void Sante::on_pushButton_chere_clicked()
{
    ui->tableView_aff_m->setModel(m.recherche_chere());

}
/*
void Sante::on_pushButton_Recherche_clicked()
{       int id=ui->_id_m->text().toInt();
    ui->tableView_aff_m->setModel(m.recherche(id));
}
*/

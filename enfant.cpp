#include "enfant.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include<QDate>
#include <QMessageBox>
 enfant::enfant()
{
id=0;
}
enfant::enfant(int id,QString nom_prenom,QString etat_psycologique,QString talent,QString sexe)
{
    this->id=id;
   // this-> date_naissance= date_naissance;
    this->nom_prenom=nom_prenom;
    this->etat_psycologique=etat_psycologique;
    this->talent=talent;
    this->sexe=sexe;

}
int enfant::getid()
{
    return id;
}
QString enfant:: getnom_prenom()
{
    return nom_prenom;
}

QString enfant:: getetat_psycologique()
{
    return etat_psycologique;
}
QString enfant:: gettalent()
{
    return talent;
}
QString enfant:: getsexe()
{
    return sexe;
}


void enfant::setid(int id)
{
    this->id=id;
}
void enfant::setnom_prenom(QString nom_prenom)
{
    this->nom_prenom=nom_prenom;
}
/*void Enfant::setdate_naissance(QDate date_naissance)
{
    this->date_naissance=date_naissance;

}*/

void enfant::setetat_psycologique(QString etat_psycologique)
{
    this->etat_psycologique=etat_psycologique;

}
void enfant::settalent(QString talent)
{
    this->talent=talent;

}
void enfant::setsexe(QString sexe)
{
    this->sexe=sexe;

}








 bool enfant::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);
     //QString nom_prenom_string=QString::QString(nom_prenom);

          query.prepare("INSERT INTO enfant (id,nom_prenom,etat_psycologique,talent ,sexe) "
                        "VALUES (:id,:nom_prenom,:etat_psycologique,:talent,:sexe)");
          query.bindValue(":id",id_string);
          query.bindValue(":nom_prenom",nom_prenom);
         // query.bindValue(":date_naissance", date_naissance);
          query.bindValue(":etat_psycologique",etat_psycologique);
          query.bindValue(":talent", talent);
          query.bindValue(":sexe",sexe);

       return query.exec();

 }
 QSqlQueryModel *enfant::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM enfant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
        // model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat_psycologique"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("talent"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
         return model;
 }
  QSqlQueryModel* afficher_id()
{
      QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM enfant ORDER BY id");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
           // model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat_psycologique"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("talent"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
            return model;
  }

  QSqlQueryModel *enfant::afficher_nom_prenom()
  {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM enfant ORDER BY nom_prenom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
   // model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat_psycologique"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("talent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
    return model;
  }



  /*QSqlQueryModel* Enfant::rechercher(int id)
  {
    QSqlQueryModel* model=new QSqlQueryModel();
  QSqlQuery query;

     // QString id_string=id_string::number(id);
        QString id_string=QString::number(id);
      query.bindValue(":id",id_string);

  model->setQuery("SELECT * FROM enfant WHERE id=:id;");

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom"));
 // model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_naissance"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat_psycologique"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("talent"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
  query.exec();
    return  model;
   }*/

bool enfant::Supprime(int id)
{
    QSqlQuery query;
         query.prepare("delete from enfant where id=:id");
         query.bindValue(0, id);
      return query.exec();
}


bool enfant::modifier(int id)
{

QSqlQuery query;


QString id_string=QString::number(id);
//QString nom_prenom_string=QString::QString(nom_prenom);
//QString etat_psycologique_string=QString::QString(etat_psycologique);
//QString talent_string=QString::QString(talent);
//QString sexe_string=QString::QString(sexe);

query.prepare("UPDATE Enfant SET nom_prenom=:nom_prenom,etat_psycologique=:etat_psycologique,talent=:talent,sexe=:sexe WHERE id=:id;");

query.bindValue(":id",id);
     query.bindValue(":nom_prenom",nom_prenom);
     query.bindValue(":etat_psycologique",etat_psycologique);
     query.bindValue(":talent",talent);
     query.bindValue(":sexe", sexe );
return    query.exec();
}
/*void MainWindow::on_txt_recherche_animal_textChanged(const QString &arg1)
{
   Animal c(1,1,1,"","","","");
        c.cleartable(ui->tableView);
        QString cas =ui->txt_recherche_animal->text();
        c.rechercher(ui->tableView,cas);

        if(ui->txt_recherche_animal->text().isEmpty())
        {
            ui->tableView->setModel(c.afficher());
        }
}*/


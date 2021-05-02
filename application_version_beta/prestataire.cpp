#include "prestataire.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QTableView>
prestataire::prestataire()
{
    idpres=0;
    salairepres=0;
    nbr_heurespres=0;
}

prestataire::prestataire(int idpres,QString nompres,QString prenompres,int salairepres,QString specialitepres,QString dateembauchepres,int nbr_heurespres,int telpres,QString adressepres,QString sexepres)
{

    this->idpres=idpres;
    this->nompres=nompres;
    this->prenompres=prenompres;
    this->salairepres=salairepres;
    this->specialitepres=specialitepres;
    this->dateembauchepres=dateembauchepres;
    this->nbr_heurespres=nbr_heurespres;
    this->telpres=telpres;
     this->adressepres=adressepres;
      this->sexepres=sexepres;
}
int prestataire::getidpres()
{
    return idpres;
}
QString prestataire:: getnompres()
{
    return nompres;
}

QString prestataire:: getprenompres()
{
    return prenompres;
}
int prestataire:: getsalairepres()
{
    return salairepres;
}
QString prestataire:: getspecialitepres()
{
    return specialitepres;
}
QString prestataire:: getdateembauchepres()
{
    return dateembauchepres;
}
int prestataire:: getnbr_heurespres()
{
    return nbr_heurespres;
}
int prestataire:: gettelpres()
{
    return telpres;
}

QString prestataire:: getsexepres()
{
    return sexepres;
}
QString prestataire:: getadressepres()
{
    return adressepres;
}


void prestataire::setidpres(int idpres)
{
    this->idpres=idpres;
}
void prestataire::setnompres(QString nompres)
{
    this->nompres=nompres;
}

void prestataire::setprenompres(QString prenompres)
{
    this->prenompres=prenompres;

}
void prestataire::setsalairepres(int salairepres)
{
    this->salairepres=salairepres;

}
void prestataire::setspecialitepres(QString specialitepres)
{
    this->specialitepres=specialitepres;

}

void prestataire::setdateembauchepres(QString dateembauchepres)
{
    this->dateembauchepres=dateembauchepres;

}
void prestataire::setnbr_heurespres(int nbr_heurespres)
{
    this->nbr_heurespres=nbr_heurespres;

}
void prestataire::settelpres(int telpres)
{
    this->telpres=telpres;

}
void prestataire::setsexepres(QString sexepres)
{
    this->sexepres=sexepres;

}
void prestataire::setadressepres(QString adressepres)
{
    this->adressepres=adressepres;

}






 bool prestataire::Ajouter_pres()
 {

     QSqlQuery query;
     QString idpres_string=QString::number(idpres);
     QString salairepres_string=QString::number(salairepres);
     QString nbr_heurespres_string=QString::number(nbr_heurespres);
     QString telpres_string=QString::number(telpres);
     query.prepare("INSERT INTO prestataire (idpres,nompres,prenompres,salairepres ,specialitepres,dateembauchepres,nbr_heurespres,telpres,adressepres,sexepres) "
           "VALUES (:idpres,:nompres,:prenompres,:salairepres,:specialitepres,:dateembauchepres,:nbr_heurespres,:telpres,:adressepres,:sexepres)");
          query.bindValue(":idpres",idpres_string);
          query.bindValue(":nompres",nompres);
          query.bindValue(":prenompres", prenompres);
          query.bindValue(":salairepres",salairepres_string);
          query.bindValue(":specialitepres", specialitepres);
          query.bindValue(":dateembauchepres",dateembauchepres);
          query.bindValue(":nbr_heurespres",nbr_heurespres_string);
          query.bindValue(":telpres",telpres_string);
          query.bindValue(":adressepres",adressepres);
          query.bindValue(":sexepres",sexepres);
        return query.exec();

 }
 QSqlQueryModel *prestataire::afficher_pres()
  {
    QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM prestataire");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nompres"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenompres"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("salairepres"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialitepres"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("dateembauchepres"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr_heurespres"));
             model->setHeaderData(7, Qt::Horizontal, QObject::tr("telpres"));
              model->setHeaderData(8, Qt::Horizontal, QObject::tr("adressepres"));
               model->setHeaderData(9, Qt::Horizontal, QObject::tr("sexepres"));
          return model;
 }
  /*QSqlQueryModel* afficher_id()
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

  QSqlQueryModel *PRESTATEUR_SERVICE::afficher_nom_prenom()
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
  }*/


bool prestataire::Supprime_pres(int idpres)
{
    QSqlQuery query;
         query.prepare("delete from prestataire where idpres=:idpres");
         query.bindValue(0, idpres);
      return query.exec();
}


bool prestataire::modifier_pres(int idpres)
{
  QSqlQuery query;
  QString idpres_string=QString::number(idpres);
  QString salairepres_string=QString::number(salairepres);
  QString nbr_heurespres_string=QString::number(nbr_heurespres);
  QString telpres_string=QString::number(telpres);

query.prepare("UPDATE prestataire SET nompres=:nompres,prenompres=:prenompres,salairepres=:salairepres,specialitepres=:specialitepres,dateembauchepres=:dateembauchepres,nbr_heurespres=:nbr_heurespres,telpres=:telpres,adressepres=:adressepres,sexepres=:sexepres WHERE idpres=:idpres;");

query.bindValue(":idpres",idpres_string);
query.bindValue(":nompres",nompres);
query.bindValue(":prenompres", prenompres);
query.bindValue(":salairepres",salairepres_string);
query.bindValue(":specialitepres", specialitepres);
query.bindValue(":dateembauchepres",dateembauchepres);
query.bindValue(":nbr_heurespres",nbr_heurespres_string);
query.bindValue(":telpres",telpres_string);
query.bindValue(":adressepres",adressepres);
query.bindValue(":sexepres",sexepres);
return query.exec();


}
void prestataire ::rechercher(QTableView *table,QString cas )
  {
      QSqlQueryModel *model= new QSqlQueryModel();

      QSqlQuery *query=new QSqlQuery;

      query->prepare("SELECT * FROM prestataire WHERE (nompres LIKE '%"+cas+"%' or prenompres LIKE '%"+cas+"%'or salairepres LIKE '%"+cas+"%'or specialitepres LIKE '%"+cas+"%'or dateembauchepres LIKE '%"+cas+"%'or specialitepres LIKE '%"+cas+"%'or nbr_heurespres LIKE '%"+cas+"%')");

      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
}
int prestataire::total_specialitepres()
{
     QSqlQuery query;
     query.prepare("SELECT COUNT(*) FROM prestataire");

      query.exec();
      int rows = 0;
      while(query.next()) {
          rows = query.value(0).toInt();
      }

      return rows ;
 }
 int prestataire:: total_femme_de_menage()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM prestataire");

 query.exec();
 int rows = 0;
 while(query.next()) {
     rows = query.value(0).toInt();
 }

 return rows ;
}
int prestataire:: total_jardinier()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM prestataire");

 query.exec();
 int rows = 0;
 while(query.next()) {
     rows = query.value(0).toInt();
 }

 return rows ;
}
int prestataire:: total_enseignant()
{
QSqlQuery query;
query.prepare("SELECT COUNT(*) FROM prestataire");

 query.exec();
 int rows = 0;
 while(query.next()) {
     rows = query.value(0).toInt();
 }

 return rows ;
}

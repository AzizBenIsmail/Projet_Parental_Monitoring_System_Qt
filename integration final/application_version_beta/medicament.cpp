#include "medicament.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
MEDICAMENT::MEDICAMENT()
{
    id=0;
    prix=0;
    quantite=0;
    date="00/00/0000";
}
MEDICAMENT::MEDICAMENT(int id,double prix,double quantite,QString date)
{
    this->id=id; this->prix=prix;
    this->quantite=quantite;
    this->date=date;
}
int MEDICAMENT::getid()
{
    return id;
}
double MEDICAMENT:: getprix()
{
    return prix;
}
double MEDICAMENT::getquantite()
{
    return quantite;
}
QString MEDICAMENT::getdate()
{
    return date;
}
void MEDICAMENT::setid(int id)
{
    this->id=id;
}
void MEDICAMENT::setprix(double prix)
{
    this->prix=prix;
}
void MEDICAMENT::setquantite(double quantite)
{
    this->quantite=quantite;

}
void MEDICAMENT::setdate(QString date)
{
    this->date=date;
}

bool MEDICAMENT::Ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString quantite_string=QString::number(quantite);
    QString prix_string=QString::number(prix);
         query.prepare("INSERT INTO MEDICAMENT (id,quantite,Dat,prix) "
                       "VALUES (:id,:quantite,:date,:prix)");
         query.bindValue(":id",id_string);
         query.bindValue(":quantite",quantite_string);
         query.bindValue(":prix", prix_string);
         query.bindValue(":date", date);
      return query.exec();

}
QSqlQueryModel *MEDICAMENT::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM MEDICAMENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        return model;
}
bool MEDICAMENT::Supprime(int id)
{
   QSqlQuery query;
        query.prepare("delete from MEDICAMENT where id=:id");
        query.bindValue(0, id);
     return query.exec();
}
bool MEDICAMENT::reset()
{
    QSqlQuery query;
         query.prepare("delete from MEDICAMENT");
         query.bindValue(0, id);
      return query.exec();
}
QSqlQueryModel *MEDICAMENT::afficher_qt()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM MEDICAMENT ORDER BY quantite");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        return model;
}
QSqlQueryModel *MEDICAMENT::afficher_prix()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM MEDICAMENT ORDER BY prix");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        return model;
}
QSqlQueryModel* MEDICAMENT::recherche_faible()
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT * FROM MEDICAMENT WHERE (prix BETWEEN '0' AND '15')");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix_Faible"));

query.exec();
  return  model;




}
QSqlQueryModel* MEDICAMENT::recherche_moye()
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT * FROM MEDICAMENT WHERE (prix BETWEEN '15' AND '35')");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix_moyenne"));

query.exec();
  return  model;




}

QSqlQueryModel* MEDICAMENT::recherche_chere()
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

 model->setQuery("SELECT * FROM MEDICAMENT WHERE (prix BETWEEN '35' AND '99999')");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix_chere"));

query.exec();
  return  model;




}
bool MEDICAMENT::modifier(int id,QString date)
{

QSqlQuery query;

QString id_string=QString::number(id);
QString a=QString::number(quantite);
QString b=QString::number(prix);

query.prepare("UPDATE MEDICAMENT SET quantite=:forename,prix=:surname,dat=:date WHERE id=:id;");

query.bindValue(":id",id);
     query.bindValue(":forename",a);
     query.bindValue(":surname",b);
     query.bindValue(":date", date /*date_string*/);
return    query.exec();
}
QSqlQueryModel* MEDICAMENT::recherche(int id)
{
  QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;

    QString id_string=QString::number(id);
    query.bindValue(":id",id_string);

model->setQuery("SELECT * FROM MEDICAMENT WHERE id=:id;");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifain"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date limite"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix_chere"));

query.exec();
  return  model;




}

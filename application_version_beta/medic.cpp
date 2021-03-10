#include "medic.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
Medic::Medic()
{

}
Medic::Medic(int id,QString nom,QString prenom)
{
    this->id=id; this->nom=nom;
    this->prenom=prenom;
}
int Medic::getid()
{
    return id;
}
QString Medic:: getnom()
{
    return nom;
}
QString Medic::getprenom()
{
    return prenom;
}
void Medic::setid(int id)
{
    this->id=id;
}
void Medic::setnom(QString nom)
{
    this->nom=nom;
}
void Medic::setprenom(QString prenom)
{
    this->prenom=prenom;

}
 bool Medic::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);
          query.prepare("INSERT INTO etudiant (id,nom, prenom) "
                        "VALUES (:id,:forename,:surname)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename",nom);
          query.bindValue(":surname", prenom);
       return query.exec();

 }
 QSqlQueryModel *Medic::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM etudiant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         return model;
 }
bool Medic::Supprime(int id)
{
    QSqlQuery query;
         query.prepare("delete from etudiant where id=:id");
         query.bindValue(0, id);
      return query.exec();
}

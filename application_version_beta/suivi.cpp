#include "suivi.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
suivi::suivi()
{
    id=0;
    taille=0;
    poid=0;
    date=0;
}
suivi::suivi(int id,double taille,double poid,double tension,double date)
{
    this->id=id; this->taille=taille;
    this->poid=poid; this->tension=tension;
    this->date=date;
}
int suivi::getid()
{
    return id;
}
double suivi:: gettaille()
{
    return taille;
}
double suivi::getpoid()
{
    return poid;
}
double suivi::getdate()
{
    return date;
}
void suivi::setid(int id)
{
    this->id=id;
}
void suivi::settaille(int taille)
{
    this->taille=taille;
}
void suivi::setpoid(int poid)
{
    this->poid=poid;

}
void suivi::settension(int tension)
{
    this->tension=tension;
}
double suivi::gettension()
{ return tension;
}
 bool suivi::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);
     QString taille_string=QString::number(taille);
     QString poid_string=QString::number(poid);
     QString tesion_string=QString::number(tension);
     QString date_string=QString::number(date);
          query.prepare("INSERT INTO suivi (id,taille,poid,tension) "
                        "VALUES (:id,:forename,:surname,:tension)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename",taille_string);
          query.bindValue(":surname", poid_string);
          query.bindValue(":tension", tesion_string);
       //   query.bindValue(":date", date_string);
       return query.exec();

 }
 QSqlQueryModel *suivi::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM suivi");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tension"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
         return model;
 }
bool suivi::Supprime(int id)
{
    QSqlQuery query;
         query.prepare("delete from suivi where id=:id");
         query.bindValue(0, id);
      return query.exec();
}

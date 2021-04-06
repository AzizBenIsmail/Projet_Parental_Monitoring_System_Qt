#include "suivi.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>

suivi::suivi()
{
    id=0;
    taille=0;
    poid=0;
    date="00/00/0000";
}
suivi::suivi(int id,double taille,double poid,double tension,QString date)
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
double suivi::gettension()
{
    return tension;
}
QString suivi::getdate()
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
void suivi::setdate(QString date)
{
    this->date=date;
}


 bool suivi::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);
     QString taille_string=QString::number(taille);
     QString poid_string=QString::number(poid);
     QString tesion_string=QString::number(tension);
    // QString date_string=QString::QString(date);
          query.prepare("INSERT INTO suivi (id,taille,poid,tension,Dat) "
                        "VALUES (:id,:forename,:surname,:tension,:date)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename",taille_string);
          query.bindValue(":surname", poid_string);
          query.bindValue(":tension", tesion_string);
          query.bindValue(":date", date /*date_string*/);
       return query.exec();

 }
 QSqlQueryModel *suivi::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM suivi ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tension"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
         return model;
 }
 QSqlQueryModel *suivi::afficher_id()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM suivi ORDER BY id");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tension"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
         return model;
 }
 QSqlQueryModel *suivi::afficher_poid()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM suivi ORDER BY poid");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tension"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
         return model;
 }
 QSqlQueryModel *suivi::afficher_taille()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM suivi ORDER BY taille");
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
bool suivi::modifier(int id,QString date)
{

QSqlQuery query;

QString id_string=QString::number(id);
QString taille_string=QString::number(taille);
QString poid_string=QString::number(poid);
QString tesion_string=QString::number(tension);

query.prepare("UPDATE suivi SET taille=:forename,poid=:surname,tension=:tension,dat=:date WHERE id=:id;");

query.bindValue(":id",id);
     query.bindValue(":forename",taille_string);
     query.bindValue(":surname",poid_string);
     query.bindValue(":tension",tesion_string);
     query.bindValue(":date", date /*date_string*/);
return    query.exec();
}
bool suivi::reset()
{
    QSqlQuery query;
         query.prepare("delete from suivi");
         query.bindValue(0, id);
      return query.exec();
}
QSqlQueryModel*  suivi::test()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM suivi WHERE  ( tension!=12)");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain problem"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("problem de tension"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        return model;
}
QSqlQueryModel *suivi::afficher_poidsideal()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM suivi WHERE (poid/(taille*taille)=1)");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("poid"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("tension"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        return model;
}

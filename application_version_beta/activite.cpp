#include "activite.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
Activite::Activite()
{
    id=0;
    duree=0;
    nom_Activite="";
    type="";
    date="";
}
Activite::Activite(int id,int duree,QString nom_Activite,QString type ,QString date )
{
    this->id=id;
    this->duree=duree;
    this-> nom_Activite= nom_Activite;
    this->type=type;
    this->date=date;


}
int Activite::getid()
{
    return id;
}
void Activite::setid(int id)
{
    this->id=id;
}
bool Activite::Ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString taille_string=QString::number(duree);



   // QString date_string=QString::QString(date);
         query.prepare("INSERT INTO Activite(id,nom_Activite,Dat,duree,type) "
                       "VALUES (:id,:nom,:date,:forename,:type)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename",taille_string);
         query.bindValue(":nom",nom_Activite);
         query.bindValue(":type",type);
         query.bindValue(":date", date /*date_string*/);
      return query.exec();

}
QSqlQueryModel *Activite::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM Activite ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Activite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));
        return model;
}
bool Activite::Supprime(int id)
{
   QSqlQuery query;
        query.prepare("delete from Activite where id=:id");
        query.bindValue(0, id);
     return query.exec();
}
bool Activite::modifier()
{

QSqlQuery query;

QString id_string=QString::number(id);
QString taille_string=QString::number(duree);

query.prepare("UPDATE Activite SET nom_Activite=:forename,type=:surname,duree=:tension,dat=:date WHERE id=:id;");

query.bindValue(":id",id);
    query.bindValue(":forename",nom_Activite);
    query.bindValue(":tension",duree);
    query.bindValue(":date",date);
    query.bindValue(":surname",type);

    query.bindValue(":date", date /*date_string*/);
return    query.exec();
}
bool Activite::reset()
{
   QSqlQuery query;
        query.prepare("delete Activite ");
        query.bindValue(0, id);
     return query.exec();
}

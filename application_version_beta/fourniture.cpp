#include "fourniture.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
Fourniture::Fourniture()
{
    id=0;
    ref=0;
    quantite=0;
    prix=0;
    date="";
}
Fourniture::Fourniture(int id,int ref ,int quantite, float prix,QString date )
{
    this->id=id;
    this->ref=ref;
    this->prix=prix;
    this->quantite=quantite;
    this->date=date;


}
int Fourniture::getid()
{
    return id;
}
void Fourniture::setid(int id)
{
    this->id=id;
}
bool Fourniture::Ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString taille_string=QString::number(ref);
    QString poid_string=QString::number(prix);
    QString tesion_string=QString::number(quantite);
   // QString date_string=QString::QString(date);
         query.prepare("INSERT INTO Fourniture (id,ref,quantite,prix,Dat) "
                       "VALUES (:id,:forename,:surname,:tension,:date)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename",taille_string);
         query.bindValue(":surname", poid_string);
         query.bindValue(":tension", tesion_string);
         query.bindValue(":date", date /*date_string*/);
      return query.exec();

}
QSqlQueryModel *Fourniture::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM Fourniture ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        return model;
}
bool Fourniture::Supprime(int id)
{
   QSqlQuery query;
        query.prepare("delete from Fourniture where id=:id");
        query.bindValue(0, id);
     return query.exec();
}
bool Fourniture::modifier(int id,QString date)
{

QSqlQuery query;

QString id_string=QString::number(id);
QString taille_string=QString::number(ref);
QString poid_string=QString::number(prix);
QString tesion_string=QString::number(quantite);

query.prepare("UPDATE Fourniture SET ref=:forename,quantite=:surname,prix=:tension,dat=:date WHERE id=:id;");

query.bindValue(":id",id);
    query.bindValue(":forename",taille_string);
    query.bindValue(":surname",poid_string);
    query.bindValue(":tension",tesion_string);
    query.bindValue(":date", date /*date_string*/);
return    query.exec();
}
bool Fourniture::reset()
{
   QSqlQuery query;
        query.prepare("delete Fourniture suivi");
        query.bindValue(0, id);
     return query.exec();
}
QSqlQueryModel *Fourniture::afficher_id()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM Fourniture ORDER BY id");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        return model;
}
QSqlQueryModel *Fourniture::afficher_prix()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM Fourniture ORDER BY prix");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        return model;
}

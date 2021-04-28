#include "vetement.h"
#include <QPixmap>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
vetement::vetement()
{
     ref=0;
     saison="";
     genre="";
     type="";
     taille="";
     marque="";
     prix=0;
}

vetement::vetement(int ref,QString saison,QString genre,QString type,QString taille,QString marque,float prix)
{
this->ref=ref;
this->saison=saison;
this->genre=genre;
this->type=type;
this->taille=taille;
this->marque=marque;
this->prix=prix;
}
int vetement::getref()
{return ref;}
QString vetement::getsaison()
{return saison;}
QString vetement::getgenre()
{return genre;}
QString vetement::gettype()
{return type;}
QString vetement::gettaille()
{return taille;}
QString vetement::getmarque()
{return marque;}
float vetement::getprix()
{return prix;}


void  vetement::setref(int ref)
{this->ref=ref;}
void  vetement::setsaison(QString saison)
{this->saison=saison;}
void  vetement::setgenre(QString genre)
{this->genre=genre;}
void  vetement::settype(QString type)
{this->type=type;}
void  vetement::settaille(QString taille)
{this->taille=taille;}
void  vetement::setmarque(QString marque)
{this->marque=marque;}
void  vetement::setprix(float prix)
{this->prix=prix;}


                                                  /*Crud*/

bool vetement::ajouter()
{
    QSqlQuery query;

    QString ref_string= QString::number(ref);
    QString prix_string= QString::number(prix);
        query.prepare("INSERT INTO vetement (ref, saison, genre, type, taille, marque, prix) "
                      "VALUES (:ref, :saison, :genre, :type, :taille, :marque, :prix)");
        query.bindValue(":ref", ref_string);
        query.bindValue(":saison", saison);
        query.bindValue(":genre", genre);
        query.bindValue(":type", type);
        query.bindValue(":taille", taille);
        query.bindValue(":marque", marque);
        query.bindValue(":prix", prix_string);

       return query.exec();

}

QSqlQueryModel *vetement::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM vetement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("saison"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));

        return model;
}

bool vetement::supprimer(int)
{
    QSqlQuery query;
         query.prepare("delete from vetement where ref=:ref");
         query.bindValue(0, ref);
      return query.exec();
}
bool vetement::reset()
{
    QSqlQuery query;
         query.prepare("delete from vetement");
      return query.exec();
}
bool vetement::modifier(int)
{

QSqlQuery query;

QString ref_string=QString::number(ref);
QString prix_string=QString::number(prix);

query.prepare("UPDATE vetement SET saison=:saison,genre=:genre,type=:type,taille=:taille,marque=:marque,prix=:prix WHERE ref=:ref;");

query.bindValue(":ref", ref);
query.bindValue(":saison", saison);
query.bindValue(":genre", genre);
query.bindValue(":type", type);
query.bindValue(":taille", taille);
query.bindValue(":marque", marque);
query.bindValue(":prix", prix_string);

return query.exec();

}




                          /*Metiers*/

QSqlQueryModel *vetement::afficher_ref()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM vetement ORDER BY ref");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("saison"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
QSqlQueryModel *vetement::afficher_prix()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM vetement ORDER BY prix");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("saison"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("marque"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
        return model;
}

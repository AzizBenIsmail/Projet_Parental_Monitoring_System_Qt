#include "boutique.h"
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
boutique::boutique()
{
   id=0;
   nom="";
   adr="";
   mail="";
   tel=0;
}

boutique::boutique(int id,QString nom,QString adr,QString mail,int tel)
{
this->id=id;
this->nom=nom;
this->adr=adr;
this->mail=mail;
this->tel=tel;
}
int boutique::getid()
{return id;}
QString boutique::getnom()
{return nom;}
QString boutique::getadr()
{return adr;}
QString boutique::getmail()
{return mail;}
int boutique::gettel()
{return tel;}

void  boutique::setid(int id)
{this->id=id;}
void  boutique::setnom(QString nom)
{this->nom=nom;}
void  boutique::setadr(QString adr)
{this->adr=adr;}
void  boutique::setmail(QString mail)
{this->mail=mail;}
void  boutique::settel(int tel)
{this->tel=tel;}

bool boutique::ajouter()
{
    QSqlQuery query;
    QString tel_string= QString::number(tel);
    QString id_string= QString::number(id);
        query.prepare("INSERT INTO BOUTIQUE (ID,NOM, ADR, TEL,MAIL) "
                      "VALUES (:id, :nom, :adr, :tel, :mail)");
        query.bindValue(":id", id_string);
        query.bindValue(":nom", nom);
        query.bindValue(":adr", adr);
        query.bindValue(":tel", tel_string);
        query.bindValue(":mail", mail);
       return query.exec();

}

QSqlQueryModel *boutique::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM BOUTIQUE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("adr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
        return model;
}

bool boutique::supprimer(int)
{
    QSqlQuery query;
         query.prepare("delete from Boutique where id=:id");
         query.bindValue(0, id);
      return query.exec();
}
bool boutique::reset()
{
    QSqlQuery query;
         query.prepare("delete from Boutique");
      return query.exec();
}

bool boutique::modifier(int)
{

QSqlQuery query;

QString id_string=QString::number(id);
QString tel_string=QString::number(tel);

query.prepare("UPDATE BOUTIQUE SET nom=:nom,adr=:adr,tel=:tel,mail=:mail WHERE id=:id;");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":tel",tel_string);
    query.bindValue(":adr",adr);
    query.bindValue(":mail",mail);

return    query.exec();
}

#ifndef ENFANT_H
#define ENFANT_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
//#include<QDate>

class enfant
{
public:
    enfant();

       enfant(int,QString,QString,QString,QString);
       int getid();
      QDate getdate_naissance_4();
      QString getnom_prenom();
      QString getetat_psycologique();
      QString gettalent();
      QString getsexe();
       void setid(int);
       void setdate_naissance(QDate);
       void setnom_prenom(QString);
       void setetat_psycologique(QString);
       void settalent(QString);
       void setsexe(QString);

       bool Ajouter();
       QSqlQueryModel* afficher();
       QSqlQueryModel* afficher_id();
       QSqlQueryModel* afficher_nom_prenom();
       QSqlQueryModel* afficher_sexe();
       //QSqlQueryModel* rechercher(int id);
       bool Supprime(int);
       bool modifier(int);
       bool reset();
       void recherche_animal_textChanged(const QString &arg1);
       QSqlQueryModel* test();
private:
    int id;
    QString nom_prenom,etat_psycologique,talent,sexe;
   // QDate date_naissance;
};


#endif // ENFANT_H


#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class Activite
{
private:

    int id,duree;
    QString  nom_Activite ,date,type;


public:
    Activite();
     Activite(int,int,QString,QString,QString);


     int getid();
     void setid(int);
     int get_duree();
     QString get_nom_Activite();
     QString get_date();
     QString get_type();
     bool Ajouter();
     QSqlQueryModel* afficher();
    bool Supprime(int);
     bool modifier();
     bool reset();
     QSqlQueryModel* afficher_id();
     QSqlQueryModel* afficher_prix();
};
#endif // Activite_H

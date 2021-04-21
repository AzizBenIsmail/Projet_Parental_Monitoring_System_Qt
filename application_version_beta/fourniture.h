#ifndef FOURNITURE_H
#define FOURNITURE_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class Fourniture
{
private:
    int id,ref,quantite;
    float prix;
    QString date;
public:
    Fourniture();
    Fourniture(int,int,int,float,QString);


    int getid();
    void setid(int);

     int get_ref();
     int get_quantite();
     float get_prix();
     QString get_Nomf();
     bool Ajouter();
     QSqlQueryModel* afficher();
    bool Supprime(int);
     bool modifier(int,QString);
     bool reset();
     QSqlQueryModel* afficher_id();
     QSqlQueryModel* afficher_prix();
};

#endif // FOURNITURE_H

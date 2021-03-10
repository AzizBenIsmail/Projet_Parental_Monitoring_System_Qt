#ifndef SUIVI_H
#define SUIVI_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class suivi
{
public:
    suivi();
    suivi(int,double,double,double,double);
    int getid();
    double gettaille();
    double getpoid();
    double getdate();
    void setid(int);
    void settaille(int);
    void setpoid(int);
    void setdate(int);
     void settension(int);
     double gettension();

    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
private:
    int id;
    double taille,poid,date,tension;
};

#endif // SUIVI_H

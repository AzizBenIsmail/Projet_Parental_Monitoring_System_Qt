#ifndef SUIVI_H
#define SUIVI_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include<vector>

class suivi
{
public:
    suivi();
    suivi(int,double,double,double,QString);
    int getid();
    double gettaille();
    double getpoid();
    QString getdate();
    void setid(int);
    void settaille(int);
    void setpoid(int);
    void setdate(QString);
     void settension(int);
     double gettension();

    bool Ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_id();
    QSqlQueryModel* afficher_poid();
    QSqlQueryModel* afficher_taille();
    QSqlQueryModel* afficher_poidsideal();

    bool Supprime(int);
    bool modifier(int,QString);
    bool reset();
    QVector<float> stat();
    QSqlQueryModel* test();

private:
    int id;
    double taille,poid,tension;
    QString date;
};

#endif // SUIVI_H

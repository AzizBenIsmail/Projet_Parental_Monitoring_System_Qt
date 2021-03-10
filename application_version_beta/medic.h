#ifndef MEDIC_H
#define MEDIC_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>


class Medic
{
public:
    Medic();
    Medic(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
private:
    int id;
    QString nom,prenom;
};

#endif // MEDIC_H

#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class boutique
{
public:
    boutique();
    boutique(int,QString,QString,QString,int);

    int getid();
    QString getnom();
    QString getadr();
    QString getmail();
    int gettel();

    void setid(int);
    void setnom(QString);
    void setadr(QString);
    void setmail(QString);
    void settel(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool reset();
    bool modifier(int);
private:
    int id;
    QString nom;
    QString adr;
    QString mail;
    int tel;
};

#endif // BOUTIQUE_H

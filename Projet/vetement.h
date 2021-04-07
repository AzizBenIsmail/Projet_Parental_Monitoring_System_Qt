#ifndef VETEMENT_H
#define VETEMENT_H


#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class vetement
{
public:
    vetement();
    vetement(int,QString,QString,QString,QString,QString,float);

    int getref();
    QString getsaison();
    QString getgenre();
    QString gettype();
    QString gettaille();
    QString getmarque();
    float getprix();



    void setref(int);
    void setsaison(QString);
    void setgenre(QString);
    void settype(QString);
    void settaille(QString);
    void setmarque(QString);
    void setprix(float);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_prix();
    QSqlQueryModel* afficher_ref();
    bool supprimer(int);
    bool reset();
    bool modifier(int);
    bool chercher();
private:
    int ref;
    QString saison;
    QString genre;
    QString type;
    QString taille;
    QString marque;
    float prix;
};

#endif // VETEMENT_H

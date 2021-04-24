#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class MEDICAMENT
{
public:
    MEDICAMENT();
    MEDICAMENT(int,double,double,QString);
    int getid();
    double getprix();
    double getquantite();
    QString getdate();

    void setid(int);
    void setprix(double);
    void setquantite(double);
    void setdate(QString);


    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
    bool reset();
    QSqlQueryModel* afficher_qt();
    QSqlQueryModel* afficher_prix();
    bool modifier(int,QString);
     QSqlQueryModel* recherche_faible();
      QSqlQueryModel* recherche_moye();
      QSqlQueryModel* recherche(int);
       QSqlQueryModel* recherche_chere();
private:
    double id,prix,quantite;
    QString date;
};

#endif // MEDICAMENT_H

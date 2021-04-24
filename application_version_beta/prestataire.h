#ifndef PRESTATAIRE_H
#define PRESTATAIRE_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QTableView>
class prestataire
{
public:
    prestataire();
    prestataire(int,QString,QString,int,QString,QString,int,int,QString,QString);
    int getidpres();
   QString getnompres();
   QString getprenompres();
   int getsalairepres();
   QString getspecialitepres();
   QString getdateembauchepres();
   int getnbr_heurespres();
   int gettelpres();
   QString getadressepres();
   QString getsexepres();

    void setidpres(int);
    void setnompres(QString);
    void setprenompres(QString);
    void setsalairepres(int);
    void setspecialitepres(QString);
    void setdateembauchepres(QString);
    void setnbr_heurespres(int);
    void settelpres(int);
    void setadressepres(QString);
    void setsexepres(QString);

    bool Ajouter_pres();
    QSqlQueryModel* afficher_pres();
  //  QSqlQueryModel* afficher_id();
  //  QSqlQueryModel* afficher_nom_prenom();
   //  QSqlQueryModel* rechercher();
    bool Supprime_pres(int);
    bool modifier_pres(int);
    bool reset_pres();
       void rechercher(QTableView *table,QString cas );
    QSqlQueryModel* test();
private:
 int idpres,salairepres,nbr_heurespres,telpres;
 QString nompres,prenompres,specialitepres,dateembauchepres,adressepres,sexepres;
};




#endif // PRESTATAIRE_H

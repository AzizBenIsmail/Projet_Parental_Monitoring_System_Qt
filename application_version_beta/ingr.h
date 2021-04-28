#ifndef INGR_H
#define INGR_H
#include <QString>
#include<QSqlQueryModel>
#include<QDate>
#include <QSqlQuery>

class ingr
{
public:
    ingr();
    void setnoming(QString noming_i) {noming_i=noming;}
 //   void setduree(QString duree_consommation_i ) {duree_consommation_i=duree_consommation;}
    void settype(QString type_i) {type_i=type;}
 //   void setprix(QString prix_i){prix_i=prix;}
    void valeuralimentaire(QString  valeur_alimentaire_i ){valeur_alimentaire_i=valeur_alimentaire;}
    QString getnoming(){return noming;}
 //   QString getduree(){return duree_consommation;}
    QString gettype(){return type;}
 //   QString getprix(){return prix; }
    QString getvaleuralimentaire(){return valeur_alimentaire; }
    ingr(QString,QString,QString);
    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString noming_i,QString type_i ,QString valeur_alimentaire_i);
    bool modifier();

private:
 QString noming,type,valeur_alimentaire;
// QString duree_consommation,prix;

};




#endif // INGR_H

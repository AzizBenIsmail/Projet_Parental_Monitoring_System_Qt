#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <QString>
#include<QSqlQueryModel>
#include<QDate>
#include <QSqlQuery>
class Ingredient
{
public:
    Ingredient();
    void setnom(QString nom_r) {nom_repas=nom_r;}
    void settype(QString type_r ) {type_repas=type_r;}
    void setheure(QString heure_r) {heure_repas=heure_r;}
    void setcategorie(QString repas_r){categorie_repas=repas_r;}
    QString getnom(){return nom_repas;}
    QString gettype(){return type_repas;}
    QString getheure(){return heure_repas;}
    QString getcategorie(){return categorie_repas; }
    Ingredient(QString,QString,QString,QString);
    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel * afficher();
     QSqlQueryModel * recherche(QString NOM_R,QString TYPE_R,QString CATEGORIE_R);
     bool modifier() ;

    bool auth(QString,QString);
private:
 QString nom_repas,type_repas,heure_repas,categorie_repas;
   };

#endif // INGREDIENT_H



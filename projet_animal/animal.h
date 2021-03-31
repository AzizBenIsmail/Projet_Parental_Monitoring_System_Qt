#ifndef ANIMAL_H
#define ANIMAL_H
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Animal
{
private:

    int id,age;
    float prix;
    QString Nom,Race,sex;

public:
    Animal();
     Animal(int,int,float,QString,QString,QString);


     int get_id();
     int get_age();
     float get_prix();
     QString get_Nom();
     QString get_Race();
     QString get_sex();
     bool ajouter();
     bool modifier();
     QSqlQueryModel * afficher();
     bool supprimer(int);
};
#endif // ANIMAL_H

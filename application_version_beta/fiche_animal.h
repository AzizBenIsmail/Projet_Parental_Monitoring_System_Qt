#ifndef FICHE_ANIMAL_H
#define FICHE_ANIMAL_H
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>

class Fiche_animal
{
private:

    int id,poid,taille,nbr_consultation,id_animal;
    QString date_vacc,etat,nom_maladie;


public:
    Fiche_animal();
    Fiche_animal(int,int,int,int,int,QString,QString,QString);


     int get_id();
     int get_poid();
     int get_taille();
     int get_nbr_consultation();
     int get_id_animal();
     QString get_date_vacc();
     bool ajouter();

     QSqlTableModel *afficher();
   QSqlTableModel *supprimer ();
};

#endif // FICHE_ANIMAL_H

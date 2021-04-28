#ifndef ANIMAL_H
#define ANIMAL_H
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QTableView>
#include <QDate>

class Animal
{
private:

    int id,age;
    float prix;
    QString Nom,Race,sex;
    QString DATE_ACHAT;

public:
    Animal();
     Animal(int,int,float,QString,QString,QString,QString);


     int get_id();
     int get_age();
     float get_prix();
     QString get_Nom();
     QString get_Race();
     QString get_Date_Achat();
     QString get_sex();
     bool ajouter();


     QSqlTableModel *afficher();
   QSqlTableModel *supprimer ();

    QSqlTableModel *tri (int );
    void cleartable(QTableView * table);
     void rechercher(QTableView * table,QString );
};




#endif // ANIMAL_H

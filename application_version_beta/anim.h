#ifndef ANIM_H
#define ANIM_H
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QTableView>
#include <QDate>

class Anim
{
private:

    int id,age;
    float prix;
    QString Nom,Race,sex;
    QString DATE_ACHAT;

public:
    Anim();
    Anim(int,int,float,QString,QString,QString,QString);
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

#endif // ANIM_H

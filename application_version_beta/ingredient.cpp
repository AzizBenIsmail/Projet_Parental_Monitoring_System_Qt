#include "ingredient.h"
#include <QMessageBox>
Ingredient::Ingredient()
{

}
Ingredient::Ingredient (QString nom, QString type,QString heure ,QString categorie)
{
   nom_repas = nom;
   type_repas = type;
   heure_repas= heure;
   categorie_repas=categorie;
  }


bool Ingredient::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO ingredient (NOM_R, TYPE_R, HEURE_R,CATEGORIE_R) "
                   "VALUES (:NOM_R, :TYPE_R, :HEURE_R,:CATEGORIE_R)");

query.bindValue(":NOM_R",getnom());
query.bindValue(":TYPE_R",gettype());
query.bindValue(":HEURE_R",getheure());
query.bindValue(":CATEGORIE_R",getcategorie());

return  query.exec();
}
QSqlQueryModel * Ingredient::afficher()
{
 QSqlQueryModel *model =new QSqlQueryModel();
 model->setQuery("select * from INGREDIENT");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_R"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_R"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("HEURE_R"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("CATEGORIE_R"));
  return model;

}

bool Ingredient::supprimer(QString NOM)
{
   QSqlQuery query;

   query.prepare("delete from INGREDIENT where NOM_R=:NOM_R");
   query.bindValue(":NOM_R",NOM);
   return query.exec();
}

QSqlQueryModel *Ingredient::recherche(QString NOM_R, QString TYPE_R, QString CATEGORIE_R)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int c=0;
    query.prepare("SELECT *from Ingredient where NOM_R=:NOM_R or TYPE_R=:TYPE_R or CATEGORIE_R=:CATEGORIE_R");
    query.bindValue(":NOM_R",NOM_R);
    query.bindValue(":TYPE_R",TYPE_R);
    query.bindValue(":CATEGORIE_R",CATEGORIE_R);
    if(query.exec())
    {
        while(query.next())
        {
            c++;
        }

        if(c==1)
        {
            QMessageBox boxt;
            boxt.setText("trouvé");
            boxt.exec();
            model->setQuery(query);
        }
        else
            if (c<1)
            {
                QMessageBox boxpt;
                boxpt.setText("pas trouvé");
                boxpt.exec();
                model=0;
            }
        return model;
    }

}

#include "ingr.h"
#include <QMessageBox>
ingr::ingr()
{

}

ingr::ingr (QString noming_i, QString type_i ,QString valeur_alimentaire_i)
{
   noming = noming_i;

   type= type_i;

   valeur_alimentaire=valeur_alimentaire_i;
  }


bool ingr::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO INGR (NOMING, TYPE,VALEUR_ALIMENTAIRE) "
                   "VALUES (:NOMING, :TYPE, :VALEUR_ALIMENTAIRE)");

query.bindValue(":NOMING",getnoming());
//query.bindValue(":DUREE_CONSOMMATION",getduree());
query.bindValue(":TYPE",gettype());
//query.bindValue(":PRIX",getprix());
query.bindValue(":VALEUR_ALIMENTAIRE",getvaleuralimentaire());

return  query.exec();
}


QSqlQueryModel * ingr::afficher()
{
 QSqlQueryModel *model =new QSqlQueryModel();
 model->setQuery("select * from INGR");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMING"));

 model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));

 model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR_ALIMENTAIRE"));
  return model;

}

bool ingr::supprimer(QString NOMING)
{
   QSqlQuery query;

   query.prepare("delete from INGR where NOMING=:NOMING");
   query.bindValue(":NOMING",NOMING);
   return query.exec();
}

QSqlQueryModel *ingr::recherche(QString NOMING, QString TYPE, QString VALEUR_ALIMENTAIRE)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int c=0;
    query.prepare("SELECT *from INGR where NOMING=:NOMING or TYPE=:TYPE or VALEUR_ALIMENTAIRE=:VALEUR_ALIMENTAIRE");
    query.bindValue(":NOMING",NOMING);
    query.bindValue(":TYPE",TYPE);
    query.bindValue(":VALEUR_ALIMENTAIRE",VALEUR_ALIMENTAIRE);
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




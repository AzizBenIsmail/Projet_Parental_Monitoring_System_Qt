#include "fiche_animal.h"

Fiche_animal::Fiche_animal()
{
    id=0;
    poid=0;
    taille=0;
    nbr_consultation=0;
    id_animal=0;
    date_vacc="";
}
Fiche_animal::Fiche_animal(int id,int poid,int taille,int nbr_consultation,int id_animal ,QString date_vacc,QString etat,QString nom_maladie )
{
    this->id=id;
    this->poid=poid;
    this->taille=taille;
    this->nbr_consultation=nbr_consultation;
    this->id_animal=id_animal;
    this->date_vacc=date_vacc;
    this->etat=etat;
      this->nom_maladie=nom_maladie;

}

bool Fiche_animal::ajouter()
{


QSqlQuery query;
query.prepare("INSERT INTO FICHE_ANIMAL (ID, POID, TAILLE, NBR_CONSULTATION,DATE_VACC,ID_ANNIMAL,ETAT,NOM_MALADE) "
                    "VALUES (:ID, :POID, :TAILLE, :NBR_CONSULTATION,:DATE_VACC,:ID_ANNIMAL,:ETAT,:NOM_MALADE)");
QString ID= QString::number(id);
QString POID= QString::number(poid);
QString TAILLE= QString::number(taille);
 QString NBR_CONSULTATION= QString::number(nbr_consultation);
  QString ID_ANNIMAL= QString::number(id_animal);
query.bindValue(":ID", ID);
query.bindValue(":POID", POID);
query.bindValue(":TAILLE", TAILLE);
query.bindValue(":NBR_CONSULTATION", NBR_CONSULTATION);
query.bindValue(":DATE_VACC", date_vacc);
query.bindValue(":ID_ANNIMAL", ID_ANNIMAL);
 query.bindValue(":ETAT", etat);
  query.bindValue(":NOM_MALADE", nom_maladie);
query.exec();
return true    ;
}

QSqlTableModel * Fiche_animal::afficher()
{

    QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("FICHE_ANIMAL");
    mmodel->select();
    return mmodel;
}

QSqlTableModel * Fiche_animal::supprimer()
{

    QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("FICHE_ANIMAL");
    mmodel->select();
    return mmodel;
}

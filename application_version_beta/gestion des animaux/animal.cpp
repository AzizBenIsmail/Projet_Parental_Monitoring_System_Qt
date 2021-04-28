#include "animal.h"
#include <QDebug>
#include <QMessageBox>
//#include "connection.h"

Animal::Animal()
{
   id=0;
   age=0;
   prix=0;
   Nom="";
   Race="";
   sex="";
}
 Animal::Animal(int id,int age,float prix,QString Nom,QString Race ,QString sex ,QString DATE_ACHAT)
{
     this->id=id;
     this->age=age;
     this->prix=prix;
     this->Nom=Nom;
     this->Race=Race;
     this->sex=sex;
     this->DATE_ACHAT=DATE_ACHAT;

}

 bool Animal::ajouter()
 {


 QSqlQuery query;
 query.prepare("INSERT INTO ANIMAL (ID, AGE, PRIX, NOM,RACE,SEX,DATE_ACHAT) "
                     "VALUES (:ID, :AGE, :PRIX, :NOM,:RACE,:SEX,:DATE_ACHAT)");
 QString ID= QString::number(id);
 QString AGE= QString::number(age);
 QString PRIX= QString::number(prix);
 query.bindValue(":ID", ID);
 query.bindValue(":AGE", AGE);
 query.bindValue(":PRIX", PRIX);
 query.bindValue(":NOM", Nom);
 query.bindValue(":RACE", Race);
 query.bindValue(":SEX", sex);
 query.bindValue(":DATE_ACHAT", DATE_ACHAT);




 return query.exec()    ;
 }


 QSqlTableModel * Animal::afficher()
 {

     QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ANIMAL");
     mmodel->select();
     return mmodel;
 }
 QSqlTableModel * Animal::tri(int num )
 {

     QSqlTableModel *mmodel = new QSqlTableModel();
          mmodel->setTable("ANIMAL");
         mmodel->setSort(num,Qt::DescendingOrder);
         mmodel->select();
         return mmodel;
 }
 QSqlTableModel * Animal::supprimer()
 {

     QSqlTableModel *mmodel = new QSqlTableModel();
     mmodel->setTable("ANIMAL");
     mmodel->select();
     return mmodel;
 }

 void Animal ::rechercher(QTableView *table,QString cas )
  {
      QSqlQueryModel *model= new QSqlQueryModel();

      QSqlQuery *query=new QSqlQuery;

      query->prepare("SELECT * FROM ANIMAL WHERE (NOM LIKE '%"+cas+"%' or RACE LIKE '%"+cas+"%' or SEX Like '%"+cas+"%' )");

      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();

  }
  void Animal::cleartable(QTableView * table)
  {
      QSqlQueryModel *model= new QSqlQueryModel();
      model->clear();
      table->setModel(model);
  }


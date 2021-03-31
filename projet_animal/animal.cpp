#include "animal.h"
#include <QDebug>
#include <QMessageBox>
//#include "connection.h"



 bool ajouter();
 bool modifier();
 QSqlQueryModel * afficher();
 bool supprimer(int);

Animal::Animal()
{
   id=0;
   age=0;
   prix=0;
   Nom="";
   Race="";
   sex="";
}
 Animal::Animal(int id,int age,float prix,QString Nom,QString Race ,QString sex )
{
     this->id=id;
     this->age=age;
     this->prix=prix;
     this->Nom=Nom;
     this->Race=Race;
     this->sex=sex;

}

 bool Animal::ajouter()
 {


 QSqlQuery query;
 query.prepare("INSERT INTO ANIMAL (ID, AGE, PRIX, NOM,RACE,SEX) "
                     "VALUES (:ID, :AGE, :PRIX, :NOM,:RACE,:SEX)");
 QString ID= QString::number(id);
 QString AGE= QString::number(age);
 QString PRIX= QString::number(prix);
 query.bindValue(":ID", ID);
 query.bindValue(":AGE", AGE);
 query.bindValue(":PRIX", PRIX);
 query.bindValue(":NOM", Nom);
 query.bindValue(":RACE", Race);
 query.bindValue(":SEX", sex);





 return query.exec()    ;
 }

 QSqlQueryModel * Animal::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from ANIMAL");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("AGE"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("RACE"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
 return model;
 }






 bool Animal::modifier()
 {

 QSqlQuery query;

 query.prepare("UPDATE Animal SET AGE=:AGE,PRIX=:PRIX,NOM=:NOM,RACE=:RACE, SEX=:SEX WHERE ID=:ID");
 QString ID= QString::number(id);
 QString AGE= QString::number(age);
 QString PRIX= QString::number(prix);
 query.bindValue(":ID", ID);
 query.bindValue(":AGE", AGE);
 query.bindValue(":PRIX", PRIX);
 query.bindValue(":NOM", Nom);
 query.bindValue(":RACE", Race);
 query.bindValue(":SEX", sex);

 return    query.exec();
 }




 bool Animal::supprimer(int NId)
 {
     QSqlQuery query;

     query.prepare("Delete from Animal where ID = :id");
     query.bindValue(":id",NId);
     return    query.exec();
 }


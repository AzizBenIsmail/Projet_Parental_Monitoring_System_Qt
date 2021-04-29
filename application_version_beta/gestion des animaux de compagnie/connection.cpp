#include "connection.h"
#include <QSqlDatabase>
#include<QDebug>
#include <QSqlQuery>
#include<iostream>
#include <QSqlError>
using namespace std;
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A");
db.setUserName("lamis");//inserer nom de l'utilisateur
db.setPassword("lamis");//inserer mot de passe de cet utilisateur

if(db.open())
{
    test=true;
    cout<<"succes"<<endl;
}
    else
    {
    qDebug()<< db.lastError();
    cout<<"failed"<<endl;
    }




    return  test;
}

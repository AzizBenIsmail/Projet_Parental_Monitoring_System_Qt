#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("lamis");//inserer nom de l'utilisateur
db.setPassword("lamis");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

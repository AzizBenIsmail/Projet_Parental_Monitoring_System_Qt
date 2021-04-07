#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_QT");//inserer le nom de la source de données ODBC
db.setUserName("yassine");//inserer nom de l'utilisateur
db.setPassword("2711");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

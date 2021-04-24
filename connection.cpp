#include "connection.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("contact");//inserer le nom de la source de données ODBC
db.setUserName("chaima");//inserer nom de l'utilisateur
db.setPassword("chaima");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

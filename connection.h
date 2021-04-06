#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class connexion
{
public:
    connexion();
      bool createconnect();
};

#endif // CONNECTION_H

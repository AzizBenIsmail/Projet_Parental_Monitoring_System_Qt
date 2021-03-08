#ifndef ADMIN_H
#define ADMIN_H
#include <QString>


class admin
{ private:
    QString Login,Password;
public:
    void SetLogin(QString n);
    void SetPassword(QString n);
    QString GetLogin();
    QString GetPassword();
    admin();
};
#endif // ADMIN_H

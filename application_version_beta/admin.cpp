#include "admin.h"
#include <QString>

admin::admin()
{ Login="";
Password="";
}
void admin::SetLogin(QString n)
{ Login=n;
}
void admin::SetPassword(QString n)
{
 Password=n;
}
QString admin::GetLogin()
{
    return Login   ;
}
QString admin::GetPassword()
{
    return  Password;
}

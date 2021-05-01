#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include <QString>
class notification
{
public:
    notification(){};
   void notification_connecter(QString);
void notification_ajout(QString);


private:
    int num;
};

#endif // NOTIFICATION_H

#include "notification.h"


void notification::notification_connecter(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/Mohamed Ali Sghari/Desktop/notif.png"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("notification","Admin connecté !",QSystemTrayIcon::Information,15000);

}

void notification::notification_ajout(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/Mohamed Ali Sghari/Desktop/notif.png"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("notification"," Un nouveau abonné est ajouté !",QSystemTrayIcon::Information,15000);

}

#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "notification.h"
#include<QFile>
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/Adaptic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

  QTranslator T;
  QStringList langs;
  langs << "English" << "French" <<"Arabic";
  const QString lang= QInputDialog::getItem(NULL,"Language","Select a language :",langs);
  if(lang=="English")
  {
      T.load(":/new/prefix1/français.qm");
  }else if(lang=="Arabic")
  {
      T.load(":/new/prefix1/arabe.qm");
  }
  if(lang!="French")
  {
      a.installTranslator(&T);
  }







    connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();

        QMessageBox::information(nullptr, QObject::tr("Welcom"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    w.show();
    return a.exec();
}

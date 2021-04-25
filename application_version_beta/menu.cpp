#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "aide.h"
#include "sante.h"
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include "animal.h"
#include "securite.h"
#include "contact.h"
#include "programme.h"
#include "cuisine.h"
#include "capteur_dincendie.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
   QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/9.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}
void Menu::showTime()
{
    QTime time=QTime ::currentTime();
    QString time_texte=time.toString("hh : mm : ss");
    if((time.second() % 2)==0)
    { time_texte[3]= ' ';
        time_texte[8]= ' ';
    }
    ui->Digital_clock->setText(time_texte);
}


Menu::~Menu()
{
    delete ui;
}


void Menu::on_pushButton_logout_clicked()
{
    hide();
    Login m;
    m.exec();
}


void Menu::on_pushButton_a_clicked()
{
    hide();
    aide a;
    a.exec();
}
void Menu::on_pushButton_Q_clicked()
{
    int reponse = QMessageBox::question(this, "Interrogatoire", "Monsieur esque tu est sur tu veux quitter?", QMessageBox ::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            QMessageBox::critical(this, "bayy bayy", "Ala pouchane !");
            close();
        }
        else if (reponse == QMessageBox::No)
        {
            QMessageBox::information(this, "Helloo", "Alors bienvenue!");
        }
}


void Menu::on_pushButton_Sante_clicked()
{
    hide();
    Sante s;
    s.exec();
}
void Menu::on_pushButton_a_2_clicked()
{
    hide();
    Animal ni;
    ni.exec();
}
//Admin@esprit.tn
void Menu::on_pushButton_Securite_clicked()
{
    hide();
    Securite se;
    se.exec();
}


void Menu::on_pushButton_Contact_clicked()
{
    hide();
    Contact c;
    c.exec();
}

void Menu::on_pushButton_programme_clicked()
{
    hide();
    programme c;
    c.exec();

}

void Menu::on_pushButton_cui_clicked()
{
    hide();
    cuisine cui;
    cui.exec();
}


void Menu::label_5()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_5->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_5->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void Menu::on_pushButton99_7_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}

void Menu::on_pushButton99_8_clicked()
{
     A.write_to_arduino("0");
}

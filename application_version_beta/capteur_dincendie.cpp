#include "capteur_dincendie.h"
#include "ui_capteur_dincendie.h"

capteur_dincendie::capteur_dincendie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capteur_dincendie)
{
    ui->setupUi(this);
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

void capteur_dincendie::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_5->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_5->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void capteur_dincendie::on_pushButton_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}

void capteur_dincendie::on_pushButton_2_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("0");  //envoyer 0 à arduino
}



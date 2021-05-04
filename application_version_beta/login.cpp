#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QPixmap>
#include "admin.h"
#include"menu.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include "securite.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{



    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/avatar.png");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/..jpg");
    int w1=ui->label_p->width();
    int h1=ui->label_p->height();
    ui->label_p->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    ui->lineEdit_login->setPlaceholderText("AdresseMail@Contact.com");
    ui->lineEdit_password->setPlaceholderText("Password ");


}
void Login::showTime()
{
    QTime time=QTime ::currentTime();
    QString time_texte=time.toString("hh : mm : ss");
    if((time.second() % 2)==0)
    { time_texte[3]= ' ';
        time_texte[8]= ' ';
    }
    ui->Digital_clock->setText(time_texte);
}
Login::~Login()
{
    delete ui;

}

void Login::on_pushButton_Q_clicked()
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




void Login::on_pushButton_valide_clicked()
{ admin l;
l.SetLogin(ui->lineEdit_login->text());
l.SetPassword(ui->lineEdit_password->text());

if((l.GetLogin()=="")&&(l.GetPassword()==""))
{
    QMessageBox::warning(this, "yo yo ", "il faux saisie login & Password");
}else
if((l.GetLogin()=="Admin")&&(l.GetPassword()=="Admin"))
{
    hide();
    Menu m;
    //m.setClient(l);
    m.exec();

}else
{ int rep = QMessageBox::question(this, "Message d'erreur", "mots de passe ou login incorrecte?", QMessageBox ::Yes | QMessageBox::No);

    if (rep ==QMessageBox::No )
    {
        QMessageBox::information(this, "Sorry", "tu peut pas accéder à cette application!");
        close();
    }
    else if (rep == QMessageBox::Yes)
    {
        QMessageBox::critical(this, "Attention", "faire attention une autre fois ");
    }
  }
}

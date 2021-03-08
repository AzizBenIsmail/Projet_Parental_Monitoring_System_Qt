#include "aide.h"
#include "ui_aide.h"
#include <QPixmap>
#include "menu.h"
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include "note.h"
#include "calculator.h"
aide::aide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aide)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/0.png");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/ASUS/Documents/application_version_beta/...jpg");
    int w1=ui->label_p->width();
    int h1=ui->label_p->height();
    ui->label_p->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}
void aide::showTime()
{
    QTime time=QTime ::currentTime();
    QString time_texte=time.toString("hh : mm : ss");
    if((time.second() % 2)==0)
    { time_texte[3]= ' ';
        time_texte[8]= ' ';
    }
    ui->Digital_clock->setText(time_texte);
}

aide::~aide()
{
    delete ui;

}

void aide::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void aide::on_pushButton_note_clicked()
{
    hide();
    Note a;
    a.exec();
}
void aide::on_pushButton_Cal_clicked()
{
    hide();
    calculator c;
    c.exec();
}
void aide::on_pushButton_Q_clicked()
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


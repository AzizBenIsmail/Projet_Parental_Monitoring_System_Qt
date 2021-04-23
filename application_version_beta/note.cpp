#include "note.h"
#include "ui_note.h"
#include "aide.h"
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
Note::Note(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/..jpg");
    int w1=ui->label_ph->width();
    int h1=ui->label_ph->height();
    ui->label_ph->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
QTimer *timer=new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
timer->start();
}
void Note::showTime()
{
QTime time=QTime ::currentTime();
QString time_texte=time.toString("hh : mm : ss");
if((time.second() % 2)==0)
{ time_texte[3]= ' ';
    time_texte[8]= ' ';
}
ui->Digital_clock->setText(time_texte);
}
Note::~Note()
{
    delete ui;
}

void Note::on_pushButton_clicked()
{
    hide();
    aide m;
    m.exec();
}

void Note::on_pushButton_ecrire_clicked()
{
    QFile file("C:/Users/ASUS/Documents/application_version_beta/myfile.txt");
    if( (!file.open(QFile::WriteOnly)) & (QFile::Text) )
    {
    QMessageBox::information(this, "Helloo", "Alors bienvenue!");
    }
    QTextStream out(&file);
    QString text=ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Note::on_pushButton_lire_clicked()
{
    QFile file("C:/Users/ASUS/Documents/application_version_beta/myfile.txt");
    if( (!file.open(QFile::ReadOnly)) & QFile::Text){
    QMessageBox::information(this, "Helloo", "Alors bienvenue!");}

    QTextStream in(&file);
    QString text=in.readAll();
ui->plainTextEdit->setPlainText(text);
file.close();
}

void Note::on_pushButton_Q_clicked()
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

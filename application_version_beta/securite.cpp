#include "securite.h"
#include "ui_securite.h"
#include "menu.h"
#include <QPixmap>
#include "QString"
#include <QMessageBox>
Securite::Securite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Securite)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/5.jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}




Securite::~Securite()
{
    delete ui;
}

void Securite::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}



void Securite::on_pushButton_Q_clicked()
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

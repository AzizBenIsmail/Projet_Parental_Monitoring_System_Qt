#include "cuisine.h"
#include "ui_cuisine.h"
#include <QPixmap>
#include "menu.h"
#include <QMessageBox>
cuisine::cuisine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cuisine)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/MSI/OneDrive/Bureau/application_version_beta/cui.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

cuisine::~cuisine()
{
    delete ui;
}

void cuisine::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void cuisine::on_pushButton_Q_clicked()
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

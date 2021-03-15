#include "programme.h"
#include "ui_programme.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
programme::programme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programme)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/pro.jpg");
    int w=ui->label_a->width();
    int h=ui->label_a->height();
    ui->label_a->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

programme::~programme()
{
    delete ui;
}

void programme::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void programme::on_pushButton_Q_clicked()
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

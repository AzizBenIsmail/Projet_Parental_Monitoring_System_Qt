#include "contact.h"
#include "ui_contact.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
Contact::Contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contact)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/MSI/OneDrive/Bureau/application_version_beta/c.jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Contact::~Contact()
{
    delete ui;
}

void Contact::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void Contact::on_pushButton_Q_clicked()
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

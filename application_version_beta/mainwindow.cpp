#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "login.h"
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    animation = new QPropertyAnimation(ui->bienvenu, "geometry");
    animation->setDuration(15000);
    animation->setStartValue(ui->bienvenu->geometry());
    animation->setEndValue(QRect(700,700,200,500));
    animation->start();
    // QMessageBox::information(this, "Welcom", "Bonjour et bienvenue à <strong> votre application </strong>");
QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/Smart-Home-2.jpg");
int w=ui->label_ph->width();
int h=ui->label_ph->height();
ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
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


void MainWindow::on_bienvenu_clicked()
{
   /* Login login;
    login.setModal(true);
     login.exec(); */
    hide();
    login = new Login(this);
    login->show();
}

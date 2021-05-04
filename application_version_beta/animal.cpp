#include "animal.h"
#include "ui_animal.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
#include<iostream>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <anim.h>
#include <QSqlRecord>
#include <fiche_animal.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPdfWriter>

#include <QSqlRecord>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

Animal::Animal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Animal)
{
    ui->setupUi(this);
      ui->listView->setModel(afficherHistorique());
    QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/a.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/a.jpg");
    int w1=ui->label_ph_4->width();
    int h1=ui->label_ph_4->height();
    ui->label_ph_4->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    QPixmap pix2("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/a.jpg");
    int w2=ui->label_ph_3->width();
    int h2=ui->label_ph_3->height();
    ui->label_ph_3->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    ui->tableView->setModel(a.afficher());



          ui->tableView_2->setModel(b.afficher());
}

Animal::~Animal()
{
    delete ui;
}

void Animal::on_pushButton_R_clicked()
{
    hide();
    Menu m;
    m.exec();
}

void Animal::on_pushButton_Q_clicked()
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

void Animal::on_Ajouter_FICHE_clicked()
{
    int id=ui->lineEdit_id_Fiche_animal->text().toInt();
     int poid=ui->lineEdit_poid_fiche->text().toInt();
           int taille = ui->lineEdit_taille_fiche->text().toInt();
               int nbr = ui->lineEdit_nbr_fiche->text().toInt();
       QString date = ui->date_fiche->text();
     int id_animal = ui->lineEdit_id_animal_fiche->text().toInt();
     QString etat = ui->etat_text->text();
     QString nom_malade = ui->nom_maladie->text();
     if (id < 0 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id"),
                     QObject::tr("verifier id\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (poid < 0 || poid > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                     QObject::tr("verifier poid\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
    else  if (taille < 0 || taille > 90 )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                     QObject::tr("verifier taille\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (nbr==0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem nbr"),
                     QObject::tr("verifier nom\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (id_animal<0  )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem id_animal"),
                     QObject::tr("verifier id_animal\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (etat=="" )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem etat"),
                     QObject::tr("verifier etat\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else if (nom_malade=="" )
     {
         QMessageBox::critical(nullptr, QObject::tr("problem nom_malade"),
                     QObject::tr("verifier nom_malade\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
   else
     {Fiche_animal a(id,poid,taille,nbr,id_animal,date,etat,nom_malade);

         a.ajouter();
         addToHistory("ajout","d'une fiche animal",ui->lineEdit_id_Fiche_animal->text());
          ui->tableView_2->setModel(a.afficher());
          ui->listView->setModel(afficherHistorique());


          bool test=a.ajouter();
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                       QObject::tr("ajout successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_2->setModel(a.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                       QObject::tr("ajout failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void Animal::on_Supprimer_fiche_clicked()
{
    Fiche_animal a(1,1,1,1,1,"","","");
      a.supprimer()->removeRow(ui->tableView_2->currentIndex().row());
      addToHistory("suppression","d'une fiche animal ",ui->tableView_2->currentIndex().data().toString());

          ui->tableView_2->setModel(a.afficher());
          ui->listView->setModel(afficherHistorique());

          ui->tableView_2->setModel(a.afficher());
}

void Animal::on_PDF_clicked()
{
    QSqlQueryModel model;
       model.setQuery("SELECT * FROM FICHE_ANIMAL");

        QString html = "<table  border='2'> <thead> <tr> <th>#</th> <th>Poid</th> <th>Taille</th> <th>NBR consultation</th> <th> ID Animal</th> <th> Date Vacc</th> <th> Etat</th><th> Nom Maladie </th>  </tr> </thead><tbody > ";


       for (int i = 0; i < model.rowCount(); ++i) {

           QString id = model.record(i).value("ID").toString();
                    QString poid = model.record(i).value("POID").toString();
                             QString taille = model.record(i).value("TAILLE").toString();
                              QString NBR_CONSULTATION = model.record(i).value("NBR_CONSULTATION").toString();
                                QString ID_ANNIMAL = model.record(i).value("ID_ANNIMAL").toString();
                                  QString DATE_VACC = model.record(i).value("DATE_VACC").toString();
                                          QString ETAT = model.record(i).value("ETAT").toString();
           QString name = model.record(i).value("NOM_MALADE").toString();
html += "<tr > <td>"+id+"</td> <td>"+poid+"</td> <td>"+taille+"</td><td>"+NBR_CONSULTATION+"</td><td>"+DATE_VACC+"</td><td>"+DATE_VACC+"</td><td>"+ETAT+"</td> <td>"+name+"</td></tr>";
       }
    html+="</tbody></table>";

      QTextDocument document;
      document.setHtml(html);

      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("Fiche.pdf");

      document.print(&printer);
}

void Animal::on_Supprimer_clicked()
{
    Anim a(1,1,1,"","","","");
    a.supprimer()->removeRow(ui->tableView->currentIndex().row());

    addToHistory("suppression","d'un animal",ui->tableView->currentIndex().data().toString());


        ui->tableView->setModel(a.afficher());
        ui->listView->setModel(afficherHistorique());

        ui->tableView->setModel(a.afficher());
}

void Animal::on_Afficher_clicked()
{
    Anim a(1,1,1,"","","","");
    ui->tableView->setModel(a.afficher());
}

void Animal::on_Tr_Animal_clicked()
{
    Anim a(1,1,1,"","","","");
    ui->tableView->setModel(a.tri(ui->tableView->currentIndex().column()));
}

void Animal::on_Ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
     int age=ui->lineEdit_age->text().toInt();
           float prix = ui->lineEdit_prix->text().toFloat();
       QString nom = ui->lineEdit_nom->text();
       QString race = ui->lineEdit_race->text();
       QString sexe = ui->lineEdit_sexe->text();
       QString date_achat = ui->date_achat->text();
       if (id < 0 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem id"),
                       QObject::tr("verifier id\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (age < 0 || age > 50 )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem age"),
                       QObject::tr("verifier age\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
      else  if (prix < 0  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem prix"),
                       QObject::tr("verifier prix\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (nom==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                       QObject::tr("verifier nom\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (race==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem race"),
                       QObject::tr("verifier race\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else if (sexe==""  )
       {
           QMessageBox::critical(nullptr, QObject::tr("problem sexe"),
                       QObject::tr("verifier sexe\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {

           Anim a(id,age,prix,nom,race,sexe,date_achat);




                a.ajouter();
                addToHistory("ajout","d'un animal",ui->lineEdit_id->text());



               ui->tableView->setModel(a.afficher());
               ui->listView->setModel(afficherHistorique());
           }


            bool test=a.ajouter();
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                         QObject::tr("ajout successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView->setModel(a.afficher());
                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                         QObject::tr("ajout failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }






void Animal::on_txt_recherche_animal_textChanged(const QString &arg1)
{
    Anim c(1,1,1,"","","","");
         c.cleartable(ui->tableView);
         QString cas =ui->txt_recherche_animal->text();
         c.rechercher(ui->tableView,cas);

         if(ui->txt_recherche_animal->text().isEmpty())
         {
             ui->tableView->setModel(c.afficher());
         }
}

void Animal::on_Afficher_Fiche_clicked()
{
    Fiche_animal a(1,1,1,1,1,"","","");

          ui->tableView_2->setModel(a.afficher());
}

void Animal::on_pushButton_im_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tableView->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void Animal::on_pushButton_clicked()
{
    QString link="https://www.google.com";
    QDesktopServices::openUrl(QUrl (link)) ;
}
//history

void Animal::addToHistory(QString action, QString type, QString id)
{

    QSqlQuery query1;
    query1.prepare("select * from history where (TO_CHAR(DATE_ACTIVITE_HISTORIQUE,'dd/mm/yyyy') = TO_CHAR(sysdate,'dd/mm/yyyy'))");
    query1.exec();

    QSqlQuery query,qry;
    QString date=QDateTime::currentDateTime().toString("dddd, dd MMMM yyyy");
    QString date1=QDateTime::currentDateTime().toString("dd/MM/yy");
    QString time=QDateTime::currentDateTime().toString("hh:mm");
    QString activity;

    activity="\n    "+date1+"   -   "+time+" \t    "+ action +" "+type+" d'identifiant:  "+id+" \n";

          query.prepare("INSERT INTO history (activity) VALUES (:activity)");
          query.bindValue(":activity", activity);

    query.exec();

    activity="\n\t\t\t\t"+date+"\n";
/*
    if(!query1.next()) //if 1 ere activité du jour
    {
           query.prepare("INSERT INTO history (activity) VALUES (:activity)");
           query.bindValue(":activity", activity);
    qDebug() << "test11111";
    query.exec();

    }else
    {
        qDebug() << "test22222";

           query.prepare("delete from history where (activity = :activity) ");
           query.bindValue(":activity", activity);
           query.exec();



           qry.prepare("INSERT INTO history (activity,DATE_ACTIVITE_HISTORIQUE) VALUES (:activity, sysdate+(1/86400*60))");
           qry.bindValue(":activity", activity);
           query.exec();

    }
*/
}



//afficher historique

QSqlQueryModel* Animal::afficherHistorique()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    QString historyType="";
    switch (ui->comboBox->currentIndex())
    {
    case 1:  historyType="ajout";break;
    case 2:  historyType="suppression";break;
    }
    //qDebug() << "test";
         query.prepare("SELECT activity FROM history where activity like '%"+historyType+"%'  order by date_activite_historique desc");
         query.exec();
         model->setQuery(query);
    return model;
}




bool Animal::historyDelete()
{
    QSqlQuery query;
    int periode;

    switch (ui->comboBox_2->currentIndex())
    {
    case 0: periode=1; break;
    case 1: periode=7; break;
    case 2: periode=28; break;
    case 3: periode=999999; break;
    }
    //qDebug()<< periode;
    QDateTime lastdate=QDateTime::currentDateTime().addDays(-periode);
    //qDebug()<< lastdate;


    query.prepare("Delete from history where date_activite_historique > :lastdate ");
    query.bindValue(":lastdate",lastdate);
    //qDebug() << delete_id;

    return query.exec();
}


void Animal::on_comboBox_activated(const QString &arg1)
{
    ui->listView->setModel(afficherHistorique());

}

void Animal::on_pushButton_2_clicked()
{
    bool test=historyDelete();
    if(test){
        QMessageBox::information(this,"Success","suppression terminée");
    ui->listView->setModel(afficherHistorique());
    }
    else{
        QMessageBox::information(this,"Success","suppression non effectuée");
    }
}


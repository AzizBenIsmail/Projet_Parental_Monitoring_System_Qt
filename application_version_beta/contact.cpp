#include "contact.h"
#include "ui_contact.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "prestataire.h"
#include "enfant.h"
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>
#include <QDate>
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
Contact::Contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contact)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Documents/application_version_beta/c.jpg");
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

void Contact::on_pushButton_15_clicked()
{


    int idpres=ui->idpres->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nompres=ui->nompres->text();
        QString prenompres=ui->prenompres->text();
        int salairepres=ui->salairepres->text().toInt();
        QString specialitepres=ui->specialitepres->text();
        QString dateembauchepres=ui->dateembauchepres->text();
        int nbr_heurespres=ui->nbr_heurespres->text().toInt();
        int telpres=ui->telpres->text().toInt();
        QString adressepres=ui->adressepres->text();
        QString sexepres=ui->sexepres->text();
         //prestataire P;
        if (idpres <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem id"),
                                   QObject::tr("verifier id\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else if (nompres <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem nompres"),
                                   QObject::tr("verifier nompres\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
        else if (prenompres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem prenompres"),
                        QObject::tr("verifier prenompres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (salairepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem salairepres"),
                        QObject::tr("verifier salairepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (specialitepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem specialitepres"),
                        QObject::tr("verifier specialitepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (dateembauchepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem dateembauchepres"),
                        QObject::tr("verifier dateembauchepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (nbr_heurespres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem nbr_heurespres"),
                        QObject::tr("verifier nbr_heurespres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (telpres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem telpres"),
                        QObject::tr("verifier telpres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (adressepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem adressepres"),
                        QObject::tr("verifier adressepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (sexepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem sexepres"),
                        QObject::tr("verifier sexepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       prestataire P(idpres,nompres,prenompres,salairepres,specialitepres,dateembauchepres,nbr_heurespres,telpres,adressepres,sexepres);

        bool test=P.Ajouter_pres();
             if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff->setModel(P.afficher_pres());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Contact::on_pushButton_2_clicked()
{
    int idpres=ui->idpres->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nompres=ui->nompres->text();
        QString prenompres=ui->prenompres->text();
        int salairepres=ui->salairepres->text().toInt();
        QString specialitepres=ui->specialitepres->text();
        QString dateembauchepres=ui->dateembauchepres->text();
        int nbr_heurespres=ui->nbr_heurespres->text().toInt();
        int telpres=ui->telpres->text().toInt();
        QString adressepres=ui->adressepres->text();
        QString sexepres=ui->sexepres->text();
        if (idpres <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem id"),
                                   QObject::tr("verifier id\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else if (nompres <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem nompres"),
                                   QObject::tr("verifier nompres\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
        else if (prenompres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem prenompres"),
                        QObject::tr("verifier prenompres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (salairepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem salairepres"),
                        QObject::tr("verifier salairepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (specialitepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem specialitepres"),
                        QObject::tr("verifier specialitepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (dateembauchepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem dateembauchepres"),
                        QObject::tr("verifier dateembauchepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (nbr_heurespres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem nbr_heurespres"),
                        QObject::tr("verifier nbr_heurespres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (telpres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem telpres"),
                        QObject::tr("verifier telpres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (adressepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem adressepres"),
                        QObject::tr("verifier adressepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (sexepres <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem sexepres"),
                        QObject::tr("verifier sexepres\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       prestataire P(idpres,nompres,prenompres,salairepres,specialitepres,dateembauchepres,nbr_heurespres,telpres,adressepres,sexepres);

        bool test=P.modifier_pres(idpres);
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("modifier avec succes"),
                                     QObject::tr("modifier successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff->setModel(P.afficher_pres());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("modifier errer"),
                                     QObject::tr("modifier failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void Contact::on_pushButton_3_clicked()
{
    {
        prestataire P1;
        P1.setidpres(ui->lineEdit_SP->text().toInt());
        bool test;
        test=P1.Supprime_pres(P1.getidpres());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_aff->setModel(P1.afficher_pres());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void Contact::on_pushButton_4_clicked()
{

    prestataire P(1,"","",1,"","",1,1,"","");
      // e.cleartable(ui->tableView_aff);
       QString cas =ui->lineEdit_r->text();
       P.rechercher(ui->tableView_aff,cas);

       if(ui->lineEdit_r->text().isEmpty())
       {
           ui->tableView_aff->setModel(P.afficher_pres());
       }
}

void Contact::on_pushButton_14_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tableView_aff_2->model()->rowCount();
            const int columnCount = ui->tableView_aff_2->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tableView_aff_2->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView_aff_2->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_aff_2->isColumnHidden(column)) {
                        QString data = ui->tableView_aff_2->model()->data(ui->tableView_aff_2->model()->index(row, column)).toString().simplified();
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

void Contact::on_pushButton_11_clicked()
{
    prestataire P1;

        ui->tableView_aff->setModel(P1.afficher_pres());
}



void Contact::on_pushButton_ae_clicked()
{

    int id=ui->id->text().toInt();
       // QString date_naissance=ui->date_naissance->date();
        QString nom_prenom=ui->nom_prenom->text();
        QString etat_psycologique=ui->etat_psycologique->text();
        QString talent=ui->talent->text();
        QString sexe=ui->sexe->text();
        if (id <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem id"),
                                   QObject::tr("verifier id\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else if (nom_prenom <= 0 )
                   {
                       QMessageBox::critical(nullptr, QObject::tr("problem nom_prenom"),
                                   QObject::tr("verifier nom_prenom\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
        else if (etat_psycologique <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem etat_psycologique"),
                        QObject::tr("verifier etat_psycologique\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (talent <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem talent"),
                        QObject::tr("verifier talent\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (sexe <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem sexe"),
                        QObject::tr("verifier sexe\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
         enfant E(id,nom_prenom,etat_psycologique,talent,sexe);
        bool test=E.Ajouter();
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_aff_2->setModel(E.afficher());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Contact::on_pushButton_me_clicked()
{

    int id=ui->id->text().toInt();
          // QString date_naissance=ui->date_naissance->date();
           QString nom_prenom=ui->nom_prenom->text();
           QString etat_psycologique=ui->etat_psycologique->text();
           QString talent=ui->talent->text();
           QString sexe=ui->sexe->text();

           if (id <= 0 )
                      {
                          QMessageBox::critical(nullptr, QObject::tr("problem id"),
                                      QObject::tr("verifier id\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                      }
                      else if (nom_prenom <= 0 )
                      {
                          QMessageBox::critical(nullptr, QObject::tr("problem nom_prenom"),
                                      QObject::tr("verifier nom_prenom\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

                      }
           else if (etat_psycologique <= 0 )
           {
               QMessageBox::critical(nullptr, QObject::tr("problem etat_psycologique"),
                           QObject::tr("verifier etat_psycologique\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else if (talent <= 0 )
           {
               QMessageBox::critical(nullptr, QObject::tr("problem talent"),
                           QObject::tr("verifier talent\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else if (sexe <= 0 )
           {
               QMessageBox::critical(nullptr, QObject::tr("problem sexe"),
                           QObject::tr("verifier sexe\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }

            enfant E(id,nom_prenom,etat_psycologique,talent,sexe);
           bool test=E.modifier(id);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_2->setModel(E.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void Contact::on_pushButton_se_clicked()
{
    {
         enfant e1;
        e1.setid(ui->lineEdit_idSE->text().toInt());
        bool test;
        test=e1.Supprime(e1.getid());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_aff_2->setModel(e1.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    }

}

void Contact::on_pushButton_ten_clicked()
{
      ui->tableView_aff_2->setModel(e.afficher_nom_prenom());
}

void Contact::on_pushButton_ace_clicked()
{
    enfant e1;

         ui->tableView_aff_2->setModel(e1.afficher());
}



void Contact::on_pushButton_acp_clicked()
{
    prestataire P1;

        ui->tableView_aff->setModel(P1.afficher_pres());
}

void Contact::on_pushButton_13_clicked()
{
      ui->tableView_aff_2->setModel(e.afficher_sexe());
}

void Contact::on_pushButton_PDFE_clicked()
{
    QSqlQueryModel model;
       model.setQuery("SELECT * FROM enfant");

        QString html = "<table  border='1'> <thead> <tr> <th>+</th> <th>nom_prenom</th> <th>etat_psycologique</th> <th>talent</th> <th> sexe</th> <th> id</th> <th> Etat</th><th> Nom Maladie </th>  </tr> </thead><tbody > ";


       for (int i = 0; i < model.rowCount(); ++i) {
           /*this->id=id;
          // this-> date_naissance= date_naissance;
           this->nom_prenom=nom_prenom;
           this->etat_psycologique=etat_psycologique;
           this->talent=talent;
           this->sexe=sexe;*/
           QString id = model.record(i).value("id").toString();
                    QString nom_prenom = model.record(i).value("nom_prenom").toString();
                             QString etat_psycologique = model.record(i).value("etat_psycologique").toString();
                              QString talent = model.record(i).value("talent").toString();
                                QString sexe = model.record(i).value("sexe").toString();

           QString name = model.record(i).value("nom_prenom").toString();
html += "<tr > <td>"+id+"</td> <td><h2>"+nom_prenom+"</h2></td> <td><h2>"+etat_psycologique+"</h2></td><td><h2>"+talent+"</h2></td><td><h2>"+sexe+"</h2></td></tr>";



       }
    html+="</tbody></table>";

      QTextDocument document;
      document.setHtml(html);

      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName("Fiche.pdf");

     document.print(&printer);
}

void Contact::on_lineEdit_idSE_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM enfant WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_idSE->clear();}
}

void Contact::on_lineEdit_SP_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM prestataire WHERE idpres  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_SP->clear();}
}

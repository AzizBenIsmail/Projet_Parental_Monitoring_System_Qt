#include "sante.h"
#include "ui_sante.h"
#include "menu.h"
#include <QPixmap>
#include "QMessageBox"
#include"suivi.h"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <medicament.h>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>

#include "mailing.h"


#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include "notification.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>

Sante::Sante(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sante)
{
    ui->setupUi(this);
    ui->tableView_aff->setModel(e.afficher());
    ui->tableView_aff_m->setModel(m.afficher());
    ui->_id_ajouter->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_idS->setValidator(new QIntValidator(0,9999999,this));

    QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/s.jpg");
    int w=ui->label_ph->width();
    int h=ui->label_ph->height();
    ui->label_ph->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    int a=ui->label_ph_2->width();
    int b=ui->label_ph_2->height();
    ui->label_ph_2->setPixmap(pix.scaled(a,b,Qt::KeepAspectRatio));
    int aa=ui->label_ph3->width();
    int bb=ui->label_ph3->height();
    ui->label_ph3->setPixmap(pix.scaled(aa,bb,Qt::KeepAspectRatio));


    QVector<float> x;

         x=e.stat();
        // QBarSeries *series = new QBarSeries()
                  QBarSet *set0 = new QBarSet("100-500");
                 QBarSet *set1 = new QBarSet("500-1000");
                 QBarSet *set2 = new QBarSet("1000-2000");
                 QBarSet *set3 = new QBarSet("+2000");

                 *set0 << x[0];
                 *set1 << x[1] ;
                 *set2 << x[2] ;
                 *set3 << x[3] ;
         series->append(set0);
         series->append(set1);
         series->append(set2);
         series->append(set3);


       //  QChart *chart = new QChart();

         //chart->legend()->hide();
         chart->addSeries(series);
         chart->createDefaultAxes();
         chart->setTitle("Statistique des salaires");


         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);



         ui->_id_m->setPlaceholderText("ID");
         ui->Prix->setPlaceholderText("Quantité");
         ui->_Quantite->setPlaceholderText("Prix");
         ui->lineEdit_idS_m->setPlaceholderText("ID :");
         ui->_id_m_2->setPlaceholderText("ID :");


         ui->_id_ajouter->setPlaceholderText("ID");
         ui->_taille->setPlaceholderText("Taille");
         ui->_poid->setPlaceholderText("Poids");
         ui->_tenstion->setPlaceholderText("Tension");
         ui->Psearch_5->setPlaceholderText("Chercher");
         ui->id_modify->setPlaceholderText("ID :");
         ui->lineEdit_idS->setPlaceholderText("ID :");




}
Sante::~Sante()
{
    delete ui;
}

void Sante::on_pushButton_clicked()
{
    hide();
    Menu m;
    m.exec();
}




void Sante::on_pushButton_Q_clicked()
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


void Sante::on_pushButton_Sui_clicked()
{
    suivi e1;
    e1.setid(ui->lineEdit_idS->text().toInt());
    bool test;
    test=e1.Supprime(e1.getid());
    if(e1.getid()==8)
     {     QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                 QObject::tr("Id n'excete pas.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(e1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_pushButton_ajout_clicked()
{

        int id=ui->_id_ajouter->text().toInt();
            double taille=ui->_taille->text().toDouble();
            double poid=ui->_poid->text().toDouble();
           double tension=ui->_tenstion->text().toDouble();
            QString date=ui->_date->text();

            if (id <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem id"),
                            QObject::tr("verifier id\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (taille <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                            QObject::tr("verifier taille\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
           else  if (poid <= 0  )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                            QObject::tr("verifier poid\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (tension <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem tension"),
                            QObject::tr("verifier tension\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (date== ""  )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem date"),
                            QObject::tr("verifier date\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
            {
                suivi E(id,taille,poid,tension,date);
                bool test=E.Ajouter();
              if(test)
               {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                             QObject::tr("ajout successful.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->tableView_aff->setModel(E.afficher());
                  QString okd="";

                  notification ok;
                    ok.notification_ajout(okd);
                         }
                             else
                                 QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                             QObject::tr("ajout failed.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);
            }


}

void Sante::on_pushButton_ajout_m_clicked()
{
    int id=ui->_id_m->text().toInt();
        double Quantite=ui->_Quantite->text().toDouble();
        double Prix=ui->Prix->text().toDouble();
        QString date=ui->_date_m->text();
        if (id <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem id"),
                        QObject::tr("verifier id\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (Quantite < 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem age"),
                        QObject::tr("verifier age\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       else  if (Prix < 0  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem prix"),
                        QObject::tr("verifier prix\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (date==""  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem nom"),
                        QObject::tr("verifier nom\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            MEDICAMENT m(id,Quantite,Prix,date);
            bool test=m.Ajouter();
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                         QObject::tr("ajout successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_aff_m->setModel(m.afficher());

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                         QObject::tr("ajout failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void Sante::on_pushButton_Sui_m_clicked()
{
    MEDICAMENT m1;
    m1.setid(ui->lineEdit_idS_m->text().toInt());
    bool test;
    test=m1.Supprime(m1.getid());
    if(m1.getid()==8)
     {     QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                 QObject::tr("Id n'excete pas.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_m->setModel(m1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup error"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_Modifier_clicked()
{
    int id=ui->id_modify->text().toInt();
        double taille=ui->_taille->text().toDouble();
        double poid=ui->_poid->text().toDouble();
       double tension=ui->_tenstion->text().toDouble();
        QString date=ui->_date->text();

        if (id <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem id"),
                        QObject::tr("verifier id\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (taille <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem taille"),
                        QObject::tr("verifier taille\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
       else  if (poid <= 0  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem poid"),
                        QObject::tr("verifier poid\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (tension <= 0 )
        {
            QMessageBox::information(nullptr, QObject::tr("problem tension"),
                        QObject::tr("verifier tension\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (date== ""  )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem date"),
                        QObject::tr("verifier date\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
        suivi m(id,taille,poid,tension,date);
        bool test=m.modifier(id,date);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff->setModel(m.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
      }
}
void Sante::on_Tri_IdE_clicked()
{
    ui->tableView_aff->setModel(e.afficher_id());
}

void Sante::on_Tri_Taille_clicked()
{
    ui->tableView_aff->setModel(e.afficher_taille());
}

void Sante::on_Tri_Poid_clicked()
{
    ui->tableView_aff->setModel(e.afficher_poid());

}


void Sante::on_pushButton_2_clicked()
{
    ui->tableView_aff->setModel(e.test());
}


void Sante::on_pushB_clicked()
{
    bool t;
    t=e.reset();
    if(t)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(e.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_pushB_2_clicked()
{    MEDICAMENT m1;

    bool t1;
    t1=m1.reset();
    if(t1)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_m->setModel(m1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Sante::on_Tri_IdE_2_clicked()
{
    ui->tableView_aff_m->setModel(m.afficher_prix());
}

void Sante::on_Tri_Taille_2_clicked()
{
    ui->tableView_aff_m->setModel(m.afficher_qt());
}
void Sante::on_pushm_clicked()
{
    int id=ui->_id_m_2->text().toInt();
        double Quantite=ui->_Quantite->text().toDouble();
        double Prix=ui->Prix->text().toDouble();
        QString date=ui->_date_m->text();
         if (id <= 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem id"),
                         QObject::tr("verifier id\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else if (Quantite < 0 )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem Quantite"),
                         QObject::tr("verifier taille\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
        else  if (Prix < 0  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem Prix"),
                         QObject::tr("verifier poid\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else if (date== ""  )
         {
             QMessageBox::critical(nullptr, QObject::tr("problem date"),
                         QObject::tr("verifier date\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         {
          MEDICAMENT m1(id,Quantite,Prix,date);
          bool test=m1.modifier(id,date);

         if(test)
          {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                        QObject::tr("modify successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_m->setModel(m.afficher());

                    }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                        QObject::tr("modify failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void Sante::on_pushButton_3_clicked()
{
       ui->tableView_aff_m->setModel(m.recherche_faible());

}

void Sante::on_pushButton_Moyenne_clicked()
{
    ui->tableView_aff_m->setModel(m.recherche_moye());
}


void Sante::on_pushButton_chere_clicked()
{
    ui->tableView_aff_m->setModel(m.recherche_chere());

}
/*
void Sante::on_pushButton_Recherche_clicked()
{       int id=ui->_id_m->text().toInt();
    ui->tableView_aff_m->setModel(m.recherche(id));
}
*/


void Sante::on_pushButton_Actualise_m_clicked()
{
    ui->tableView_aff_m->setModel(m.afficher());

}

void Sante::on_pushButton_Actualise_clicked()
{
    ui->tableView_aff->setModel(e.afficher());
}

void Sante::on_pushButton_enregistre_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_aff->model()->rowCount();
    const int columnCount = ui->tableView_aff->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des suivi </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_aff->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_aff->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_aff->isColumnHidden(column))
            {
                QString data = ui->tableView_aff->model()->data(ui->tableView_aff->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
        "</body>\n"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void Sante::on_Psearch_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM suivi WHERE ID  LIKE'"+arg1+"%' or taille  LIKE'"+arg1+"%' or poid  LIKE'"+arg1+"%' or dat LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView_aff->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_5->clear();}
}

void Sante::on_id_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM suivi WHERE ID  LIKE'"+arg1+"%' or taille  LIKE'"+arg1+"%' or poid  LIKE'"+arg1+"%' or tension LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_5->clear();}
}

void Sante::on_id_modify_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM suivi WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->id_modify->clear();}
}

void Sante::on_lineEdit_idS_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM suivi WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_idS->clear();}
}

void Sante::on__id_m_2_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM MEDICAMENT WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->_id_m_2->clear();}
}

void Sante::on_lineEdit_idS_m_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM MEDICAMENT WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_idS_m->clear();}
}

void Sante::on_pushButton_6_clicked()
{
    ui->tableView_aff->setModel(e.afficher_poidsideal());

}

void Sante::on_pushButton_im_clicked()
{

        QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableView_aff->model()->rowCount();
                const int columnCount = ui->tableView_aff->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableView_aff->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_aff->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView_aff->isColumnHidden(column)) {
                            QString data = ui->tableView_aff->model()->data(ui->tableView_aff->model()->index(row, column)).toString().simplified();
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

void Sante::on_reload_stat_clicked()
{
    QVector<float> x;
         x=e.stat();





         QBarSeries *series2= new QBarSeries();

         *set0 <<x[0];
         *set1 <<x[1] ;
         *set2 << x[2] ;
         *set3 << x[3] ;


    series2->append(set0);
    series2->append(set1);
    series2->append(set2);
    series2->append(set3);
    chart->removeAllSeries();
     chart->addSeries(series2);
     chartView->update();
}

void Sante::on_pushButton_4_clicked()
{
    Mailing M;
    M.exec();
}





void Sante::on_pushButton_5_clicked()
{
  QTableView *table;
        table = ui->tableView_aff_m;

           QString filters("CSV files (.csv);;All files (.*)");
           QString defaultFilter("CSV files (*.csv)");
           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                              filters, &defaultFilter);
           QFile file(fileName);

           QAbstractItemModel *model =  table->model();
           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
               QTextStream data(&file);
               QStringList strList;
               for (int i = 0; i < model->columnCount(); i++) {
                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                   else
                       strList.append("");
               }
               data << strList.join(";") << "\n";
               for (int i = 0; i < model->rowCount(); i++) {
                   strList.clear();
                   for (int j = 0; j < model->columnCount(); j++) {

                       if (model->data(model->index(i, j)).toString().length() > 0)
                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") + "\n";
               }
               file.close();
               QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
           }
}


void Sante::on_pushButton_7_clicked()
{
    QString link="https://www.worldometers.info/coronavirus/";
    QDesktopServices::openUrl(QUrl (link)) ;
}

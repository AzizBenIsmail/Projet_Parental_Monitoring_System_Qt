#include "programme.h"
#include "ui_programme.h"
#include "fourniture.h"
#include"activite.h"
#include "menu.h"
#include <QPixmap>
#include <QMessageBox>
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
programme::programme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::programme)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/MSI/OneDrive/Bureau/application_version_beta/pro.jpg");
    int w=ui->label_a->width();
    int h=ui->label_a->height();
    ui->label_a->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->tableView_aff_h->setModel(f.afficher());
    ui->tableView_aff_ha->setModel(a.afficher());
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

void programme::on_pushButton_ajout_m_clicked()
{
    int id=ui->_id_h->text().toInt();
    int ref=ui->ref_h->text().toInt();
        double Quantite=ui->Qunatite_h->text().toDouble();
        double Prix=ui->prix_hay->text().toDouble();
        QString date=ui->_date_h->text();
        if (id <= 0 )
        {
            QMessageBox::critical(nullptr, QObject::tr("problem id"),
                        QObject::tr("verifier id\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (Quantite < 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("problem quantite"),
                        QObject::tr("verifier quantite\n"
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
            QMessageBox::critical(nullptr, QObject::tr("problem date"),
                        QObject::tr("verifier date\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            Fourniture f(id,ref,Quantite,Prix,date);
            bool test=f.Ajouter();
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                         QObject::tr("ajout successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_aff_h->setModel(f.afficher());

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                         QObject::tr("ajout failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void programme::on_pushB_2_clicked()
{
    bool t;
    t=f.reset();
    if(t)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_h->setModel(f.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}


void programme::on_pushButton_Sui_m_clicked()
{
    Fourniture e1;
    e1.setid(ui->lineEdit_idS_h->text().toInt());
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
ui->tableView_aff_h->setModel(e1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}


void programme::on_pushm_clicked()
{
    int id=ui->_id_h_2->text().toInt();
    int ref=ui->ref_h->text().toInt();
        double Quantite=ui->Qunatite_h->text().toDouble();
        double Prix=ui->prix_hay->text().toDouble();
        QString date=ui->_date_h->text();


            Fourniture f(id,ref,Quantite,Prix,date);        bool test=f.modifier(id,date);
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_h->setModel(f.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void programme::on_pushButton_enregistre_p_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_aff_h->model()->rowCount();
    const int columnCount = ui->tableView_aff_h->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste Des Fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_aff_h->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_aff_h->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_aff_h->isColumnHidden(column))
            {
                QString data = ui->tableView_aff_h->model()->data(ui->tableView_aff_h->model()->index(row, column)).toString().simplified();
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

void programme::on_Tri_IdE_2_clicked()
{
    ui->tableView_aff_h->setModel(f.afficher_id());

}

void programme::on_Tri_Taille_2_clicked()
{
    ui->tableView_aff_h->setModel(f.afficher_prix());
}
void programme::on_lineEdit_idS_h_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM Fourniture WHERE ID  LIKE'"+arg1+"%'" );
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit_idS_h->clear();}
}

void programme::on__id_h_2_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM Fourniture WHERE ID  LIKE'"+arg1+"%'" );
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->_id_h_2->clear();
}
}


void programme::on_Psearch_4_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM Fourniture WHERE ID  LIKE'"+arg1+"%' or REF  LIKE'"+arg1+"%' or PRIX  LIKE'"+arg1+"%' or QUANTITE LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView_aff_h->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_4->clear();}
}

void programme::on_pushButton_Actualise_h_clicked()
{
     ui->tableView_aff_h->setModel(f.afficher());
}

void programme::on_pushButton_ajout_a_clicked()
{
    int id=ui->id_ha->text().toInt();
    int duree=ui->duree_ha->text().toInt();
       QString nom_Activite=ui->nom_Activite_ha->text();
        QString type=ui->type_ha->text();
        QString date=ui->date_ha->text();
            Activite a(id,duree,nom_Activite,type,date);
            bool test=a.Ajouter();
          if(test)
           {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                         QObject::tr("ajout successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_aff_ha->setModel(a.afficher());

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                         QObject::tr("ajout failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void programme::on_pushButton_Sui_ha_clicked()
{
    Activite e1;
    e1.setid(ui->lineEdit_idS_ha->text().toInt());
    bool test;
    test=e1.Supprime(e1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_ha->setModel(e1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void programme::on_Modifier_a_clicked()
{
    int id=ui->id_ha->text().toInt();
    int duree=ui->duree_ha->text().toInt();
         QString nom_Activite=ui->nom_Activite_ha->text();
        QString type=ui->type_ha->text();
        QString date=ui->date_ha->text();


            Activite a(id,duree,nom_Activite,type,date);        bool test=a.modifier();
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                       QObject::tr("modify successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_aff_ha->setModel(a.afficher());

                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                       QObject::tr("modify failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

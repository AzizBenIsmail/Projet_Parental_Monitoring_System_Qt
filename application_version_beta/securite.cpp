#include "securite.h"
#include "ui_securite.h"
#include "menu.h"
#include <QPixmap>
#include "QString"
#include <QMessageBox>
#include "boutique.h"
#include "mailing.h"
#include "boutique.h"
#include "vetement.h"
#include<iostream>
#include <QtMultimedia/QSound>
#include <QPixmap>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QLineEdit>
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
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>

Securite::Securite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Securite)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/proj-parental-monitoring-system-2A21-G6-main/application_version_beta/5.jpg");
    int w=ui->label_p->width();
    int h=ui->label_p->height();
    ui->label_p->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->afficheb->setModel(B.afficher());
    ui->affichev->setModel(V.afficher());
    /*ref&taille&prix pattern*/
        ui->ref->setValidator(new QIntValidator(0,9999,this));
        QRegularExpression rx2("\\b[0-9]{6}\\b",
        QRegularExpression::CaseInsensitiveOption);
        ui->prix->setValidator(new QRegularExpressionValidator(rx2, this));
        QRegularExpression rx3("\\b[A-Z0-9]{1,5}\\b",
        QRegularExpression::CaseInsensitiveOption);
        ui->taille->setValidator(new QRegularExpressionValidator(rx3, this));
                                 /*maxlenght*/
                        ui->saison->setMaxLength(15);
                        ui->genre->setMaxLength(12);
                        ui->type->setMaxLength(25);
                        ui->marque->setMaxLength(50);

                        /*placeholder*/
         ui->ref->setPlaceholderText("Reference");
         ui->saison->setPlaceholderText("Saison");
         ui->genre->setPlaceholderText("Genre");
         ui->type->setPlaceholderText("Type de Vetement");
         ui->taille->setPlaceholderText("Taille");
         ui->marque->setPlaceholderText("Marque");
         ui->prix->setPlaceholderText("Prix");
         ui->nomsuppv->setPlaceholderText("Ref :");
         ui->refmodif->setPlaceholderText("Ref :");
         ui->findv->setPlaceholderText("Chercher celon :");


                         /*tel&id pattern*/
        ui->id->setValidator(new QIntValidator(0,999,this));
        QRegularExpression rx1("\\b[0-9]{8}\\b",
        QRegularExpression::CaseInsensitiveOption);
        ui->tel->setValidator(new QRegularExpressionValidator(rx1, this));


                        /*email pattern*/
        QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z.-]+\\.[A-Z]{2,4}\\b",
        QRegularExpression::CaseInsensitiveOption);
        ui->mail->setValidator(new QRegularExpressionValidator(rx, this));
                          /*maxlenght*/
                   ui->nom->setMaxLength(20);
                   ui->adr->setMaxLength(50);
                   ui->mail->setMaxLength(50);
                      /*placeholder*/
       ui->id->setPlaceholderText("Id Boutique");
       ui->nom->setPlaceholderText("Nom Complet");
       ui->adr->setPlaceholderText("Adresse Local");
       ui->tel->setPlaceholderText("N° Telephone");
       ui->mail->setPlaceholderText("Contact@mail.com");
       ui->nomsupp->setPlaceholderText("Id :");
       ui->idmodif->setPlaceholderText("Id :");
     //  ui->mailing->setPlaceholderText("Mettre Votre E-mail içi :");
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

void Securite::on_ajoutb_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString adr=ui->adr->text();
    QString mail=ui->mail->text();
    int tel=ui->tel->text().toInt();
    boutique B(id,nom,adr,mail,tel);
    bool test=B.ajouter();

  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("Boutique est ajoutée"),
                                 QObject::tr("Ajout Terminer.\n"
                                             "Cliquer Ok pour Continuer."), QMessageBox::Ok);
      ui->afficheb->setModel(B.afficher());
      {  /*clear after ajouter*/
           ui->id->clear();
           ui->nom->clear();
           ui->adr->clear();
           ui->tel->clear();
           ui->mail->clear();}

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Boutique N'est pas Ajoutée"),
                                 QObject::tr("Echec D'Ajout.\n"
                                             "Cliquer Retry Pour Ajouter à Nouveau "), QMessageBox::Retry);
}

void Securite::on_annulerb_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->adr->clear();
    ui->tel->clear();
    ui->mail->clear();
}

void Securite::on_actualiserb_clicked()
{
    ui->afficheb->setModel(B.afficher());
}

void Securite::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->afficheb->model()->rowCount();
    const int columnCount = ui->afficheb->model()->columnCount();

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
        if (!ui->afficheb->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->afficheb->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->afficheb->isColumnHidden(column))
            {
                QString data = ui->afficheb->model()->data(ui->afficheb->model()->index(row, column)).toString().simplified();
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

void Securite::on_modifierb_clicked()
{
    int id=ui->idmodif->text().toInt();
    QString nom=ui->nom->text();
    QString adr=ui->adr->text();
    int tel=ui->tel->text().toInt();
    QString mail=ui->mail->text();


        boutique a(id,nom,adr,mail,tel);
        bool test=a.modifier(id);
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                   QObject::tr("modify successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->afficheb->setModel(a.afficher());

               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                   QObject::tr("modify failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void Securite::on_reset_clicked()
{
    bool test1;
    test1=B.reset();
    if(test1)
     {    QMessageBox::information(nullptr, QObject::tr("toutes les boutiques ont été  Supprimées"),
                                   QObject::tr("Liste est Vide.\n"
                                                "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->afficheb->setModel(B.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression echoué"),
                                   QObject::tr("Liste n'est pas vide .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);

}

void Securite::on_suppb_clicked()
{
    boutique B1;
    B1.setid(ui->nomsupp->text().toInt());
    bool test;
    test=B1.supprimer(B1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("Suppression effectué "),
                                   QObject::tr("Boutique a été Supprimée .\n"
                                               "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->afficheb->setModel(B1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression Echoué"),
                                   QObject::tr("Boutique n'a pas été  Supprimée .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);

}

void Securite::on_actualiserv_clicked()
{
    ui->affichev->setModel(V.afficher());
}

void Securite::on_ajouterv_clicked()
{
    int ref=ui->ref->text().toInt();
    QString saison=ui->saison->text();
    QString genre=ui->genre->text();
    QString type=ui->type->text();
    QString taille=ui->taille->text();
    QString marque=ui->marque->text();
    float prix=ui->prix->text().toInt();
    vetement V(ref,saison,genre,type,taille,marque,prix);
    bool test=V.ajouter();

  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("vetement est ajoutée"),
                                 QObject::tr("Ajout Terminer.\n"
                                             "Cliquer Ok pour Continuer."), QMessageBox::Ok);
      ui->affichev->setModel(V.afficher());
      {  /*clear after ajouter*/
          ui->ref->clear();
          ui->saison->clear();
          ui->genre->clear();
          ui->type->clear();
          ui->taille->clear();
          ui->marque->clear();
          ui->prix->clear();}

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Boutique N'est pas Ajoutée"),
                                 QObject::tr("Echec D'Ajout.\n"
                                             "Cliquer Retry Pour Ajouter à Nouveau "), QMessageBox::Retry);
}

void Securite::on_annulerv_clicked()
{
    ui->ref->clear();
    ui->saison->clear();
    ui->genre->clear();
    ui->type->clear();
    ui->taille->clear();
    ui->marque->clear();
    ui->prix->clear();
}

void Securite::on_triref_clicked()
{
    ui->affichev->setModel(V.afficher_ref());
}

void Securite::on_triprix_clicked()
{
    ui->affichev->setModel(V.afficher_prix());
}

void Securite::on_modifierv_clicked()
{
    int ref=ui->refmodif->text().toInt();
    QString saison=ui->saison->text();
    QString genre=ui->genre->text();
    QString type=ui->type->text();
    QString taille=ui->taille->text();
    QString marque=ui->marque->text();
    float prix=ui->prix->text().toFloat();



        vetement e(ref,saison,genre,type,taille,marque,prix);
        bool test=e.modifier(ref);
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                   QObject::tr("modify successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->affichev->setModel(e.afficher());

               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                   QObject::tr("modify failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Securite::on_resetv_clicked()
{
    bool test1;
    test1=V.reset();
    if(test1)
     {    QMessageBox::information(nullptr, QObject::tr("toutes les boutiques ont été  Supprimées"),
                                   QObject::tr("Liste est Vide.\n"
                                                "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->affichev->setModel(V.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression echoué"),
                                   QObject::tr("Liste n'est pas vide .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);
}

void Securite::on_suppv_clicked()
{
    vetement V1;
    V1.setref(ui->nomsuppv->text().toInt());
    bool test;
    test=V1.supprimer(V1.getref());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("Suppression effectué "),
                                   QObject::tr("Boutique a été Supprimée .\n"
                                               "Cliquer OK Pour Verifier."), QMessageBox::Ok);
ui->affichev->setModel(V1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("Suppression Echoué"),
                                   QObject::tr("Boutique n'a pas été  Supprimée .\n"
                                               "Cliquer OK Pour Continuer."), QMessageBox::Ok);
}

void Securite::on_findv_textChanged(const QString &arg1)
{

    QSqlQueryModel *model= new QSqlQueryModel();
       QSqlQuery   *query= new QSqlQuery();
       query->prepare("SELECT * FROM vetement WHERE ref  LIKE'"+arg1+"%' or prix  LIKE'"+arg1+"%' or marque  LIKE'"+arg1+"%' or type LIKE'"+arg1+"%' ");
        query->exec();
        if (query->next()) {
        model->setQuery(*query);
        ui->affichev->setModel(model);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                            QObject::tr("NO MATCH FOUND !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->findv->clear();}
}

void Securite::on_pushButton_4_clicked()
{
    Mailing M;
    M.exec();
}

void Securite::on_idmodif_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM BOUTIQUE WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void Securite::on_nomsupp_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM BOUTIQUE WHERE ID  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void Securite::on_refmodif_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM vetement WHERE ref  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void Securite::on_nomsuppv_textChanged(const QString &arg1)
{
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM vetement WHERE ref  LIKE'"+arg1+"%'");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

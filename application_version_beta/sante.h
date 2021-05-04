#ifndef SANTE_H
#define SANTE_H
#include"suivi.h"
#include <QDialog>
#include "medicament.h"
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QDate>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QNetworkAccessManager>
#include <QNetworkReply>
namespace Ui {
class Sante;
}

class Sante : public QDialog
{
    Q_OBJECT

public:
    explicit Sante(QWidget *parent = nullptr);
    ~Sante();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_Sui_clicked();

    void on_pushButton_ajout_clicked();

    void on_pushButton_ajout_m_clicked();

    void on_pushButton_Sui_m_clicked();

    void on_Modifier_clicked();

    void on_Tri_IdE_clicked();

    void on_Tri_Taille_clicked();

    void on_Tri_Poid_clicked();

    void on_Reset_clicked();

    void on_Reset1_clicked();

    void on_pushB_clicked();

    void on_pushB_2_clicked();

    void on_Tri_IdE_2_clicked();

    void on_Tri_Taille_2_clicked();

    void on_Modifier_2_clicked();

    void on_pushm_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_Moyenne_clicked();

    void on_pushButton_Chaire_clicked();

    void on_pushButton_chere_clicked();

    void on_pushButton_Recherche_clicked();

    void on_pushButton_Actualise_2_clicked();

    void on_pushButton_Actualise_m_clicked();

    void on_pushButton_Actualise_clicked();

    void on_pushButton_enregistre_clicked();

    void on_Psearch_5_textChanged(const QString &arg1);

    void on_lineEdit_idS_textChanged(const QString &arg1);

    void on__id_textChanged(const QString &arg1);

    void on_id_textChanged(const QString &arg1);

    void on_id_modify_textChanged(const QString &arg1);

    void on__id_m_2_textChanged(const QString &arg1);

    void on_lineEdit_idS_m_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_im_clicked();

    void on_reload_stat_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_idS_m_textEdited(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Sante *ui;
    suivi e;
    MEDICAMENT m;
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    QBarSet *set0 = new QBarSet("100-500");
   QBarSet *set1 = new QBarSet("500-1000");
   QBarSet *set2 = new QBarSet("1000-2000");
   QBarSet *set3 = new QBarSet("+2000");
};

#endif // SANTE_H

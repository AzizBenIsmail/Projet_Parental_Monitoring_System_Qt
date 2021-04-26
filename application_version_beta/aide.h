#ifndef AIDE_H
#define AIDE_H
#include <QDialog>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDialog>
#include <QMediaPlayer>
#include <QListWidgetItem>

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QDate>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class aide;
}

class aide : public QDialog
{
    Q_OBJECT

public:
    explicit aide(QWidget *parent = nullptr);
    ~aide();

private slots:
    void showTime();
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();


    void on_pushButton_note_clicked();

    void on_pushButton_Cal_clicked();

    void on_pb_envoyer_clicked();

    void on_sav_clicked();

    void on_envoyer_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_Note_clicked();

    void on_pushButton_N_clicked();

private:
    Ui::aide *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;



};

#endif // AIDE_H

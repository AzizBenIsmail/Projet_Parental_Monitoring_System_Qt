#ifndef STATISTICS_H
#define STATISTICS_H
#include <QDialog>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QMainWindow>

namespace Ui {
class statistics;
}

class statistics : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = nullptr);
    ~statistics();

private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H


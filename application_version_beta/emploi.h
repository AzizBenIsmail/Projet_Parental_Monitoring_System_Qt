#ifndef EMPLOI_H
#define EMPLOI_H

#include <QDialog>

namespace Ui {
class emploi;
}

class emploi : public QDialog
{
    Q_OBJECT

public:
    explicit emploi(QWidget *parent = nullptr);
    ~emploi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::emploi *ui;
};

#endif // EMPLOI_H

#ifndef SANTE_H
#define SANTE_H
#include"suivi.h"
#include <QDialog>

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

private:
    Ui::Sante *ui;
    suivi e;
};

#endif // SANTE_H

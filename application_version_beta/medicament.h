#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include "medic.h"
#include <QDialog>

namespace Ui {
class medicament;
}

class medicament : public QDialog
{
    Q_OBJECT

public:
    explicit medicament(QWidget *parent = nullptr);
    ~medicament();

private slots:
    void on_pushButton_R_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_S_clicked();

private:
    Ui::medicament *ui;
    Medic c;
};

#endif // MEDICAMENT_H

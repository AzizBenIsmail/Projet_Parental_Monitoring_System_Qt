#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "fourniture.h"
#include <QDialog>
#include "activite.h"

namespace Ui {
class programme;
}

class programme : public QDialog
{
    Q_OBJECT

public:
    explicit programme(QWidget *parent = nullptr);
    ~programme();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_ajout_m_clicked();

    void on_pushB_2_clicked();

    void on_pushButton_Sui_m_clicked();

    void on_pushm_clicked();

    void on_pushButton_enregistre_p_clicked();

    void on_Tri_IdE_2_clicked();

    void on_Tri_Taille_2_clicked();

    void on_lineEdit_idS_h_textChanged(const QString &arg1);

    void on__id_h_2_textChanged(const QString &arg1);

    void on_Psearch_5_textChanged(const QString &arg1);

    void on_Psearch_4_textChanged(const QString &arg1);

    void on_pushButton_Actualise_clicked();

    void on_pushButton_Actualise_h_clicked();

    void on_pushButton_ajout_a_clicked();

    void on_pushButton_Sui_ha_clicked();

    void on_Modifier_a_clicked();

    void on_pushB_clicked();

private:
    Ui::programme *ui;
    Fourniture f;
    Activite a;
};

#endif // PROGRAMME_H

#ifndef CUISINE_H
#define CUISINE_H
#include "ingr.h"
#include <QDialog>
#include "ingredient.h"

namespace Ui {
class cuisine;
}

class cuisine : public QDialog
{
    Q_OBJECT

public:
    explicit cuisine(QWidget *parent = nullptr);
    ~cuisine();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_ajouter_5_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_suppr_clicked();

    void on_pushButton_modifier_i_clicked();

    void on_tableView_repas_activated(const QModelIndex &index);

    void on_pushButton_trier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_ingr_ajout_clicked();

    void on_ajouteringr_clicked();

    void on_pushButton_modieri_clicked();

    void on_tableView_ingr_activated_activated(const QModelIndex &index);

    void on_modif_ing_clicked();

    void on_pushButton_afficher_ngr_clicked();

    void on_pushButton_suprimer_ingr_clicked();

    void on_pushButton_recherche_ingr_clicked();

    void on_pushButton_trier_ingr_clicked();

    void on_imprim_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cuisine *ui;
    ingr i;
    Ingredient r;
};

#endif // CUISINE_H

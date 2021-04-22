#ifndef ANIMAL_H
#define ANIMAL_H

#include <QDialog>

namespace Ui {
class Animal;
}

class Animal : public QDialog
{
    Q_OBJECT

public:
    explicit Animal(QWidget *parent = nullptr);
    ~Animal();

private slots:
    void on_pushButton_R_clicked();

    void on_pushButton_Q_clicked();

    void on_Ajouter_FICHE_clicked();

    void on_Supprimer_fiche_clicked();

    void on_PDF_clicked();

    void on_Supprimer_clicked();

    void on_Afficher_clicked();

    void on_Tr_Animal_clicked();

    void on_Ajouter_clicked();

    void on_txt_recherche_animal_textChanged(const QString &arg1);

    void on_Afficher_Fiche_clicked();

private:
    Ui::Animal *ui;
};

#endif // ANIMAL_H

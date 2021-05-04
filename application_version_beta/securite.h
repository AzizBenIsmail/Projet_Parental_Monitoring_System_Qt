#ifndef SECURITE_H
#define SECURITE_H
#include"admin.h"
#include <QDialog>
#include "boutique.h"
#include "vetement.h"
namespace Ui {
class Securite;
}

class Securite : public QDialog
{
    Q_OBJECT

public:
    explicit Securite(QWidget *parent = nullptr);

    ~Securite();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

    void on_ajoutb_clicked();

    void on_annulerb_clicked();

    void on_actualiserb_clicked();

    void on_pdf_clicked();

    void on_modifierb_clicked();

    void on_reset_clicked();

    void on_suppb_clicked();

    void on_actualiserv_clicked();

    void on_ajouterv_clicked();

    void on_annulerv_clicked();

    void on_triref_clicked();

    void on_triprix_clicked();

    void on_modifierv_clicked();

    void on_resetv_clicked();

    void on_suppv_clicked();

    void on_findv_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_idmodif_textChanged(const QString &arg1);

    void on_nomsupp_textChanged(const QString &arg1);

    void on_refmodif_textChanged(const QString &arg1);

    void on_nomsuppv_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::Securite *ui;
    boutique B;
    vetement V;
};

#endif // SECURITE_H

#ifndef CONTACT_H
#define CONTACT_H
#include <QMainWindow>
#include "prestataire.h"
#include "enfant.h"
#include <QDialog>


namespace Ui {
class Contact;
}

class Contact : public QDialog
{
    Q_OBJECT

public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_ae_clicked();

    void on_pushButton_me_clicked();

    void on_pushButton_se_clicked();

    void on_pushButton_ten_clicked();

    void on_pushButton_ace_clicked();

    void on_groupBox_2_clicked();

    void on_pushButton_acp_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_PDFE_clicked();

    void on_lineEdit_idSE_textChanged(const QString &arg1);

    void on_lineEdit_SP_textChanged(const QString &arg1);

private:
    Ui::Contact *ui;
    prestataire P;
      enfant e;
};

#endif // CONTACT_H

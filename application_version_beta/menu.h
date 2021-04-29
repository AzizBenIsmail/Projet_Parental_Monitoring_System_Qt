#ifndef MENU_H
#define MENU_H
#include "login.h"
#include "QString"
#include <QDialog>
#include "admin.h"
#include<QPropertyAnimation>
#include "arduino.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    void setClient(admin l);

    ~Menu();

private slots:
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void showTime();
    void on_pushButton_retour_clicked();

    void on_pushButton_logout_clicked();

    void on_toolButton_aide_clicked();

    void on_toolButton_a_clicked();

    void on_pushButton_a_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_Sante_clicked();

    void on_pushButton_Animal_clicked();

    void on_pushButton_a_2_clicked();

    void on_pushButton_Securite_clicked();

    void on_pushButton_activite_clicked();

    void on_pushButton_Contact_clicked();

    void on_pushButton_programme_clicked();

    void on_pushButton_cuisine_clicked();

    void on_pushButton_123_clicked();

    void on_Button_cuisine_clicked();

    void on_pushButton_cui_clicked();

    void on_pushButton99_clicked();

    void on_pushButton99_2_clicked();

    void on_pushButton99_7_clicked();

    void on_pushButton99_8_clicked();

    void on_label_5_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::Menu *ui;

    QByteArray data; // variable contenant les données reçues
    QPropertyAnimation *animation;
    Arduino A; // objet temporaire
};

#endif // MENU_H

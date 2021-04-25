#ifndef CAPTEUR_DINCENDIE_H
#define CAPTEUR_DINCENDIE_H
#include "arduino.h"
#include <QDialog>

namespace Ui {
class capteur_dincendie;
}

class capteur_dincendie : public QDialog
{
    Q_OBJECT

public:
    explicit capteur_dincendie(QWidget *parent = nullptr);
    ~capteur_dincendie();

private slots:
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::capteur_dincendie *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // CAPTEUR_DINCENDIE_H

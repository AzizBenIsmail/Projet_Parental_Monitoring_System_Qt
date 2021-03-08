#ifndef SUIVIE_MEDICAL_H
#define SUIVIE_MEDICAL_H

#include <QDialog>

namespace Ui {
class Suivie_medical;
}

class Suivie_medical : public QDialog
{
    Q_OBJECT

public:
    explicit Suivie_medical(QWidget *parent = nullptr);
    ~Suivie_medical();

private slots:
    void on_pushButton_R_clicked();

    void on_pushButton_Q_clicked();

private:
    Ui::Suivie_medical *ui;
};

#endif // SUIVIE_MEDICAL_H

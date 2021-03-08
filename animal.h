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

private:
    Ui::Animal *ui;
};

#endif // ANIMAL_H

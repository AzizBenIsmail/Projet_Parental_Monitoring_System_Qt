#ifndef SECURITE_H
#define SECURITE_H
#include"admin.h"
#include <QDialog>

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

private:
    Ui::Securite *ui;
};

#endif // SECURITE_H

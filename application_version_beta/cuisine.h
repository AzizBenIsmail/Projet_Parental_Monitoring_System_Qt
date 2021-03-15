#ifndef CUISINE_H
#define CUISINE_H

#include <QDialog>

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

private:
    Ui::cuisine *ui;
};

#endif // CUISINE_H

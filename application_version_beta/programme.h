#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <QDialog>

namespace Ui {
class programme;
}

class programme : public QDialog
{
    Q_OBJECT

public:
    explicit programme(QWidget *parent = nullptr);
    ~programme();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

private:
    Ui::programme *ui;
};

#endif // PROGRAMME_H

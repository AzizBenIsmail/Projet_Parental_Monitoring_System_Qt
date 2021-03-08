#ifndef AIDE_H
#define AIDE_H
#include <QDialog>

namespace Ui {
class aide;
}

class aide : public QDialog
{
    Q_OBJECT

public:
    explicit aide(QWidget *parent = nullptr);
    ~aide();

private slots:
    void showTime();
    void on_pushButton_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Note_clicked();

    void on_pushButton_N_clicked();

    void on_pushButton_note_clicked();

    void on_pushButton_Cal_clicked();

private:
    Ui::aide *ui;
};

#endif // AIDE_H

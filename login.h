#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
//#include "menu.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void showTime();
    void on_pushButton_4_clicked();

    void on_pushButton_Q_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_precedent_clicked();

    void on_pushButton_valide_clicked();

private:
    Ui::Login *ui;
//menu *menu;
};

#endif // LOGIN_H

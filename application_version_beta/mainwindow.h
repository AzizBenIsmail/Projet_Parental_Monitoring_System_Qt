#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "login.h"
#include <QMainWindow>
#include<QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_bienvenu_clicked();

    void on_pushButton_z_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    Login *login;
};
#endif // MAINWINDOW_H

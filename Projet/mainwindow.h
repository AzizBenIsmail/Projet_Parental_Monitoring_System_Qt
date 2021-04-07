#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vetement.h"
#include <QPixmap>
#include "QMessageBox"
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QMainWindow>
#include "boutique.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajoutb_clicked();

    void on_afficheb_backwardAvailable(bool arg1);

    void on_annulerb_clicked();

    void on_suppb_clicked();

    void on_actualiserb_clicked();

    void on_reset_clicked();



    void on_modifierb_clicked();

    void on_ajouterv_clicked();

    void on_suppv_clicked();

    void on_resetv_clicked();

    void on_actualiserv_clicked();

    void on_triref_clicked();

    void on_triprix_clicked();

    void on_findv_cursorPositionChanged(int arg1, int arg2);

    void on_chercherv_clicked();

    void on_findv_textChanged(const QString &arg1);

    void on_modifierv_clicked();

    void on_annulerv_clicked();

private:
    Ui::MainWindow *ui;

boutique B;
vetement V;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_Ajouter_clicked();

    void on_Afficher_clicked();

    void on_Supprimer_clicked();

    void on_Ajouter_4_clicked();

    void on_Modifier_clicked();

    void on_Afficher_2_clicked();

    void on_Supprimer_fiche_clicked();

    void on_Ajouter_FICHE_clicked();

    void on_Modifier_fiche_clicked();

    void on_Tri_clicked();

    void on_Tr_Animal_clicked();

    void on_txt_recherche_animal_textChanged(const QString &arg1);

    void on_Afficher_Fiche_clicked();

    void on_PDF_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

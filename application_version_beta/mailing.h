#ifndef MAILING_H
#define MAILING_H
#include <QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QtWidgets/QMessageBox>
namespace Ui {
class Mailing;
}

class Mailing : public QDialog
{
    Q_OBJECT

public:
    explicit Mailing(QWidget *parent = nullptr);
    ~Mailing();

private slots:
    void on_pushButton_clicked();

    void on_sendBtn_clicked();

    void sendMail();
    void mailSent(QString);

private:
    Ui::Mailing *ui;
};

#endif // MAILING_H

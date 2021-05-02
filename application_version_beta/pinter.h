#ifndef PINTER_H
#define PINTER_H

#include <QMainWindow>
#include<QDialog>
namespace Ui {
class pinter;
}
class QPainter;
class QImage;
class pinter : public QMainWindow
{
    Q_OBJECT

public:
    explicit pinter(QWidget *parent = nullptr);
    ~pinter();
protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private slots:
    void on_actionTaille_triggered();

    void on_actioncolour_triggered();

    void on_actionsupprimer_triggered();

    void on_actiontaille_triggered();

private:
    Ui::pinter *ui;
    QPainter *mpainter;
    QImage *mImage;
    QPoint mBegin;
    QPoint mEnd;
    QColor mColor;
    bool mEnabled;
    int mSize;
};

#endif // PINTER_H

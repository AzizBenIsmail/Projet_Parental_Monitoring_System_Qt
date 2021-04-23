#ifndef MODIFFOURNITURE_H
#define MODIFFOURNITURE_H

#include <QDialog>

namespace Ui {
class Modiffourniture;
}

class Modiffourniture : public QDialog
{
    Q_OBJECT

public:
    explicit Modiffourniture(QWidget *parent = nullptr);
    ~Modiffourniture();

private:
    Ui::Modiffourniture *ui;
};

#endif // MODIFFOURNITURE_H

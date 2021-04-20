#ifndef MODIFEMP_H
#define MODIFEMP_H

#include <QDialog>

namespace Ui {
class Modifemp;
}

class Modifemp : public QDialog
{
    Q_OBJECT

public:
    explicit Modifemp(QWidget *parent = nullptr);
    ~Modifemp();

private:
    Ui::Modifemp *ui;
};

#endif // MODIFEMP_H

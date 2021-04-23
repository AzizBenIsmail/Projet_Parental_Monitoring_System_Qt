#ifndef AJOUTEMP_H
#define AJOUTEMP_H

#include <QDialog>

namespace Ui {
class Ajoutemp;
}

class Ajoutemp : public QDialog
{
    Q_OBJECT

public:
    explicit Ajoutemp(QWidget *parent = nullptr);
    ~Ajoutemp();

private:
    Ui::Ajoutemp *ui;
};

#endif // AJOUTEMP_H

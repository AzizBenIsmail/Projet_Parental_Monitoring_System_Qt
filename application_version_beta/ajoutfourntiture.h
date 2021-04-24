#ifndef AJOUTFOURNTITURE_H
#define AJOUTFOURNTITURE_H

#include <QDialog>

namespace Ui {
class AjoutFourntiture;
}

class AjoutFourntiture : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutFourntiture(QWidget *parent = nullptr);
    ~AjoutFourntiture();

private:
    Ui::AjoutFourntiture *ui;
};

#endif // AJOUTFOURNTITURE_H

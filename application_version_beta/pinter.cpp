#include "pinter.h"
#include "ui_pinter.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QDesktopWidget>

#define DEFAULT_SIZE 5
pinter::pinter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pinter)
{
    ui->setupUi(this);
    mImage =new QImage(QApplication::desktop()->size(),QImage::Format_ARGB32_Premultiplied);
    mpainter =new QPainter(mImage);
    mEnabled =false;
    mColor =QColor(Qt::black);
    mSize = DEFAULT_SIZE;
}

pinter::~pinter()
{
    delete ui;

    delete mImage;
    delete mpainter;

}
void pinter::paintEvent(QPaintEvent *e)
{
    QPainter painter (this);
    painter.fillRect(mImage->rect(), Qt::white);
    painter.drawImage(0,0, *mImage);
    e->accept();
}
void pinter::mousePressEvent(QMouseEvent *e)
{
    mEnabled =true;
    mBegin = e->pos();
    e->accept();
}
void pinter::mouseMoveEvent(QMouseEvent *e)
{
    if (!mEnabled){
        e->accept();
        return;
    }
   /* QPen pen;
    QBrush brush;
    brush.setColor(Qt::black);
    //brush.setStyle(Qt::RoundCap);
    pen.setBrush(brush);*/
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mEnd=e->pos();
    mpainter ->setPen(pen);
    mpainter ->drawLine(mBegin, mEnd);
    mBegin =mEnd;
    update();
    e->accept();

}
void pinter::mouseReleaseEvent(QMouseEvent *e)
{
    mEnabled =false;
    e->accept();
}




void pinter::on_actiontaille_triggered()
{
mSize =QInputDialog::getInt(this,"taille de crayon","entrer la taille:", 5, 1);
}

void pinter::on_actioncolour_triggered()
{
    mColor = QColorDialog::getColor(Qt::black, this,"color de crayon");
}

void pinter::on_actionsupprimer_triggered()
{
    close();
}

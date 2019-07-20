#include "Paintedwidgett.h"

#include <QLinearGradient>

PaintedWidgett::PaintedWidgett(QWidget *parent) : QWidget (parent)
{
    resize(800, 600);
    setWindowTitle(tr("Demo"));
}

void PaintedWidgett::paintEvent(QPaintEvent *) {
    //反走样
    /*
    QPainter painter1(this);

    painter1.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter1.setBrush(Qt::yellow);
    painter1.drawEllipse(50, 150, 200, 150);

    painter1.setRenderHint(QPainter::Antialiasing, true);
    painter1.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter1.setBrush(Qt::yellow);
    painter1.drawEllipse(300, 150, 200, 150);


    //线性渐变
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient(60, 50, 200, 200);
    linearGradient.setColorAt(0.2, Qt::white);
    linearGradient.setColorAt(0.6, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(50, 50, 200, 150);
    */

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int r = 150;
    QConicalGradient conicalGradient(0, 0, 0);

    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    painter.translate(r, r);

    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0, 0), r, r);
}

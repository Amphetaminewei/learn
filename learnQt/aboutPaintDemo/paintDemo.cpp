#include <QPainter>
#include "paintDemo.h"

paintDemo::paintDemo(QWidget *parent)
    :QWidget (parent)
{
    resize(400, 400);
    setWindowTitle(tr("Paint Demo"));
}

void paintDemo::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setViewport(0, 0, 400, 400);
    //painter.setWindow(0, 0, 200, 200);
    painter.fillRect(0, 0, 200, 200, Qt::red);

}

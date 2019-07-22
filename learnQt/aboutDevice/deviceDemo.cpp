#include "deviceDemo.h"

#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QPicture>


deviceDemo::deviceDemo(QWidget *parent)
    :QWidget (parent)
{
    //如果我们的画布不够大，就只能显示一小丢丢
    resize(800, 600);
}


void deviceDemo::paintEvent(QPaintEvent *) {
    /*
    QPainter painter(this);
    QPixmap pixmap("a.png");
    QBitmap bitmap("a.png");
    painter.drawPixmap(10, 10, 250, 125, pixmap);
    painter.drawPixmap(270, 10, 250, 125, bitmap);
    QPixmap whitePixmap("b.png");
    QBitmap whiteBitmap("b.png");
    painter.drawPixmap(10, 140, 250, 125, whitePixmap);
    painter.drawPixmap(270, 140, 250, 125, whiteBitmap);
    */
    QPicture picture;
    QPainter painter;
    painter.begin(&picture);             // 在 picture 进行绘制
    //painter.drawEllipse(10, 20, 80, 70); // 绘制一个椭圆
    painter.fillRect(0, 0, 200, 200, Qt::red);
    painter.end();                       // 绘制完成
    picture.save("drawing.pic");         // 保存 picture
}

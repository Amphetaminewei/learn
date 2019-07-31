#include "wall.h"

#include <QPainter>

Wall::Wall() : topLeft(0, 0), bottomRight(90, 90) {

}


QRectF Wall::boundingRect() const {

    //视图和场景坐标转换
    QPointF tl = mapFromScene(topLeft);
    QPointF br = mapFromScene(bottomRight);

    QRectF bound = QRectF(tl, br);
    return bound;
}

QPainterPath Wall::shape() const {
    //函数决定了蛇身体的形状，我们遍历蛇身体的每一个方块向路径中添加
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(-100, -100, 190, 190));

    //最后将路径返回并且由paint绘制出来
    return path;
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->setPen(Qt::red);
    painter->drawLine(-90, -90, 90, -90);
    painter->drawLine(-90, 80, 90, 80);
    painter->drawLine(-90, -90, -90, 80);
    painter->drawLine(90, -90, 90, 80);
    //painter->fillPath(shape(), Qt::red);
    painter->restore();
}

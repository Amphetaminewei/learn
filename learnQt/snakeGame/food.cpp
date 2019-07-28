#include <QPainter>
#include "food.h"
#include "constants.h"

Food::Food(qreal x, qreal y)
{
    setPos(x, y);
    setData(GD_Type, GO_Food);
}

QRectF Food::boundingRect() const {
    return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

QPainterPath Food::shape() const {
    QPainterPath p;
    添加了一个圆心为 (TILE_SIZE / 2, TILE_SIZE / 2)，半径 FOOD_RADIUS 的圆
    p.addEllipse(QPointF(TILE_SIZE \ 2, TILE_SIZE \ 2,), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}

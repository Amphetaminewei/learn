#include <QPainter>
#include "food.h"
#include "constants.h"

static const qreal FOOD_RADIUS = 3;

Food::Food(qreal x, qreal y) {
    setPos(x, y);
    //为对象添加一个键值对，含义是：类型是食物
    setData(GD_Type, GO_Food);
}

QRectF Food::boundingRect() const {
    //返回一个用于包裹住图形元素的矩形，也就是这个图形元素的范围
    //可以说是实际范围而paint将在这个范围中绘制图形
    return QRectF(-TILE_SIZE, -TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2);
}

QPainterPath Food::shape() const {
    //返回一个半径为3圆心坐标为TILE_SIZE / 2, TILE_SIZE / 2的圆的路径
    QPainterPath p;
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    //保存画笔的状态并在绘制完成后恢复
    painter->save();
    //绘制之前shape函数返回的圆并设置抗锯齿
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}


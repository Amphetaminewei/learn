#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>


class Food : public QGraphicsItem
{
public:
    //放置食物的横纵坐标
    Food(qreal x, qreal y);

    //返回一个矩形对象
    QRectF boundingRect() const;
    //返回要绘制的实际路径
    QPainterPath shape() const;

    //使用QPainter将图形画出来
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // FOOD_H

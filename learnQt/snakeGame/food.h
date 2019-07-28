#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>


class Food : public QGraphicsItem
{
public:
    //横纵坐标
    Food(qreal x, qreal y);
    QRectF boundingRect() const;
    QPainterPath shape() const;

    //使用QPainter将图形画出来
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // FOOD_H

#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>

class Wall : public QGraphicsItem {
public:
    Wall();

    QRectF boundingRect() const;
    QPainterPath shape() const;

    //使用QPainter将图形画出来
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
private:
    QPointF topLeft;
    QPointF bottomRight;

};

#endif // WALL_H

#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QGraphicsItem>

class Snake : public QGraphicsItem
{
public:
    Snake();
    Snake(QObject *parent);

    QRectF boundingRect() const;
    QPainterPath shape() const;

    //使用QPainter将图形画出来
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // SNAKE_H

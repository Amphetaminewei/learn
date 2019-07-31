#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QPainter>
#include <QList>
#include <QGraphicsItem>

class GameController;

class Snake : public QGraphicsItem
{
public:

    enum Direction {
        //枚举来表示移动方向
        NoMove,
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };


    Snake(GameController & controller);

    QRectF boundingRect() const;
    QPainterPath shape() const;

    //使用QPainter将图形画出来
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    //更改运动方向
    void setMoveDirection(Direction direction);

protected:
    void advance(int);

private:
    //头部的坐标
    QPointF head;
    //用来记录蛇的增长
    int growing;
    //记录速度
    int speed;
    //记录蛇的位置
    QList<QPointF> tail;
    //计时器，控制速度
    int tickCounter;
    Direction moveDirection;
    GameController &controller;

    //蛇的运动函数
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    //蛇的撞到处理
    void handleCollisions();

};

#endif // SNAKE_H

#include "constants.h"
#include "gamecontroller.h"
#include "snake.h"


#include <QPainter>
#include <QList>

//之前我一直以为SNAKE_SIZE应该是一个宏
static const qreal SNAKE_SIZE = TILE_SIZE;


Snake::Snake(GameController &controller) :
    head(0, 0),
    growing(7),
    speed(3),
    moveDirection(NoMove),
    controller(controller){}


QRectF Snake::boundingRect() const {
    //返回一个矩形包裹了整个蛇身
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    //这个函数的算法是：遍历蛇身体的每一个方块，找出所有部分的最大的 x 坐标和 y 坐标，以及最小的 x 坐标和 y 坐标,进而就可以确定蛇的位置
    foreach (QPointF p, tail) {
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }

    //视图和场景坐标转换
    QPointF tl = mapFromScene(QPointF(minX, minY));
    QPointF br = mapFromScene(QPointF(maxX, maxY));

    QRectF bound = QRectF(tl.x(),  // x
                          tl.y(),  // y
                          br.x() - tl.x() + SNAKE_SIZE,      // width
                          br.y() - tl.y() + SNAKE_SIZE       //height
                          );
    return bound;
}

QPainterPath Snake::shape() const {
    //函数返回实际的蛇身体路径
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, SNAKE_SIZE, SNAKE_SIZE));

    foreach (QPointF p, tail) {
        //在一个列表中保存蛇每个节点的路径，并按照这个路径绘制蛇身
        QPointF itemp = mapFromScene(p);
        path.addRect(QRectF(itemp.x(), itemp.y(), SNAKE_SIZE, SNAKE_SIZE));
    }

    //最后将路径返回并且由paint绘制出来
    return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(shape(), Qt::black);
    painter->restore();
}



//分别以 SNAKE_SIZE 为基准改变头部坐标，然后与场景边界比较，大于边界值时，设置为反方向的边界值
//也就是蛇碰到右边时会从左边出来
void Snake::moveLeft() {
    head.rx() -= SNAKE_SIZE;
    if (head.rx() < -90) {
        head.rx() = 80;
    }
}

void Snake::moveRight() {
    head.rx() += SNAKE_SIZE;
    if (head.rx() > 80) {
        head.rx() = -90;
    }
}

void Snake::moveUp() {
    head.ry() -= SNAKE_SIZE;
    if (head.ry() < -90) {
        head.ry() = 70;
    }
}

void Snake::moveDown() {
    head.ry() += SNAKE_SIZE;
    if (head.ry() > 70) {
        head.ry() = -90;
    }
}



void Snake::setMoveDirection(Direction direction)
{
    //修改运动方向
    moveDirection = direction;
}



void Snake::handleCollisions() {
    QList<QGraphicsItem *> collisions = collidingItems();

    // 检查蛇身体的碰撞
    foreach (QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Food) {
            //如果碰撞的对象是食物，则调用吃食物函数，并将蛇长度加一
            controller.snakeAteFood(this, (Food *)collidingItem);
            growing += 1;
        }
    }

    // Check snake eating itself
    if (tail.contains(head)) {
        //如果蛇身体的路径和蛇头路径重合，则调用蛇咬到自己函数
        controller.snakeAteItself(this);
    }
}




void Snake::advance(int step) {
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        //tickCounter作为一个内部计时器，根据时间边长增加难度
        return;
    }
    if (moveDirection == NoMove) {
        return;
    }

    if (growing > 0) {
        //如果蛇的长度增加了也就是碰到了食物，就将蛇头的位置加到蛇身也就是长度加了一
        QPointF tailPoint = head;
        tail << tailPoint;
        growing -= 1;
    } else {
        //如果没有则将蛇身的第一节设置为蛇头的路径
        tail.takeFirst();
        tail << head;
    }

    switch (moveDirection) {
    //判断蛇的运动方向，并分别调用不同运动方向的函数
        case MoveLeft:
            moveLeft();
            break;
        case MoveRight:
            moveRight();
            break;
        case MoveUp:
            moveUp();
            break;
        case MoveDown:
            moveDown();
            break;
    }
    //重新设置蛇头的坐标并检查碰撞
    setPos(head);
    handleCollisions();
}

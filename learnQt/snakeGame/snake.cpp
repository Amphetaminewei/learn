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
    //返回矩形的坐标
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
    //函数决定了蛇身体的形状，我们遍历蛇身体的每一个方块向路径中添加
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, SNAKE_SIZE, SNAKE_SIZE));

    foreach (QPointF p, tail) {
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



//分别以 SNAKE_SIZE 为基准改变头部坐标，然后与场景边界比较，大于边界值时，设置为边界值
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
    moveDirection = direction;
}



void Snake::handleCollisions() {
    QList<QGraphicsItem *> collisions = collidingItems();

    // Check collisions with other objects on screen
    foreach (QGraphicsItem *collidingItem, collisions) {
        if (collidingItem->data(GD_Type) == GO_Food) {
            // Let GameController handle the event by putting another apple
            controller.snakeAteFood(this, (Food *)collidingItem);
            growing += 1;
        }
    }

    // Check snake eating itself
    if (tail.contains(head)) {
        controller.snakeAteItself(this);
    }
}




void Snake::advance(int step) {
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        //tickCounter作为一个内部计时器，speed越高返回的越快难度也就越高
        return;
    }
    if (moveDirection == NoMove) {
        return;
    }

    if (growing > 0) {
        QPointF tailPoint = head;
        tail << tailPoint;
        growing -= 1;
    } else {
        tail.takeFirst();
        tail << head;
    }

    switch (moveDirection) {
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

    setPos(head);
    handleCollisions();
}

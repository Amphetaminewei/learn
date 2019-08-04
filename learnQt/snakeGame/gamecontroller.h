#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QTimer>
#include <QObject>

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;

//游戏控制类，通过控制类来将对象添加到场景中，并实现对蛇的操作，以及蛇的碰撞实现
class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent);


    //蛇在碰撞时可能出现的情况
    void snakeAteFood(Snake *snake, Food *food);
    void snakeAteItself(Snake *snake);
    //这里应该用来代替snake类中对撞墙的处理，在snake类中的moveLeft等四个类里做了这件事
    //显然创造一个Wall对象然后通过对墙的碰撞来做这件事会更好
    //但是目前我还没做这件事，只是把墙画出来了，后面有时间会把功能加上
    void snakeHitWall(Snake *snake, Wall *wall);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    QGraphicsScene &scene;
    Snake *snake;
    QTimer timer;

    //
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();

public slots:
    void pause();
    void resume();
    void gameOver();
};

#endif // GAMECONTROLLER_H

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QTimer>
#include <QObject>

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent);


    void snakeAteFood(Snake *snake, Food *food);
    void snakeAteItself(Snake *snake);
    void snakeHitWall(Snake *snake, Wall *wall);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    QGraphicsScene &scene;
    Snake *snake;
    QTimer timer;

    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();

public slots:
    void pause();
    void resume();
    void gameOver();
};

#endif // GAMECONTROLLER_H

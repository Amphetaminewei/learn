#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QTimer>
#include <QWidget>
#include <QGraphicsScene>

#include "snake.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, QObject *parent);

private:
    QGraphicsScene *scene;
    Snake *snake;
    QTimer timer;

    void pause();
    void resume();
};

#endif // GAMECONTROLLER_H

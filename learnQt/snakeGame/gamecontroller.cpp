#include "gamecontroller.h"
#include "snake.h"
#include "food.h"

#include <QGraphicsScene>
#include <QObject>

GameController::GameController(QGraphicsScene *scene, QObject *parent)
    :QObject(parent), scene(scene), snake(new  Snake(this))
{
    timer.start(1000/33);
    Food *f1 = new Food(0, 50);
    scene->addItem(f1);

    scene->addItem(snake);

    scene->installEventFilter(this);
}

void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               scene,  SLOT(advance()));
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            scene,  SLOT(advance()));
}

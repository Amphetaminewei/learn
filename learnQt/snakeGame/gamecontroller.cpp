#include <QEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDialog>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"
#include "wall.h"

int KILL_NUM = 0;

GameController::GameController(QGraphicsScene &scene, QObject *parent)
    :QObject(parent), scene(scene), snake(new  Snake(*this)) {
    timer.start(1000/33);

    Wall *w1 = new Wall();
    scene.addItem(w1);

    Food *f1 = new Food(0, -50);
    scene.addItem(f1);

    scene.addItem(snake);

    scene.installEventFilter(this);
    resume();
}

void GameController::pause() {
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
}

void GameController::resume() {
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}


void GameController::gameOver() {
    ++KILL_NUM;
    if(KILL_NUM == 10) {
        QMessageBox::warning(nullptr, tr("弱智警告"), tr("死了这么多次我觉得可能你需要帮助"));
        QMessageBox::information(nullptr, tr("准备好啦嘛"), tr("您的帮助要来了呢"));
        QDialog dialog;

        dialog.setWindowTitle(tr("爱你鸭小宝贝"));
        dialog.setStyleSheet("border-image:url(C:\ Users\Amphetamine \ Desktop3.png)");
        dialog.exec();
    }
    else {
        scene.clear();

        Wall *w1 = new Wall();
        scene.addItem(w1);

        snake = new Snake(*this);
        scene.addItem(snake);

        addNewFood();
    }

}

void GameController::handleKeyPressed(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Left:
            snake->setMoveDirection(Snake::MoveLeft);
            break;
        case Qt::Key_Right:
            snake->setMoveDirection(Snake::MoveRight);
            break;
        case Qt::Key_Up:
            snake->setMoveDirection(Snake::MoveUp);
            break;
        case Qt::Key_Down:
            snake->setMoveDirection(Snake::MoveDown);
            break;
    }
}


bool GameController::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        //这里用到了类型转换
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}


void GameController::snakeAteFood(Snake *snake, Food *food) {
    scene.removeItem(food);
    delete food;

    addNewFood();
}


void GameController::addNewFood() {
    int x, y;

    do {
        x = (int) (qrand() % 100) / 10 - 10;
        y = (int) (qrand() % 100) / 10 - 10;

        x *= 10;
        y *= 10;
    } while (x > 70 || x < -70 || y > 70 || y < -70 ||snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x , y);
    scene.addItem(food);
}


void GameController::snakeAteItself(Snake *snake) {
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::snakeHitWall(Snake *snake, Wall *wall){}

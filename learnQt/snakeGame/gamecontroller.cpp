#include <QEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDialog>
#include <QIcon>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"
#include "wall.h"

static int KILL_NUM = 0;

GameController::GameController(QGraphicsScene &scene, QObject *parent)
    :QObject(parent), scene(scene), snake(new  Snake(*this)) {
    //设置刷新率
    timer.start(1000/33);

    //将食物墙和蛇加入场景中
    Wall *w1 = new Wall();
    scene.addItem(w1);

    Food *f1 = new Food(0, -50);
    scene.addItem(f1);

    scene.addItem(snake);

    //安装了一个过滤器
    scene.installEventFilter(this);
    //打开信号槽连接
    resume();
}

void GameController::pause() {
    //关闭事件连接
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
}

void GameController::resume() {
    //开启一个信号槽连接，每当发出timeout信号时都会调用scene的advance
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}


void GameController::gameOver() {
    //当判断蛇死亡后重新布置场景

    //用来记录死亡次数
    //次数多了有惊喜蒽
    ++KILL_NUM;

    if(KILL_NUM == 4) {
        QMessageBox::warning(nullptr, tr("弱智警告"), tr("死了这么多次笨死啦"));
    }
    else if (KILL_NUM == 8) {
        QMessageBox::information(nullptr, tr("哼哼笨猪猪"), tr("可能你需要一点帮助蒽"));
    }
    else if (KILL_NUM == 11) {
        QMessageBox::information(nullptr, tr("果然没有我还是不行啊"), tr("我来给你一点点帮助蒽"));

        QDialog dialog;

        dialog.setWindowTitle(tr("给你我的小心心❤"));
        dialog.setWindowIcon(QIcon(":/img/2"));
        dialog.setStyleSheet("background-image:url(:/img/3);");
        dialog.exec();
    }
    else {
        //先清空场景
        scene.clear();

        Wall *w1 = new Wall();
        scene.addItem(w1);

        snake = new Snake(*this);
        scene.addItem(snake);

        addNewFood();

    }

}

void GameController::handleKeyPressed(QKeyEvent *event) {
    //判断键盘事件，并调用相应的函数
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
    //事件过滤器将键盘事件交给handleKeyPressde处理，否则调用父类的同名函数
    if (event->type() == QEvent::KeyPress) {
        //这里用到了类型转换，后面可能将这种类型转换都换成新式的
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}


void GameController::snakeAteFood(Snake *snake, Food *food) {
    //当蛇吃掉一个食物，移除这个食物并将其析构，随后添加一个新的食物
    scene.removeItem(food);
    delete food;

    addNewFood();
}


void GameController::addNewFood() {
    int x, y;

    //生成一个随机数作为食物坐标
    do {
        x = (int) (qrand() % 100) / 10 - 10;
        y = (int) (qrand() % 100) / 10 - 10;

        x *= 10;
        y *= 10;
    } while (x > 70 || x < -70 || y > 70 || y < -70 ||snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    //用这个坐标创建一个食物并加到场景中
    Food *food = new Food(x , y);
    scene.addItem(food);
}


void GameController::snakeAteItself(Snake *snake) {
    //当蛇咬到自己 ，调用game over
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::snakeHitWall(Snake *snake, Wall *wall){}

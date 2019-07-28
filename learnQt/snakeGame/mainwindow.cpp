#include "mainwindow.h"
#include "gamecontroller.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(scene, this))
{
    setCentralWidget(view);
    resize(600, 600);

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{

}


void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackground()
{
    //首先我们创建一个边长TILE_SIZE的QPixmap，将其使用灰色填充矩形
    //边框颜色默认是黑色，然后将这个Pixmap作为场景刷铺满整个视图
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));
}

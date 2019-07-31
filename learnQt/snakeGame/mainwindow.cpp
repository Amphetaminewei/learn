#include "mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"
#include "wall.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMenuBar>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(*scene, this))
{
    helpAction = new QAction(tr("Game &Help"), this);
    aboutAction = new QAction(tr("&About"), this);

    connect(helpAction, &QAction::triggered, this, &MainWindow::gameHelp);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::gameAbout);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);

    QMenu *aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAction);


    setCentralWidget(view);
    setFixedSize(600, 600);

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));

}

MainWindow::~MainWindow() {

}



void MainWindow::initScene() {
    //设置了蛇的起始坐标
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackground() {
    //首先我们创建一个边长TILE_SIZE的QPixmap，将其使用灰色填充矩形
    //边框颜色默认是黑色，然后将这个Pixmap作为场景刷铺满整个视图
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));

}


//更改视图大小
void MainWindow::adjustViewSize() {
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}


void MainWindow::gameHelp() {
    QMessageBox::information(this, tr("Help"), tr("果然是笨猪猪这都需要帮助"));
}

void MainWindow::gameAbout() {
    QMessageBox::about(this, tr("About this Game"), tr("没事看什么关于，关于爱你还要我说嘛"));
}

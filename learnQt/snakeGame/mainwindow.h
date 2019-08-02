#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;

class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //设置场景大小
    void initScene();
    //设置场景的背景
    void initSceneBackground();

    //用来做信号
    void gameHelp();
    void gameAbout();

    QGraphicsScene *scene;
    QGraphicsView *view;

    //通过控制器来将游戏的部件添加进主窗口中
    GameController *game;

    //两个菜单的action
    QAction *helpAction;
    QAction *aboutAction;
private slots:
    //更改视图的槽函数
    void adjustViewSize();
};

#endif // MAINWINDOW_H

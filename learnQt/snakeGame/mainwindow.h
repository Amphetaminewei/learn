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

    QGraphicsScene *scene;
    QGraphicsView *view;

    GameController *game;
};

#endif // MAINWINDOW_H

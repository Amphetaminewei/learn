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

    void gameHelp();
    void gameAbout();

    QGraphicsScene *scene;
    QGraphicsView *view;

    GameController *game;

    QAction *helpAction;
    QAction *aboutAction;
private slots:
    void adjustViewSize();
};

#endif // MAINWINDOW_H

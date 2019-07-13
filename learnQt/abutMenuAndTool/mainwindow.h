#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void open();//用来做打开的槽
    void newFile();//另一个槽
    QAction *openAction;
    QAction *newAction;//另一个action
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "deviceDemo.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);
    deviceDemo *painter = new deviceDemo(this);
    //setCentralWidget(painter);
}

MainWindow::~MainWindow()
{

}

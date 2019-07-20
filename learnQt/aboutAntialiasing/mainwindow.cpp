#include "mainwindow.h"
#include "Paintedwidgett.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    PaintedWidgett *paint = new PaintedWidgett(this);
    setCentralWidget(paint);
}

MainWindow::~MainWindow()
{

}

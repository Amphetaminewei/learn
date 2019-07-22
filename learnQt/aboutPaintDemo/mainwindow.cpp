#include "mainwindow.h"
#include "paintDemo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 400);
    paintDemo *painter = new paintDemo(this);
    //setCentralWidget(painter);
}

MainWindow::~MainWindow()
{

}

#include "mainwindow.h"
#include <QApplication>

#include "paintedwidget.h"


int main(int argc, char *argv[])
{
    //但是这里的主窗口怎么析构emmmm
    QApplication a(argc, argv);
    MainWindow win;
    win.show();
    return a.exec();
}

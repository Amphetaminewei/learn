#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //尝试实现一个文本编辑器
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

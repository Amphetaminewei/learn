#include "mainwindow.h"
#include <QApplication>
#include<QWidget>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPushButton quit("Quit");
    QWidget window;
    quit.setParent(&window);
    //依照标准c++的规则在离开作用域时，后被创建的对象先析构，所以先析构的是window
    //在析构window的同时，犹豫quit在其子列表中所以quit也被析构
    //然后依然会根据c++标准将quit析构一次所以
    //你炸了

    w.show();

    return a.exec();
}

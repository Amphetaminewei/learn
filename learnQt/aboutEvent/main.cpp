#include "mainwindow.h"
#include "EventLabel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //一个鼠标跟踪，显示我们鼠标的坐标
    //重载了鼠标移动，点击和右键点击的事件
    QApplication a(argc, argv);
    EventLabel theLabel;
    theLabel.setWindowTitle("MouthEvent Demo");
    theLabel.resize(200, 200);
    theLabel.setMouseTracking(true);
    theLabel.show();
    return a.exec();
}

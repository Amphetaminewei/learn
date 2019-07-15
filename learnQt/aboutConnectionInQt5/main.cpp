#include "mainwindow.h"
#include <QApplication>
#include "Reader.h"
#include "Newspaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Newspaper newspaper("Newspaper A");
    Reader reader;
    //由于我们的信号有重载，编译器不知道应该调用哪个,所以加上一个函数指针就知道了
    void (Newspaper:: *newPaperNameDate)(const QString &, const QDate &) = &Newspaper::newPaper;
    void (Newspaper:: *getNewPaper)(const QString &) const = &Newspaper::newPaper;

    QObject::connect(&newspaper, newPaperNameDate, &reader, &Reader::receiveNewspaper);
    QObject::connect(&newspaper, getNewPaper, &reader, &Reader::receiveNewspaper);
//这里避免了使用老式C强制类型转换，改成了c++提供的类型转换，但是我想单独写成上面的形式却失败了emmm
    QObject::connect(&newspaper,
                     static_cast<void (Newspaper:: *)(const QString &, const QDate &)>(&Newspaper::newPaper),
                     &reader,
                     &Reader::receiveNewspaper);

    //Lambdab表达式代替槽函数
    //QObject::connect(&newspaper,
    //                 static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::newPaper),
    //                 &reader,
    //                 [=](const QString &name) { /* Your code here. */ });

    newspaper.sendSignals();
    return a.exec();
}

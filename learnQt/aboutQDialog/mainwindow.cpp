#include "mainwindow.h"
#include "dialog.h"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QDialog>
#include <iostream>
#include <QDebug>


//其他都和菜单栏那部分的代码一样只是将作为信号槽的open函数的动作改成了创建一个对话框
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open1);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    //QDialog dialog();
    //QDialog dialog(this);
    //dialog.setWindowTitle(tr("this is a dialog"));
    //dialog.exec();
    QDialog *dialog = new QDialog(this);
    //dialog->setWindowTitle(tr("a dialog"));
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    //可以注意到，这里在堆上建立对象会发生内存泄露！
    //这句来防止内存泄漏，指定在窗口关闭时析构对象

    dialog->exec();//应用级模态对话框
    //dialog->open();//窗口级模态对话框
    //dialog->show();//非模态对话框
    //dialog.show();这样会导致窗口一闪而过
    //测试手动释放对象
    //delete dialog;

    qDebug()<<dialog->result();
}


void MainWindow::open1()
{
    QDialog *dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    dialog->exec();
    qDebug()<<dialog->result();
    //这里是收不到返回值的，因为exec结束之后就将对象析构了
}


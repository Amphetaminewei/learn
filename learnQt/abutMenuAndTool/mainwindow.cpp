#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open"));
    //新建一个打开动作并且拥有快捷键
    openAction->setShortcut(QKeySequence::Open);
    //将这个动作绑定快捷键open
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    //将动作的触发信号和this的open槽建立连接

    newAction = new QAction(QIcon(":/images/doc-open"), tr("&NEW"));
    newAction->setShortcut(QKeySequence::New);
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);

    QMenu *fileMenu = menuBar()->addMenu(tr("&file"));
    //新建了一个菜单栏
    fileMenu->addAction(openAction);
    //并给这个菜单栏加上了openAction动作
    fileMenu->addAction(newAction);
    //为菜单栏加上其他动作后这个菜单就有了两个项

    QMenu *newMenu = menuBar()->addMenu(tr("new"));
    newMenu->addAction(newAction);

    QToolBar *fileToolBar = addToolBar(tr("&file"));
    //新建一个工具栏
    fileToolBar->addAction(openAction);
    //并为这个工具栏添加了openAction动作
    fileToolBar->addAction(newAction);

    statusBar();
    //新建一个状态栏
    //openStatus->addAction(openAction);
    //添加了openAction动作
    //但是问题是你并不会去点击状态栏，所以并不会有动作emmm
    openAction->setStatusTip(tr("Open a file"));
    //设置这个动作的状态栏显示的字
    newAction->setStatusTip(tr("New a file"));

    QToolBar *newTool = addToolBar(tr("a other tool"));
    newTool->addAction(newAction);
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
    //这是对槽函数的实现，也就是在槽接收到信号的时候会发生的事
}

void MainWindow::newFile()
{
    QMessageBox::information(this, tr("Information"), tr("New"));
    //点击新建按钮时会发生的动作
}

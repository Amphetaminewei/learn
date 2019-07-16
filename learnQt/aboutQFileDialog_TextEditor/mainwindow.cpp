#include "mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //两个动作的父对象都是主窗口
    openAction = new QAction(QIcon(":/images/open"),tr("&open"),this);
    saveAction = new QAction(QIcon(":/images/save"),tr("&save"),this);

    //设置快捷键
    openAction->setShortcut(QKeySequence::Open);
    saveAction->setShortcut(QKeySequence::Save);

    //设置动作会在状态栏显示的内容
    openAction->setStatusTip("open a new filee");
    saveAction->setStatusTip("Save this file");

    //加一个状态栏
    statusBar();

    //增加一个菜单栏，增加一个file菜单并为这个菜单加上两个项
    QMenu *theFileMenu = menuBar()->addMenu(tr("&File"));
    //QMenu *theHelpMenu = menuBar()->addMenu(tr("&Help"));
    theFileMenu->addAction(openAction);
    theFileMenu->addAction(saveAction);

    //增加一个工具栏
    QToolBar *theToolBar = addToolBar(tr("&File"));
    theToolBar->addAction(openAction);
    theToolBar->addAction(saveAction);

    //文本编辑框，这里的文本编辑框作为成员而不是像菜单栏和工具栏在构造函数中创建
    textEdit = new QTextEdit(this);
    //将一个组件作为窗口的中心组件的函数
    setCentralWidget(textEdit);

    //信号槽连接
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

}

MainWindow::~MainWindow()
{
    //虽然豆子的代码演示里面没有写析构函数，
    //但是我觉得这个应该写上蒽，我们的成员可都是指针而且，这些成员都被构造了
    delete openAction;
    delete saveAction;
    delete textEdit;
}

void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    //如果路径不为空
    if(!path.isEmpty()) {
        //打开文件
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this,
                                 tr("Read file"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        //如果顺利打开文件了，创建一个文本流，通过文本流读取全部文本内容
        //然后用texttEdit的seText函数将文本内容写入到文本框中
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else {
        QMessageBox::warning(this,
                             tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile() {
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty()) {
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this,
                                 tr("Write file"),
                                 tr("Cannot open file:\n%1").arg(path));
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
    }
    else {
        QMessageBox::warning(this,
                             tr("Path"),
                             tr("You did not select any file."));
    }
}

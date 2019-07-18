#include "mainwindow.h"

#include <QTextEdit>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    theTextEdit = new QTextEdit;
    setCentralWidget(theTextEdit);
    theTextEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete theTextEdit;
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == theTextEdit) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);
            qDebug() << "you press" << keyEvent->key();
            return true;
        }
        else {
            return false;
        }
    }
    else {
        //如果不是我们关心的组件，则将其交给父类的事件过滤器处理
        return QMainWindow::eventFilter(watched, event);
    }
}

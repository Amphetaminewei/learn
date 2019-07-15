#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //创建了一个问题窗口，根据点击不同创建不同的消息窗口
    //这个问题窗口的父窗口是我们的主窗口
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("Question"),
                                                  tr("Are you OK?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::Yes)) {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    } else {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
    }


    //这是一个常见的保存窗口，对你的不同选择会在控制台有不同的输出
    QMessageBox ifSave;
    ifSave.setText(tr("do you wang to save?"));
    ifSave.setInformativeText(tr("Do you wang to change?"));
    ifSave.setDetailedText(tr("Different hear..."));
    ifSave.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    ifSave.setDefaultButton(QMessageBox::Save);
    int ret = ifSave.exec();
    switch (ret) {
    case QMessageBox::Save :
        qDebug() << "Save Document!";
        break;
    case QMessageBox::Discard :
        qDebug() << "Discard!";
        break;
    case QMessageBox::Cancel :
        qDebug() << "Cancle!";
        break;
    }

}

MainWindow::~MainWindow()
{

}

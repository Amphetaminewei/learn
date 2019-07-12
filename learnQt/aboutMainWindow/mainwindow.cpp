#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
//    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon("./images/doc-open"),tr("&open..."),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    //将这个QAction的triggered()信号与MainWindow类的open()函数连接起来

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QStatusBar *statBar = statusBar() ;
    statBar->addAction(openAction);
    setStatusBar(statBar);
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}

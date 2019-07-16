#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void openFile();
    void saveFile();

private:
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H

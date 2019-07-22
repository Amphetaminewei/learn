#ifndef PAINTDEMO_H
#define PAINTDEMO_H

#include <QPaintEvent>
#include <QWidget>
class paintDemo : public QWidget
{
    Q_OBJECT
public:
    paintDemo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTDEMO_H

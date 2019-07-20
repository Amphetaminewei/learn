#ifndef PAINTEDWIDGETT_H
#define PAINTEDWIDGETT_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class PaintedWidgett : public QWidget
{
    Q_OBJECT
public:
    PaintedWidgett(QWidget *parent = 0);
    ~PaintedWidgett() {

    }
protected:
    void paintEvent(QPaintEvent *);
};

#endif // PAINTEDWIDGETT_H

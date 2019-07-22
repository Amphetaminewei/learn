#ifndef DEVICEDEMO_H
#define DEVICEDEMO_H

#include <QWidget>
#include <QPaintEvent>

class deviceDemo : public QWidget
{
    Q_OBJECT
public:
    deviceDemo(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // DEVICEDEMO_H

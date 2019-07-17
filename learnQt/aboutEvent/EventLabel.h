#ifndef EVENTLABLE_H
#define EVENTLABLE_H

#include <QLabel>
#include <QObject>

class EventLabel : public QLabel
{
    Q_OBJECT
public:
    EventLabel();
    void getClick();
signals:
    void click();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


};

#endif // EVENTLABLE_H

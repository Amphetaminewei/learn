#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QGraphicsItem>

class Snake : public QGraphicsItem
{
public:
    Snake();
    Snake(QObject *parent);
};

#endif // SNAKE_H

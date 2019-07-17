#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QObject>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = 0);

private:
    void onButtonClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CUSTOMBUTTON_H

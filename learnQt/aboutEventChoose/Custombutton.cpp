#include "Custombutton.h"
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>

CustomButton::CustomButton(QWidget *parent) :
    QPushButton (parent)
{
    //而且这里调用了父类的构造函数
    //这里的click函数是继承过来的，其实是父类QPushButton的函数！
    connect(this, &CustomButton::clicked, this, &CustomButton::onButtonClicked);
}

void CustomButton::onButtonClicked() {
    QMessageBox::information(this, tr("you click me!"), tr("you click my ass!"));
}


void CustomButton::mousePressEvent(QMouseEvent *event) {
    //如果是左键，控制台打印left，否则调用父类的事件函数

    if (event->button() == Qt::LeftButton) {
        qDebug() << "left";
        //QPushButton::mousePressEvent(event);
    }
    else {
        QPushButton::mousePressEvent(event);
    }
}

#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Enter your age");

    QSpinBox *spinbox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal, &window);

    spinbox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    void (QSpinBox:: *SpinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinbox, SpinBoxSignal, slider,&QSlider::setValue);
    spinbox->setValue(20);
    //这里的信号槽中，由于valueChanged有两个重载的信号，编译器不知道该选哪个，所以定义了一个函数指针，指向参数为int的valueChanged函数
    //而这两个connect实现了双向数据绑定，但是如果如果在我们用自己的信号做双向数据绑定时，应该注意防止进入无线循环

    QHBoxLayout *theLatout = new QHBoxLayout();
    theLatout->addWidget(spinbox);
    theLatout->addWidget(slider);
    window.setLayout(theLatout);

    window.show();

    return app.exec();
}

#include "mainwindow.h"
#include "Custombutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomButton theButton;
    theButton.setText(QObject::tr("this is a button"));
    theButton.show();
    return a.exec();
}

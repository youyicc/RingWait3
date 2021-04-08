#include "RingWait3.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RingWait3 mainWidget;
    mainWidget.show();
    return a.exec();
}

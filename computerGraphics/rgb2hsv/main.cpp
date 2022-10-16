#include "rgb2hsvmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rgb2hsvMainWindow w;
    w.show();
    return a.exec();
}

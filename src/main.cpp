#include <QtGui/QApplication>
#include "autoqt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AutoQt w;
    w.show();
    return a.exec();
}

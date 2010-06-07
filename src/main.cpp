#include <QtGui/QApplication>
#include "AutoQt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AutoQt w;
    w.show();
    return a.exec();
}

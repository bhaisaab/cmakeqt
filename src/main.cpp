#include <QtGui/QApplication>
#include <QTranslator>
#include "CMakeQt.h"

#define TS_PREFIX "cmakeqt_"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    QString lang = "fr_FR";
    translator.load( TS_PREFIX + lang, ":/ts/");
    app.installTranslator(&translator);

    CMakeQt w;
    w.show();
    return app.exec();
}

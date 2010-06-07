#ifndef AUTOQT_H
#define AUTOQT_H

#include "ui_AutoQt.h"

#include <QtGui>

class AutoQt : public QMainWindow
{
    Q_OBJECT

public:
    AutoQt(QWidget *parent = 0);

private:
    Ui::AutoQt ui;
};

#endif // AUTOQT_H

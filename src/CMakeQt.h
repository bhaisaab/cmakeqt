#ifndef CMAKEQT_H
#define CMAKEQT_H

#include "ui_CMakeQt.h"
#include <QtGui>

class CMakeQt : public QDialog
{
    Q_OBJECT

    public:
        CMakeQt(QWidget *parent = 0);

    private:
        Ui::CMakeQt m_ui;
};

#endif // CMAKEQT_H

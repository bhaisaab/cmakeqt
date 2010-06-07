#ifndef AUTOQT_H
#define AUTOQT_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class AutoQt;
}

class AutoQt : public QMainWindow
{
    Q_OBJECT

public:
    AutoQt(QWidget *parent = 0);
    ~AutoQt();

private:
    Ui::AutoQt *ui;
};

#endif // AUTOQT_H

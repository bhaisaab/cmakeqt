#include "autoqt.h"
#include "ui_interface.h"

AutoQt::AutoQt(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AutoQt)
{
    ui->setupUi(this);
}

AutoQt::~AutoQt()
{
    delete ui;
}

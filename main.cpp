#include "mainwindow.h"
#include <QApplication>
#include "qcustomplot.h"

static int mode = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

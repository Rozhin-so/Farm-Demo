#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

//    QTimer::singleShot(1000, &a ,SLOT(startRand())) ;

//    void QTimer::start(int msec)


    w.show();
    return a.exec();
}

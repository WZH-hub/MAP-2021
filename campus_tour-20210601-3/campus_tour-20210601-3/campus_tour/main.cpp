#include "mainwindow.h"

#include <QApplication>
//QElapsedTimer find_time;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //find_time.start();
    MainWindow w;
    w.show();
    return a.exec();
}

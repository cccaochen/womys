#include "mainwindow.h"
#include <QApplication>

#include <qDebug>

int main(int argc, char *argv[])
{
    //QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

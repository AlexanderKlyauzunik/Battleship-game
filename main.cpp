#include "mainwindow.h"
#include<QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1250, 500);
    w.show();
    return a.exec();
}

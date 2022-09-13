#include "mainwindow.h"
#include<QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Battleship game");
    w.show();
    return a.exec();
}

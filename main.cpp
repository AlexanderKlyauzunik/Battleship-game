#include "MainWindow.h"
#include<QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.resize(1250, 500);
    w.show();
    return a.exec();
}

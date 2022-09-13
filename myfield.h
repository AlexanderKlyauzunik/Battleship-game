#ifndef MYFIELD_H
#define MYFIELD_H

#include "battlefield.h"
#include "ui_mainwindow.h"
#include <QThread>

class MyField : public BattleField
{
private:
     void blink(int x,int y);
public:
    MyField();

    int put(int x, int y);
    int strike(int x,int y);
    void aiPlacement();
    void resetfield();
};

#endif // MYFIELD_H

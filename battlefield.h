#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "ship.h"
#include "QObject"
#include "QTableWidget"
#include "ui_mainwindow.h"
#include <iostream>

class BattleField
{
protected:
    int currentState;
    int freeShips[4];
    int shipType;
    Ship ships[10];
    int horState;

    int checkPlacement(int x, int y, int n, int hor);
    bool validPosition(int x, int y);
public:
    int shipAlive;
    int field[10][10];
    Ui::MainWindow* gui;
    void setHor();
    void setVert();
    void setFourDeck();
    void setThreeDeck();
    void setTwoDeck();
    void setOneDeck();
    bool ready();
    BattleField();
    virtual int put (int x, int y) = 0;
    virtual int strike(int x,int y)=0;
    virtual void save()=0;
    virtual void resetfield()=0;
    virtual void load()=0;
};

#endif // BATTLEFIELD_H

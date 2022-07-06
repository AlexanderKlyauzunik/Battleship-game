#ifndef SHIP_H
#define SHIP_H

#include <iostream>

class Ship
{
private:
    int deck[4]; //1,0,-1 deck/field/wounded
    int num, alive;
    int x,y,hor;
public:
    int getX();
    int getY();
    int getN();
    int getHor();
    int getDeck(int xCoord, int yCoord);
    Ship (int n,int xCoord, int yCoord, int horPosition);
    Ship();
    int strikeShip(int xCoord, int yCoord);
};

#endif // SHIP_H

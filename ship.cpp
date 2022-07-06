#include "ship.h"

int Ship::getX()
{
    return x;
}

int Ship::getY()
{
    return y;
}

int Ship::getN()
{
    return num;
}

int Ship::getHor()
{
    return hor;
}

int Ship::getDeck(int xCoord, int yCoord)
{
    if (hor)
    {
        return(deck[xCoord - x]);
    }
    else
    {
        return(deck[yCoord - y]);
    }
}

Ship::Ship(int n, int xCoord, int yCoord, int horPosition)
{
    alive = n;
    num = n;

    for (int i = 0; i < n; ++i)
    {
        deck[i] = 1;
    }

    for (int i = n; i < 4; ++i)
    {
        deck[i] = 0;
    }

    x = xCoord;
    y = yCoord;
    hor = horPosition;
}

Ship::Ship()
{

}

int Ship::strikeShip(int xCoord, int yCoord)
{
    if (!alive)
    {
        return -1;
    }

    int strikeDeck;

    if (hor)
    {
        strikeDeck = xCoord - x;
    }
    else
    {
        strikeDeck = yCoord - y;
    }

    if (deck[strikeDeck] == -1)
    {
        return -1;
    }
    else
    {
        deck[strikeDeck] = -1;
        alive--;

        if (alive)
        {
            return 1;
        }

        return 2;
    }
}

#include "battlefield.h"

BattleField::BattleField()
{
    this->currentState = 10;

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
           {
                this->field[i][j]=0;
           }

    this->horState = 1;

    for(int i = 0;i < 4; i++)
    {
        this->freeShips[i]= 1 + i; // forming array for 'free' ships
    }

    this->shipAlive = 10;
    this->shipType = 4;
}

bool BattleField::validPosition(int x, int y)
{
    return x < 10 && x > -1 && y < 10 && y > -1;
}

void BattleField::setHor()
{
    horState = 1;
}

void BattleField::setVert()
{
    horState = 0;
}

bool BattleField::ready()
{
    return (currentState == 0 && this->shipAlive != 0);
}

void BattleField::setFourDeck()
{
    shipType = 4;
}

void BattleField::setThreeDeck()
{
    shipType = 3;
}

void BattleField::setTwoDeck()
{
    shipType = 2;
}

void BattleField::setOneDeck()
{
    shipType = 1;
}

int BattleField::checkPlacement(int x, int y, int n, bool horizontal)
{
    if ((horizontal && (x + n > 10)) || (!horizontal && (y + n > 10)))
    {
        return 1;
    }

    if (horizontal)
        {
            for (int i = -1; i <= n; i++)
            {
                if (validPosition(x + i, y - 1) && field[x + i][y - 1])
                {
                        return 1;
                }

                if (validPosition(x + i, y + 1) && field[x + i][y + 1])
                {
                        return 1;
                }
            }

            if (validPosition(x - 1, y) && field[x - 1][y])
            {
                    return 1;
            }

            if (validPosition(x+n,y) && field[x + n][y])
            {
                    return 1;
            }

            for (int i = 0; i < n; i++)
            {
                if (field[x + i][y])
                {
                    return 1;
                }
            }
        }
    else
    {
        for (int i = -1;i <= n; i++)
        {
            if (validPosition(x - 1, y + i))
            {
                if (field[x - 1][y + i])
                {
                    return 1;
                }
            }

            if (validPosition(x + 1, y + i))
            {
                if (field[x + 1][y + i])
                {
                    return 1;
                }
            }
        }

        if (validPosition(x, y - 1) && field[x][y - 1])
        {
                return 1;
        }
        if (validPosition(x, y + n) && field[x][y + n])
        {
                return 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (field[x][y + i])
            {
                return 1;
            }
        }
    }

    return 0;
}

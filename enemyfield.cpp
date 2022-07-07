#include "enemyfield.h"

void EnemyField::aiStrike()
{
    int status=1;
    int x,y;
   while (status)
   {
       if (lastHitState[2] == -1)
       {
        x = rand() % 10;
        y = rand() % 10;
        status = playerField -> strike(x,y);
       }

       if(status == 0)
       {
           break;
       }

       if (status == 2)
        {
            lastHitState[2] = -1;
            lastHitState[3] = -1;
            if (playerField -> shipAlive == 0)
            {
                QMessageBox win;
                win.setWindowTitle("Result");
                win.setText("LOSE");
                win.setFixedSize(400,400);
                win.exec();
            }
            continue;
        }
        if (status == 1 && lastHitState[2] == -1)
        {
            lastHitState[0]=x;
            lastHitState[1]=y;
            lastHitState[2]=1;
        }
    if (lastHitState[3] == -1 && lastHitState[2] > 0)

    {
        x = lastHitState[0];
        y = lastHitState[1];
        switch (lastHitState[2])
        {
        case 1:
            if (validPosition(x-1, y))
            {
                status = playerField ->strike(x-1, y);
                if (status == 1)
                {
                    lastHitState[3] = 1;
                }
                else
                {
                    lastHitState[2]++;
                }
            }
            else
            {
               lastHitState[2]++;
            }
        break;

        case 2:
            if (validPosition(x, y-1))
            {
                status = playerField -> strike(x, y-1);
                if (status == 1)
                {
                    lastHitState[3] = 2;
                }
                else
                {
                    lastHitState[2]++;
                }
            }
            else
            {
                lastHitState[2]++;
            }
            break;

        case 3:if (validPosition(x+1, y))
            {
                status = playerField -> strike(x+1, y);
                if (status == 1)
                {
                    lastHitState[3] = 3;
                }
                else
                {
                    lastHitState[2]++;
                }
            }
            else
            {
                lastHitState[2]++;
            }
            break;

        case 4:
            if (validPosition(x, y+1))
            {

                status = playerField -> strike(x, y+1);
                if (status == 1)
                {
                    lastHitState[3] = 4;
                }
                else {
                    lastHitState[2]++;
                }
            }
            else {
                lastHitState[2]++;
            }

            break;

        case 5:
            lastHitState[2] = -1;
               break;
        }
    }

    if(!status)
    {
        return;
     }
       if (lastHitState[3] > 0 && lastHitState[2] > 0)
       {
           switch (lastHitState[3])
           {
           case 1:
            x = lastHitState[0];
            y = lastHitState[1];

            if (validPosition(x-1, y))
            {
             status = playerField -> strike(x-1, y);
            }
            else
            {
                lastHitState[3] = 3;
            }

            if (status==1)
            {
                lastHitState[0]--;
            }

            if (status==0)
            {
                lastHitState[3]=3;
            }

            if(status == -1 && playerField -> field[x-1][y] > 0)
            {
                lastHitState[0]--;
            }

            if(status == -1 && playerField -> field[x-1][y] == -1)
            {
                lastHitState[3] = 3;
            }

           break;

           case 2:
            x = lastHitState[0];
            y = lastHitState[1];

            if (validPosition(x, y-1))
            {
             status = playerField -> strike(x,y-1);
            }
            else
            {
                lastHitState[3] = 4;
            }

            if (status==1)
            {
                lastHitState[1]--;
            }

            if (status==0)
            {
                lastHitState[3]=4;
            }

            if(status == -1 && playerField -> field[x][y-1] > 0)
            {
                lastHitState[1]--;
            }

            if(status == -1 && playerField -> field[x][y-1] == -1)
            {
                lastHitState[3] = 4;
            }

           break;

           case 3:

            x = lastHitState[0];
            y = lastHitState[1];
            if (validPosition(x+1, y))
            {
             status = playerField -> strike(x+1, y);
            }
            else
            {
                lastHitState[3] = 1;
            }
            if (status==1)
            {
                lastHitState[0]++;
            }
            if (status==0)
            {
                lastHitState[3] = 1;
            }
            if(status == -1 && playerField -> field[x+1][y] > 0)
            {
                lastHitState[0]++;
            }
            if(status == -1 && playerField -> field[x+1][y] == -1)
            {
                lastHitState[3] = 1;
            }

           break;

           case 4:
            x = lastHitState[0];
            y = lastHitState[1];
            if (validPosition(x, y+1))
            {
             status = playerField -> strike(x, y+1);
            }

            else
            {
                lastHitState[3] = 2;
            }
            if (status==1)
            {
                lastHitState[1]++;
            }

            if (status==0)
            {
                lastHitState[3] = 2;
            }

            if(status == -1 && playerField -> field[x][y+1] > 0)
            {
                lastHitState[1]++;
            }

            if(status == -1 && playerField -> field[x][y+1] == -1)
            {
                lastHitState[3] = 2;
            }

           break;

          }
       }
   }
}

EnemyField::EnemyField(BattleField *pf)
{
    playerField = pf;
    for (int i =0; i < 4; ++i)
    {
        lastHitState[i] = -1;
    }
}

void EnemyField::aiPlacement()
{
    int status;
    do
   {
        int x = rand() % 10;
        int y = rand() % 10;

        if(rand() % 2)
        {
            setVert();
        }
        else
        {
            setHor();
        }
        status=put(x,y);
    }
    while(status);
}

int EnemyField::put(int x, int y)
{
    int n = shipType;

    if (this -> currentState == 0)
    {
        return -1;
    }

    if (freeShips[4-shipType] == 0)
    {
        shipType--;
        return -1;
    }
       int id = currentState;

       if (checkPlacement(x, y, n, horState))
       {
           return -1;
       }

       if (!horState)
       {
           for (int i = 0; i < n; ++i)
           {
               field[x][y+i]=id;
               QTableWidgetItem* ti = gui -> enemyField -> item(y+i, x);
             if(!ti)
             {
               ti = new QTableWidgetItem();
               gui -> enemyField -> setItem(y+i, x, ti);
             }
           }
       }
       if (horState)
       {
           for(int i = 0; i < n; ++i){
               field[x+i][y] = id;
               QTableWidgetItem* ti = gui -> enemyField -> item(y, x+i);
               if(!ti)
               {
                   ti = new QTableWidgetItem();
                   gui -> enemyField -> setItem(y, x+i, ti);
               }
           }

       }

       Ship temp(n, x, y, horState);
       this -> ships[id-1] = temp;
       this -> currentState--;
       this -> freeShips[4-shipType]--;

       if (this -> currentState==0)
       {
           return 0;
       }
        return 1;
}

int EnemyField::strike(int x, int y)
{
    int hit;
    int id = field[x][y];

    if (!playerField -> ready())
    {
        return -1;
    }

    if (!this ->ready())
    {
        return -1;
    }

    if (!validPosition(x,y))
    {
        return -1;
    }

    if (field[x][y] == -1)
    {
        return -1;
    }

    if (!field[x][y])
    {
        field[x][y] = -1;
        hit = 0;
    }

    if (id > 0)
    {
        hit = ships[id - 1].strikeShip(x, y);
    }

    if (hit == -1)
    {
        return -1;
    }

    if (hit == 0)
    {
        QTableWidgetItem* ti = gui->enemyField->item(y, x);
        if (!ti)
        {
            ti = new QTableWidgetItem();
        }
        gui->enemyField->setItem(y, x, ti);
        ti -> setText("—");
    }

    if (hit == 1)
    {
        gui ->enemyField -> item(y, x)->setText("X");
        gui->enemyField->item(y,x)->setBackground(QColor(255,100,100));
    }

    if (hit == 2)
    {
        shipAlive--;

        if (shipAlive == 0)
        {
            QMessageBox win;
            win.setWindowTitle("Result");
            win.setText("WIN");
            win.setFixedSize(400,400);
            win.exec();
            resetField();
        }

        int nShip = ships[id - 1].getN();
        int xShip = ships[id - 1].getX();
        int yShip = ships[id - 1].getY();
        int horShip = ships[id - 1].getHor();
        gui -> enemyField -> item(y, x) -> setText("X");

        if (horShip)
        {
            for (int i = xShip - 1; i <= xShip + nShip; ++i)
            {
                if (validPosition(i, yShip - 1))
                {
                    field[i][yShip - 1] = -1;
                    QTableWidgetItem* ti = gui->enemyField->item(yShip - 1,i);
                    if(!ti)
                    {
                        ti = new QTableWidgetItem();
                         gui -> enemyField -> setItem(yShip - 1,i,ti);
                    }
                    gui -> enemyField -> item(yShip-1,i) -> setText("-");
                }

                if (validPosition(i, y + 1))
                {
                     field[i][yShip + 1] = -1;
                    QTableWidgetItem* ti=gui -> enemyField -> item(yShip + 1, i);
                    if(!ti){
                        ti = new QTableWidgetItem();
                        gui -> enemyField -> setItem(yShip + 1, i, ti);
                    }

                    gui -> enemyField -> item(yShip + 1, i) -> setText("-");
                }
            }
            if (validPosition(xShip - 1, yShip))
            {
                 field[xShip - 1][y] = -1;
                QTableWidgetItem* ti = gui -> enemyField -> item(yShip, xShip - 1);
                if(!ti)
                {
                    ti = new QTableWidgetItem();
                    gui -> enemyField -> setItem(yShip, xShip - 1, ti);
                }
                 gui -> enemyField -> item(yShip, xShip-1) -> setText("-");

            }
            if (validPosition(xShip + nShip, yShip))
            {
                field[xShip + nShip][y] = -1;
                QTableWidgetItem* ti = gui -> enemyField -> item(yShip, xShip + nShip);
                if(!ti)
                {
                    ti = new QTableWidgetItem();
                    gui -> enemyField -> setItem(yShip, xShip + nShip, ti);
                }
                gui -> enemyField -> item(yShip, xShip + nShip) -> setText("-");
            }
        }
        else
        {
            for (int i = yShip - 1; i <= yShip + nShip; ++i)
            {
                if (validPosition(xShip - 1, i))
                {
                    field[xShip - 1][i] = -1;
                    QTableWidgetItem* ti = gui -> enemyField -> item(i, xShip - 1);
                    if(!ti)
                    {
                        ti = new QTableWidgetItem();
                        gui -> enemyField -> setItem(i, xShip - 1, ti);
                    }
                    gui -> enemyField -> item(i, xShip - 1) -> setText("-");
                }

                if (validPosition(xShip + 1, i))
                {
                    field[xShip + 1][i] = -1;
                    QTableWidgetItem* ti = gui -> enemyField -> item(i, xShip+1);
                    if(!ti)
                    {
                        ti = new QTableWidgetItem();
                        gui -> enemyField -> setItem(i, xShip + 1, ti);
                    }
                    gui -> enemyField -> item(i, xShip + 1) -> setText("-");
                }
            }

            if (validPosition(xShip, yShip - 1))
            {
                field[xShip][yShip - 1] = -1;
                QTableWidgetItem* ti = gui -> enemyField -> item(yShip - 1, xShip);
                if(!ti)
                {
                    ti = new QTableWidgetItem();
                    gui -> enemyField -> setItem(yShip - 1, xShip, ti);
                }
                gui -> enemyField -> item(yShip - 1, xShip) -> setText("-");
            }

            if (validPosition(xShip, yShip + nShip))
            {
                field[xShip][yShip + nShip] = -1;
                QTableWidgetItem* ti = gui -> enemyField -> item(yShip + nShip, xShip);
                if(!ti)
                {
                    ti = new QTableWidgetItem();
                    gui -> enemyField -> setItem(yShip + nShip, xShip, ti);
                }
                gui -> enemyField -> item(yShip + nShip, xShip) -> setText("-");
            }
        }
        gui -> enemyField -> item(y,x) -> setBackground(QColor(255,0,0));
    }

    if (!hit)
    {
        aiStrike();
    }

    return hit;
}

void EnemyField::resetField()
{
    this -> currentState = 10;
    for(int i = 0;i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
           {
                this->field[i][j] = 0;
           }
    }

    horState = 1;

    for(int i = 0; i < 4; ++i)
    {
        freeShips[i] = 1+i;
    }

    shipAlive = 10;
    shipType = 4;
    for (int i=0;i<4;i++)
    {
        lastHitState[i] = -1;
    }

    gui->enemyField->clear();
}

EnemyField::EnemyField()
{

}

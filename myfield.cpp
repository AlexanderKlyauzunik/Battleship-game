#include "myfield.h"

MyField::MyField()
{

}

int MyField::put(int x, int y)
{
    int n = shipType;

    if (this->currentState == 0)
    {
        return -1;
    }

    if (freeShips[4 - n] == 0)
    {
        return -2;
    }

       int id=currentState;

       if (checkPlacement(x, y, n, horState))
       {
           return -1;
       }

       if (!horState)
       {
           for (int i=0;i<n;i++)
           {
               field[x][y + i] = id;
               QTableWidgetItem * ti=gui->myField->item(y + i, x);

             if(!ti){
               ti=new QTableWidgetItem();
               gui->myField->setItem(y + i, x, ti);
             }

           ti->setBackground(QColor(255,255,0));
           ti->setText("X");
           }
       }
       else
       {
           for(int i = 0; i < n; i++){
               field[x + i][y] = id;
               QTableWidgetItem * ti=gui->myField->item(y,x+i);

               if(!ti){
                   ti = new QTableWidgetItem();
                   gui->myField->setItem(y, x + i, ti);
               }

               ti->setBackground(QColor(255, 255, 0));
               ti->setText("X");
           }
       }

       Ship temp(n, x, y, horState);
       this->ships[id - 1] = temp;
       this->currentState--;
       --this->freeShips[4 - n];

       if (this->currentState == 0)
       {
           gui->gui_decknum->setEnabled(false);
           gui->gui_shippos->setEnabled(false);
           return 0;
       }

       return 1;
}

int MyField::strike(int x, int y)
{
    int hit;

    if (!validPosition(x,y))
    {
        return -1;
    }

    if (field[x][y]==-1)
    {
        return -1;
    }

    if (!field[x][y])
    {
        field[x][y] = -1;
        hit = 0;
    }
    int id=field[x][y];

    if (id>0)
    {
        hit = ships[id - 1].strikeShip(x,y);
    }
    if (hit == -1)
    {
        return -1;
    }

    if (hit==0)
    {
        QTableWidgetItem * ti=gui->myField->item(y, x);

        if(!ti){
            ti=new QTableWidgetItem();
        }

        gui->myField->setItem(y, x, ti);
        ti->setText("-");
    }

    if (hit==1)
    {
       gui->myField->item(y,x)->setText("X");
       gui->myField->item(y,x)->setBackground(QColor(255, 100, 100));
    }

    if (hit==2)
    {
       int nship=ships[id - 1].getN();
       int xship=ships[id - 1].getX();
       int yship=ships[id - 1].getY();
       int horship=ships[id-1].getHor();
       shipAlive--;

       if(horship)
       {
           for (int i=xship-1;i<=xship+nship;i++)
           {
               if (validPosition(i,yship-1))
               {
                   field[i][yship-1]=-1;
                   QTableWidgetItem * ti=gui->myField->item(yship-1,i);
                   if(!ti){
                       ti = new QTableWidgetItem();
                        gui->myField->setItem(yship-1,i,ti);
                   }
                   gui->myField->item(yship - 1, i)->setText("-");
               }

               if (validPosition(i, y + 1))
               {
                    field[i][yship + 1] = -1;
                   QTableWidgetItem * ti=gui->myField->item(yship + 1, i);
                   if(!ti){
                       ti = new QTableWidgetItem();
                       gui->myField->setItem(yship + 1, i, ti);
                   }

                   gui->myField->item(yship + 1, i)->setText("-");
               }
           }
           if (validPosition(xship - 1, yship))
           {
                field[xship - 1][y] = -1;
               QTableWidgetItem * ti = gui->myField->item(yship, xship - 1);
               if(!ti){
                   ti = new QTableWidgetItem();
                   gui->myField->setItem(yship, xship - 1, ti);
               }
                gui->myField->item(yship, xship - 1)->setText("-");

           }
           if (validPosition(xship + nship, yship))
           {
               field[xship + nship][y] = -1;
               QTableWidgetItem * ti=gui->myField->item(yship, xship + nship);
               if(!ti){
                   ti=new QTableWidgetItem();
                   gui->myField->setItem(yship, xship + nship, ti);
               }
               gui->myField->item(yship, xship + nship)->setText("-");
           }
       }
       else
       {
           for (int i = yship - 1; i <= yship + nship; i++)
           {
               if (validPosition(xship - 1, i))
               {
                   field[xship - 1][i] = -1;
                   QTableWidgetItem * ti=gui->myField->item(i, xship - 1);
                   if(!ti){
                       ti = new QTableWidgetItem();
                       gui->myField->setItem(i, xship - 1, ti);
                   }
                   gui->myField->item(i, xship - 1)->setText("-");
                  ;
               }
               if (validPosition(xship + 1, i))
               {
                   field[xship + 1][i]=-1;
                   QTableWidgetItem * ti=gui->myField->item(i, xship + 1);
                   if(!ti){
                       ti=new QTableWidgetItem();
                       gui->myField->setItem(i, xship + 1, ti);
                   }
                   gui->myField->item(i, xship + 1)->setText("-");
               }
           }
           if (validPosition(xship, yship - 1))
           {
               field[xship][yship-1]=-1;
               QTableWidgetItem * ti=gui->myField->item(yship - 1, xship);
               if(!ti){
                   ti = new QTableWidgetItem();
                   gui->myField->setItem(yship - 1, xship, ti);
               }
               gui->myField->item(yship - 1, xship)->setText("-");
           }
           if (validPosition(xship, yship + nship))
           {
               field[xship][yship + nship] = -1;
               QTableWidgetItem * ti=gui->myField->item(yship + nship, xship);
               if(!ti){
                   ti=new QTableWidgetItem();
                   gui->myField->setItem(yship + nship, xship, ti);
               }
               gui->myField->item(yship + nship, xship)->setText("-");
           }
       }
       gui->myField->item(y, x)->setBackground(QColor(255, 0, 0));
    }
    return hit;
}

void MyField::ai_placement()
{
    int status;
    do
   {
        int x=rand()%10;
        int y=rand()%10;
        if(rand()%2)
        {
            setVert();
        }
        else
        {
            setHor();
        }
        status = put(x,y);
        if (status==-2)
        {
            shipType--;
        }
    }
    while(status);
}

void MyField::resetfield()
{
    this->currentState = 10;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
           {
                this->field[i][j]=0;
           }
    horState=1;

    for(int i = 0;i < 4; i++)
    {
        freeShips[i]=1 + i;//нулевой - четырехпалубник: одна штука
    }
    shipAlive=10;
    shipType=4;
    gui->myField->clear();
}

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

    int checkPlacement(int x, int y, int n, bool horizontal);
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
    virtual void resetfield()=0;
private slots:
    void on_radioButton_ForOneDeck_clicked();
    void on_radioButton_ForTwoDecks_clicked();
    void on_radioButton_ForThreeDecks_clicked();
    void on_radioButton_ForFourDecks_clicked();
    void on_radioButton_Vertical_clicked();
    void on_radioButton_Horizontal_clicked();
    void on_randomButton_clicked();
    void on_newGamebutton_clicked();
    void on_myField_cellClicked(int row, int column);
    void on_enemyField_cellClicked(int row, int column);
};

#endif // BATTLEFIELD_H

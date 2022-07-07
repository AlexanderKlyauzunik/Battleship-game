#ifndef MYFIELD_H
#define MYFIELD_H

#include "battlefield.h"

class MyField : public BattleField
{
public:
    MyField();

    int put(int x, int y);
    int strike(int x,int y);
    void ai_placement();
    void resetfield();
};

#endif // MYFIELD_H

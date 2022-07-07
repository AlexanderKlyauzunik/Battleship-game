#ifndef ENEMYFIELD_H
#define ENEMYFIELD_H

#include "battlefield.h"
#include <QMessageBox>

class EnemyField : public BattleField
{
private:
    int lastHitState[4];

    void aiStrike();
public:
    BattleField* playerField;
    EnemyField(BattleField* pf);
    void aiPlacement();
    int put(int x, int y);
    int strike(int x, int y);
    void resetfield();
    EnemyField();
};

#endif // ENEMYFIELD_H

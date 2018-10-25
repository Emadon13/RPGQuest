#ifndef BATTLE_H
#define BATTLE_H

#include"logic/entities/entity.h"


class Battle
{
public:
    Battle();
    Battle(Entity heroes[], Entity opponents[]);

    void setOrder(Entity fighters[]);


private:

};

#endif // BATTLE_H

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

    Entity *order[8];

};

#endif // BATTLE_H

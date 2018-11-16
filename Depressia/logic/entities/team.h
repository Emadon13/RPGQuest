#ifndef TEAM_H
#define TEAM_H

#include"logic/entities/hero.h"
#include"logic/items/inventory.h"

class Team
{
public:
    Team();

private:
    Inventory bag;
};

#endif // TEAM_H

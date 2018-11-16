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
    Hero h1, h2, h3, h4;
    Hero* team_members[4];
};

#endif // TEAM_H

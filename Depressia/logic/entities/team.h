#ifndef TEAM_H
#define TEAM_H

#include"io/entityloader.h"
#include"logic/items/inventory.h"

class Team
{
public:
    Team();

    int getTeamSize();
    Entity* getHero(int i);

private:
    Inventory bag;

    static const int teamSize = 1;
    Entity* hero[teamSize];
};

#endif // TEAM_H

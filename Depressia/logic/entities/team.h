#pragma once

#ifndef TEAM_H
#define TEAM_H

#include"io/entityloader.h"
#include"logic/items/inventory.h"

class Team
{
public:
    Team();

    int getTeamSize();
    Hero* getHero(int i);
    Hero** getHeroes();
    Item getInventoryItem(int i);
    void putInTheBag(std::string);
    std::string useItem(Entity* e, int i);


private:
    Inventory bag;

    static const int teamSize = 4;
    Hero* hero[teamSize];
};

#endif // TEAM_H

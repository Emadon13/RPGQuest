#pragma once

#ifndef TEAM_H
#define TEAM_H

#include"io/entityloader.h"
#include"logic/items/inventory.h"

class Team
{
public:
    Team();
    Team(Hero* e1, Hero* e2, Hero* e3, Hero* e4, Inventory b);

    int getTeamSize();
    Hero* getHero(int i);
    Hero** getHeroes();
    Inventory* getInventory();
    void putInTheBag(std::string);


private:
    Inventory bag;

    static const int teamSize = 4;
    Hero* hero[teamSize];
};

#endif // TEAM_H

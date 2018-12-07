#pragma once

#ifndef FIGHT_H
#define FIGHT_H

#include "logic/entities/hero.h"

class Mob;
class Fight
{
public:
    Fight();
    Fight(Hero* h[],
          Mob* m[],
          std::string img,
          std::string mus);

    Hero** getHeroes();
    Mob** getMobs();
    Entity** getAll();

    bool teamWin();
    bool mobsWin();
    Entity* nextPlayer();

    static const int nb_e = 4;



private:

    Hero* heroes[nb_e];
    Mob* mobs[nb_e];
    Entity* all[2*nb_e];
    int speeds[2*nb_e];
    int speedLimit;

    std::string music;
    std::string image;




    void setOrder(std::vector <Entity> fighters);
};

#endif // FIGHT_H

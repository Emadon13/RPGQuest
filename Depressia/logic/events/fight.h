#pragma once

#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include <vector>
#include "logic/events/event.h"

class Mob;
class Team;
class Hero;
class Entity;
class Fight : public Event
{
public:
    Fight();
    Fight(Team* team,
          Mob* m[],
          std::string img,
          std::string mus);

    static const int nb_e = 4;

    Hero** getHeroes();
    Mob** getMobs();
    Entity** getAll();

    bool teamWin();
    bool mobsWin();
    bool isEnded();
    Entity* nextPlayer();





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

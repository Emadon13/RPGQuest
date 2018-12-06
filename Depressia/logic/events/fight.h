#ifndef FIGHT_H
#define FIGHT_H

#include "logic/entities/hero.h"
#include "logic/entities/mob.h"



class Fight
{
public:
    Fight();
    Fight(Hero* h[],
          Mob* m[],
          std::string img,
          std::string mus);

    Entity** getHeroes();
    Entity** getMobs();
    Entity** getAll();

    bool teamWin();
    bool mobsWin();
    Entity* nextPlayer();



private:

    static const int nb_e = 4;
    Entity* heroes[nb_e];
    Entity* mobs[nb_e];
    Entity* all[2*nb_e];
    int speeds[2*nb_e];
    int speedLimit;

    std::string music;
    std::string image;




    void setOrder(std::vector <Entity> fighters);
};

#endif // FIGHT_H

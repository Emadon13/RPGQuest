#pragma once

#ifndef FIGHT_H
#define FIGHT_H

#include <string>
#include <vector>
#include <QUrl>
#include <QString>
#include "io/qpixmaploader.h"
#include "logic/events/event.h"

class Mob;
class Team;
class Hero;
class Entity;
class Fight : public Event
{
public:
    Fight();
    Fight(Team* t,
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

    void target(Mob* user, int skill);
    void target(Hero* user, int skill);
    void target(Hero* user, int skill, int target);

    QPixmap* getImage();
    QUrl* getMusic();





private:

    Team* team;
    Hero* heroes[nb_e];
    Mob* mobs[nb_e];
    Entity* all[2*nb_e];
    Entity* tHeroes[nb_e];
    Entity* tMobs[nb_e];
    std::vector<Entity*> vMobs, vHeroes, vAll;
    int speeds[2*nb_e];
    int speedLimit;

    std::string music;
    std::string image;




    void setOrder(std::vector <Entity> fighters);
};

#endif // FIGHT_H

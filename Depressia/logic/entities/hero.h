#pragma once

#ifndef HERO_H
#define HERO_H


#include "io/skillloader.h"
#include "logic/entities/entity.h"

class Hero : public Entity
{
public:
    Hero();
    Hero(std::string n,
         int l,
         int b_hp,
         int b_mp,
         int b_att,
         int b_def,
         int b_spd,
         std::string sn,
         std::string sd,
         std::string sa,
         std::string ss,
         std::string sk,
         std::string bi,
         std::vector<Skill*> s,
         std::string stl[max_lvl],
         std::string svelnk);

    int getXp();
    int getNextLevel();
    bool addXp(int i);

    std::string getSaveLink();

    SpriteLoop* getSpriteKilled();


private:
    int xp;
    int next_level;
    int base_hp;
    int base_mp;

    int base_att;
    int base_def;
    int base_spd;

    std::string saveLink;

    std::string skillsToLearn[max_lvl];

    void calculateLevel();


};

#endif // HERO_H

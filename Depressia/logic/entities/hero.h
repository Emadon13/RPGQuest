#ifndef HERO_H
#define HERO_H

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
         std::vector<Skill*> s,
         std::string stl[]);

private:
    int xp;
    int next_level;
    int base_hp;
    int base_mp;

    int base_att;
    int base_def;
    int base_spd;

    std::string skillsToLearn[max_lvl];

    void calculateNextLevel();


};

#endif // HERO_H

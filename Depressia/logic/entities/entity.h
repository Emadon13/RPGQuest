#pragma once

#ifndef ENTITY_H
#define ENTITY_H


#include <string>
#include <vector>
#include <iostream>
#include "logic/skills/attack.h"

class Entity
{
public:
    Entity();
    Entity(std::string m_name,
    int m_lvl,
    int m_hpMax,
    int m_mpMax,
    int m_att,
    int m_def,
    int m_spd,
    std::vector<Skill*>m_skills);
    ~Entity();

    std::string getName();
    int getLvl();
    int getHp();
    int getMp();
    int getHpMax();
    int getMpMax();
    int getAtt();
    int getDef();
    int getSpd();

    Skill getSkill(int i);
    int getSkillsSize();

    void takeDamage(int deg);
    void loseMp(int mp);
    void restaureHp(int hpHeal);
    void restaureMp(int mpHeal);
    std::string hitOpponent(Entity& target);

    bool isAlive();


protected:
    std::string name;
    int lvl;
    int hpMax;
    int mpMax;
    int hp;
    int mp;
    int att;
    int def;
    int spd;
    std::vector<Skill*>skills;
    Skill* attack;
    int static const max_lvl = 10;



};

#endif // ENTITY_H

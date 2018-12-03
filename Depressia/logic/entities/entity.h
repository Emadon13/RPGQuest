#pragma once

#ifndef ENTITY_H
#define ENTITY_H


#include <string>
#include <vector>
#include <iostream>
#include "logic/skills/skill.h"
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

    std::string getName() const;
    int getLvl() const;
    int getHp() const;
    int getMp() const;
    int getAtt() const;
    int getDef() const;
    int getSpd() const;

    Skill getSkill(int i);
    int getSkillsSize();

    void takeDamage(const int deg);
    void restaureHp(const int hpHeal);
    void restaureMp(const int mpHeal);
    Sheet hitOpponent(Entity& target);

    bool isAlive() const;


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
    //Attack attack;

    int static const max_lvl = 10;



};

#endif // ENTITY_H

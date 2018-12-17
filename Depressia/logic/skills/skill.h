#pragma once

#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <sstream>
#include <vector>
#include "io/spriteloader.h"

enum HitEffect {miss, normal, critical};
enum Range { self, one_ally, one_enemy, group_allies, group_enemies, all_entities, several };

class Entity;
class Skill
{
public:
    Skill();
    Skill(std::string n, std::string t, std::string s, int m_mpCost, Range);
    virtual ~Skill();

    std::string getName();
    std::string getText();
    SpriteUnique* getSprite();
    int getMpCost();
    std::string getSummary();
    Range getRange();
    bool hasMiss();
    virtual std::vector<int> call(Entity* user, std::vector<Entity*> targets);


protected:
    std::string name;
    std::string text;
    std::string sprite;
    int mpCost;
    Range range;
    std::string summary;
    HitEffect hitEffect;

    std::string setSummary(std::string s);
    void payMp(Entity* e);
    int effect(Entity* user, Entity* target);


};



#endif // SKILL_H

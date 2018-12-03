#pragma once

#ifndef ATTACK_H
#define ATTACK_H


#include "logic/skills/skill.h"
#include "logic/entities/entity.h"

class Attack : public Skill
{
public:
    Attack();
    Attack(std::string n, std::string t, int mp, std::vector<Category> cat, double c);
    ~Attack();

    Sheet call(Entity& user, Entity& target);
    Sheet call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    Sheet doSheet(int deg);
    Sheet doSheet(std::vector<int> deg);


};

#endif // ATTACK_H

#pragma once

#ifndef ATTACK_H
#define ATTACK_H

#include "logic/skills/skill.h"
#include "logic/entities/entity.h"

class Attack : public Skill
{
public:
    Attack();
    Attack(std::string n, std::string t, int mp, Range rng, float c);
    ~Attack();

    virtual std::vector<int> call(Entity& user, std::vector<Entity*> targets);

private:
    float coef;
    int effect(Entity& user, Entity& target);
    void setSummary(std::string user, std::vector<std::string> target, std::vector<int>);
    int critcoef;

};

#endif // ATTACK_H

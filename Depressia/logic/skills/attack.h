#pragma once

#ifndef ATTACK_H
#define ATTACK_H

#include "logic/skills/skill.h"
#include "logic/entities/entity.h"

class Attack : public Skill
{
public:
    Attack();
    Attack(std::string n, std::string t, int mp, Range rng, double c);
    ~Attack();

    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    int effect(Entity& user, Entity& target, float coef);
    void setSummary(HitEffect he, std::string user, std::vector<std::string> target, std::vector<int>);

};

#endif // ATTACK_H

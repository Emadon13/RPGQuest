#pragma once

#ifndef RECOVER_H
#define RECOVER_H

#include <sstream>
#include"logic/skills/skill.h"
#include "logic/entities/entity.h"

class Recover : public Skill
{
public:
    Recover();
    Recover(std::string n, std::string t, int mp, Range rng, double c);
    ~Recover();

    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    void setSummary(std::string user, std::vector<std::string> target, std::vector<int>);
    int effect(Entity& user, Entity& target);
};

#endif // RECOVER_H

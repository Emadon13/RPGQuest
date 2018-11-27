#ifndef RECOIL_H
#define RECOIL_H

#include"logic/skills/skill.h"
#include "logic/entities/entity.h"

class Recoil : public Skill
{
public:
    Recoil();
    Recoil(std::string n, std::string t, int mp, std::vector<Category> cat, double c, double r);
    ~Recoil();

    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    double rate;
};

#endif // RECOIL_H

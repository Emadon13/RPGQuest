#ifndef RECOVER_H
#define RECOVER_H

#include"logic/skills/skill.h"
#include "logic/entities/entity.h"

class Recover : public Skill
{
public:
    Recover();
    Recover(std::string n, std::string t, int mp, std::vector<Category> cat, double c);
    ~Recover();

    Sheet call(Entity& user, Entity& target);
    Sheet call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
};

#endif // RECOVER_H

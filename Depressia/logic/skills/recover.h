#ifndef RECOVER_H
#define RECOVER_H

#include <sstream>
#include"logic/skills/skill.h"
#include "logic/entities/entity.h"

class Recover : public Skill
{
public:
    Recover();
    Recover(std::string n, std::string t, int mp, std::vector<Category> cat, double c);
    ~Recover();

    std::string call(Entity& user, Entity& target);

private:
    double coef;
};

#endif // RECOVER_H

#ifndef RECOVER_H
#define RECOVER_H

#include<QString>
#include"logic/skills/skill.h"
#include "logic/entities/entity.h"

class Recover : public Skill
{
public:
    Recover();
    Recover(double m_coef);
    Recover(std::string m_name, std::string m_description, double m_coef);
    ~Recover();

    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
};

#endif // RECOVER_H

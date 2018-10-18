#ifndef RECOVER_H
#define RECOVER_H


#include<QString>
#include"Skill.h"
#include "logic/entities/entity.h"

using namespace std;

class Recover : public Skill
{
public:
    Recover();
    Recover(double m_coef);
    Recover(std::string m_name, std::string m_description, double m_coef);
    ~Recover();

    int call(Entity& attacker);
    int call(Entity& attacker, Entity& target);

private:
    double coef;
};

#endif // RECOVER_H

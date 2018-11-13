#ifndef AFTERMATH_H
#define AFTERMATH_H


#include<QString>
#include"Skill.h"
#include "logic/entities/entity.h"

class Aftermath : public Skill
{
public:
    Aftermath();
    Aftermath(double m_coef, double m_rate);
    Aftermath(std::string m_name, std::string m_description, double m_coef, double m_rate);
    ~Aftermath();

    std::vector<int> call(Entity& attacker, std::vector<Entity> targets);

private:
    double coef;
    double rate;
};

#endif // AFTERMATH_H

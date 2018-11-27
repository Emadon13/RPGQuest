#ifndef DRAIN_H
#define DRAIN_H

#include "logic/skills/skill.h"
#include "logic/entities/entity.h"

class Drain : public Skill
{
public:
    Drain();
    Drain(std::string n, std::string t, int mp, std::vector<Category> cat, double c, double r);
    ~Drain();

    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    double rate;};

#endif // DRAIN_H

#ifndef DRAIN_H
#define DRAIN_H

#include "logic/skills/attack.h"
#include "logic/entities/entity.h"

class Drain : public Attack
{
public:
    Drain();
    Drain(std::string n, std::string t, int mp, Range rng, double c, double r);
    ~Drain();

    int call(Entity& user, Entity& target);
    std::vector<int> call(Entity& user, std::vector<Entity> targets);

private:
    double coef;
    double rate;
    void setSummary(HitEffect he, std::string user, std::string target, int deg);
    void setSummary(HitEffect he, std::string user, std::vector<std::string> target, std::vector<int>);
};

#endif // DRAIN_H

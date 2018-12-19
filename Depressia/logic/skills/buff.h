#ifndef BUFF_H
#define BUFF_H

#include "logic/skills/skill.h"
#include "logic/entities/entity.h"

enum WayToBuff{buffUp, noBuff, buffDown};

class Buff : public Skill
{
public:
    Buff();
    Buff(std::string n,
         std::string t,
         std::string s,
         int mp,
         Range rng,
         WayToBuff att,
         WayToBuff def,
         WayToBuff spd);
    ~Buff();

    virtual std::vector<int> call(Entity* user, std::vector<Entity*> targets);

private:
    WayToBuff wayToBuff[BuffStats::nbStats];
    void setSummary(std::string user, std::vector<std::string> target);
    int effect(Entity* target);
};

#endif // BUFF_H

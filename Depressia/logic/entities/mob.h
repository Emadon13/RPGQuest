#pragma once

#ifndef MOB_H
#define MOB_H

#include "logic/events/fight.h"
#include "logic/entities/entity.h"

class Mob : public Entity
{
public:
    Mob();
    Mob(std::string m_name,
        int m_lvl,
        int m_hpMax,
        int m_mpMax,
        int m_att,
        int m_def,
        int m_spd,
        std::string sn,
        std::string sd,
        std::string sa,
        std::string ss,
        std::string sk,
        std::string battleIcon,
        std::vector<Skill*>m_skills);

    int chooseMove();
    Entity* chooseEntity(Entity** entities);
    //std::vector<Entity*> choseEntities(std::vector<Entity*>);

    SpriteUnique* getSpriteKilled();

private:
    int chooseSkill();
};

#endif // MOB_H

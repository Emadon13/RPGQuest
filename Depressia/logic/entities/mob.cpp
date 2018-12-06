#include "mob.h"

using namespace std;

Mob::Mob():
    Entity()
{

}

Mob::Mob(string m_name,
         int m_lvl,
         int m_hpMax,
         int m_mpMax,
         int m_att,
         int m_def,
         int m_spd,
         string sprite,
         string battleIcon,
         vector<Skill*>m_skills):
    Entity( m_name,
    m_lvl,
    m_hpMax,
    m_mpMax,
    m_att,
    m_def,
    m_spd,
    sprite,
    battleIcon,
    m_skills)
{

}

Skill* Mob::choseSkill()
{
    vector<Skill*> usable(0);
    for(unsigned i=0 ; i<skills.size() ; i++)
        if(skills.at(i)->getMpCost() <= mp)
            usable.push_back(skills.at(i));

    return usable.at(unsigned(rand()) % usable.size());

}

Entity* Mob::choseEntity(vector<Entity*> entities)
{
    return entities.at(unsigned(rand()) % entities.size());
}

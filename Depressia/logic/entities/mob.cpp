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
         string sn,
         string sd,
         string sa,
         string ss,
         string sk,
         string battleIcon,
         vector<Skill*>m_skills):
    Entity( m_name,
    m_lvl,
    m_hpMax,
    m_mpMax,
    m_att,
    m_def,
    m_spd,
    sn,
    sd,
    sa,
    ss,
    sk,
    battleIcon,
    m_skills)
{

}

int Mob::chooseMove()
{
    if(unsigned(rand()) % 2 == 0)
        return -1;
    else
        return chooseSkill();
}
int Mob::chooseSkill()
{
    vector<int> usable(0);
    for(unsigned i=0 ; i<skills.size() ; i++)
        if(skills.at(i)->getMpCost() <= mp)
            usable.push_back(int(i));

    if(usable.size() == 0)
        return -1;
    else
        return usable.at(unsigned(rand()) % usable.size());

}

Entity* Mob::chooseEntity(Entity** entities)
{
    vector<Entity*> attackable(0);
    for(unsigned i=0 ; i<Fight::nb_e ; i++)
        if(entities[i] != nullptr)
            if(entities[i]->getHp() >0)
                attackable.push_back(entities[i]);

    return attackable.at(unsigned(rand()) % attackable.size());
}

SpriteUnique* Mob::getSpriteKilled()
{
    return dynamic_cast<SpriteUnique*>(sprites[4]);
}

#include "entity.h"
#include <string>

using namespace std;

Entity::Entity() :
    name("RandomMOB"),
    lvl(1),
    hpMax(2),
    mpMax(0),
    hp(2),
    mp(0),
    att(1),
    def(1),
    spd(1),
    skills(0)
    //attack(Attack())
{}

Entity::Entity(string m_name,
               int m_lvl,
               int m_hpMax,
               int m_mpMax,
               int m_att,
               int m_def,
               int m_spd,
               vector<Skill*> m_skills):
    name(m_name),
    lvl(m_lvl),
    hpMax(m_hpMax),
    mpMax(m_mpMax),
    hp(m_hpMax),
    mp(m_mpMax),
    att(m_att),
    def(m_def),
    spd(m_spd),
    skills(m_skills)
    //attack(Attack())
{

}


Entity::~Entity()
{}


string Entity::getName() const
{
    return name;
}

int Entity::getLvl() const
{
    return lvl;
}


int Entity::getHp() const
{
    return hp;
}

int Entity::getMp() const
{
    return mp;
}

int Entity::getAtt()  const
{
    return att;
}

int Entity::getDef() const
{
    return def;
}

int Entity::getSpd() const
{
    return spd;
}

Skill Entity::getSkill(int i)
{
    if(skills.at(unsigned (i)) != NULL)
        return *(skills.at(unsigned(i)));

    else
    {
        cout << "ERREUR : Le " << i << "-ième sort de " << name << " n'existe pas" << endl;
        return Skill();
    }
}

int Entity::getSkillsSize()
{
    return int(skills.size());
}

void Entity::takeDamage(const int deg)
{
    hp -= deg;
    if (hp < 0) hp = 0;
    else if (hp > hpMax) hp = hpMax;
}

void Entity::restaureHp(const int hpHeal)
{
    hp += hpHeal;
    if (hp < 0) hp = 0;
    else if (hp > hpMax) hp = hpMax;
}

void Entity::restaureMp(const int mpHeal)
{
    mp += mpHeal;
    if (mp < 0) mp = mpMax;
}

Sheet Entity::hitOpponent(Entity& target)
{
    //return attack.call;
    return Sheet();
}

bool Entity::isAlive() const
{
    return (hp == 0);
}

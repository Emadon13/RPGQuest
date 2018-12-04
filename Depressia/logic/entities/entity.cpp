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
    skills(0),
    attack(new Attack())
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
    skills(m_skills),
    attack(new Attack())
{

}


Entity::~Entity()
{}


string Entity::getName()
{
    return name;
}

int Entity::getLvl()
{
    return lvl;
}


int Entity::getHp()
{
    return hp;
}

int Entity::getMp()
{
    return mp;
}

int Entity::getHpMax()
{
    return hpMax;
}

int Entity::getMpMax()
{
    return mpMax;
}

int Entity::getAtt()
{
    return att;
}

int Entity::getDef()
{
    return def;
}

int Entity::getSpd()
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

void Entity::takeDamage(int deg)
{
    hp -= deg;
    if (hp < 0) hp = 0;
    else if (hp > hpMax) hp = hpMax;
}

void Entity::loseMp(int m)
{
    mp-=m;
    if (mp < 0) mp = 0;
    else if (mp > mpMax) mp = mpMax;
}

void Entity::restaureHp(int hpHeal)
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

string Entity::hitOpponent(Entity& target)
{
    Attack* a = dynamic_cast<Attack*>(attack);
    a->call(*this, target);
    return a->getSummary();
}

bool Entity::isAlive()
{
    return (hp == 0);
}

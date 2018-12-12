#include "skill.h"
#include "logic/entities/entity.h"

using namespace std;

Skill::Skill() :
    mpCost(0),
    range(self),
    hitEffect(miss)
{}

Skill::Skill(string n,
             string t,
             int m_mpCost,
             Range c):
    name(n),
    text(t),
    mpCost(m_mpCost),
    range(c),
    hitEffect(miss)
{}


Skill::~Skill()
{
}

string Skill::getName()
{
    return name;
}

string Skill::getText()
{
    return text;
}

int Skill::getMpCost()
{
    return mpCost;
}

vector<int> Skill::call(Entity* user, vector<Entity*> targets)
{
    return vector<int>(0);
}

string Skill::getSummary()
{
    return summary;
}

Range Skill::getRange()
{
    return range;
}

bool Skill::hasMiss()
{
    if(hitEffect == miss)
        return true;
    else
        return false;
}

string Skill::setSummary(string s)
{
    summary = s;
    return summary;
}

void Skill::payMp(Entity* e)
{
    if(e->getMp() >= mpCost)
        e->loseMp(mpCost);
}

int effect(Entity* user, Entity* target)
{
    return 0;
}

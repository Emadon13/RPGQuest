#include "skill.h"
#include "logic/entities/entity.h"

using namespace std;

Skill::Skill() :
    mpCost(0),
    range(one)
{}

Skill::Skill(string n,
             string t,
             int m_mpCost,
             Range c):
    name(n),
    text(t),
    mpCost(m_mpCost),
    range(c)
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

int Skill::call()
{
    return 0;
}

string Skill::getSummary()
{
    return summary;
}

string Skill::setSummary(string s)
{
    summary = s;
    return summary;
}

void Skill::payMp(Entity& e)
{
    if(e.getMp() >= mpCost)
        e.loseMp(mpCost);
}


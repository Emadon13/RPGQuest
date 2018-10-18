#include "skill.h"

Skill::Skill() :
    mpCost(0),
    categories(0)
{}

Skill::Skill(int m_mpCost):
    mpCost(m_mpCost),
    categories(0)
{}


Skill::~Skill()
{
}

void Skill::call()
{
}


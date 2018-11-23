#include "skill.h"

using namespace std;

Skill::Skill() :
    mpCost(0),
    categories(0)
{}

Skill::Skill(string n,
             string t,
             int m_mpCost,
             vector<Category> c):
    name(n),
    text(t),
    mpCost(m_mpCost),
    categories(c)
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

void Skill::call()
{
}


#include "drain.h"

using namespace std;

Drain::Drain():
    Skill("Vampipoutou",
          "Baiser qui restaure 1/2 des dégats infligés",
          3,
          vector<Category>(1,one)),
    coef(1),
    rate(1.2)
{

}


Drain::Drain(string n,
                     string t,
                     int mp,
                     vector<Category> cat,
                     double c,
                     double r):
    Skill(n, t, mp, cat),
    coef(c),
    rate(r)
{

}



Drain::~Drain()
{
}
/*
vector<int> Drain::call(Entity& user, vector <Entity> targets)
{
    vector<int> drains;

    for(unsigned long long i=0 ; i < targets.size() ; i++)
    {
        int drain;
        drain = int(user.hitOpponent(targets.at(i)) * rate);
        user.takeDamage(drain);
        drains.push_back(drain);
    }

    return drains;
}
*/

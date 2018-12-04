#include "recoil.h"

using namespace std;
/*
Recoil::Recoil():
    Skill("Vampipoutou",
          "Baiser qui restaure 1/2 des dégats infligés",
          3,
          vector<Category>(1,one)),
    coef(1),
    rate(1.2)
{

}


Recoil::Recoil(string n,
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



Recoil::~Recoil()
{
}


vector<int> Recoil::call(Entity& user, vector <Entity> targets)
{
    vector<int> recoils;

    for(unsigned long long i=0 ; i < targets.size() ; i++)
    {
        int recoil;
        recoil = int(user.hitOpponent(targets.at(i)) * rate);
        user.takeDamage(recoil);
        recoils.push_back(recoil);
    }

    return recoils;
}
*/

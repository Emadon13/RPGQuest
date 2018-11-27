#include "recover.h"

using namespace std;

Recover::Recover():
    Skill("Soin",
          "Un sort de soin basique",
          2,
          vector<Category>(1,one)),
    coef(1)
{

}

Recover::Recover(string n,
                 string t,
                 int mp,
                 vector<Category> cat,
                 double c):
    Skill(n,t,mp,cat),
    coef(c)
{

}

Sheet Recover::call(Entity& user, vector<Entity> targets)
{
    vector<int> hpHeals;
    for (unsigned i=0 ; i<targets.size() ; i++)
    {
        int hpHeal;
        hpHeal = int((user.getLvl() * 2 + targets.at(i).getLvl()) * coef);
        hpHeals.push_back(hpHeal);
    }

    return Sheet();

}

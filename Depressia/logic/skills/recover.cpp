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

string Recover::call(Entity& user, Entity& target)
{
    stringstream sstr;
    int hpHeal = int((user.getLvl() * 2 + target.getLvl()) * coef);
    sstr << user.getName() << " utilise " << name << " sur " << target.getName() << " !<br>"
         << hpHeal << " PVs soignés !";
    return sstr.str();
}





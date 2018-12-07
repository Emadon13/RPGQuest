#include "recover.h"

using namespace std;

Recover::Recover():
    Skill("Soin",
          "Un sort de soin basique",
          2,
          one),
    coef(1)
{

}

Recover::Recover(string n,
                 string t,
                 int mp,
                 Range rng,
                 double c):
    Skill(n,t,mp,rng),
    coef(c)
{

}

Recover::~Recover()
{

}

vector<int> Recover::call(Entity& user, vector<Entity> targets)
{
    //payMp(user);

    int hph;
    vector<int> hpsHeal(0);
    vector<string> targetNames(0);
    for (unsigned i=0 ; i<targets.size() ; i++)
    {

        hph = Recover::effect(user, targets.at((i)));
        hpsHeal.push_back(hph);
        targetNames.push_back(targets.at(i).getName());
    }
    setSummary(user.getName(), targetNames, hpsHeal);

    return hpsHeal;
}

int Recover::effect(Entity& user, Entity& target)
{
    int rdm(rand() % 10);
    int signe((rand() % 3)-1);
    int hpHeal(int((user.getLvl() * 2 + target.getLvl()) * coef));
    hpHeal = hpHeal+int(hpHeal*rdm*signe*0.1);
    target.restaureHp(hpHeal);

    return hpHeal;
}


void Recover::setSummary(string user, vector<string> targets, vector<int> hpsHeal)
{
    stringstream sstr;
    sstr << user << " utilise " << name << " !<br>";
    for (unsigned i=0 ; i<targets.size() ; i++)
    {
        sstr << targets.at(i) << " regagne " << hpsHeal.at(i) << " PVs !<br>";
    }
    summary = sstr.str();
}




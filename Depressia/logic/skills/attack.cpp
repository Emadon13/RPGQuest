#include "attack.h"

using namespace std;

Attack::Attack():
    Skill("Attaque", "L'attaque de base", 0, one),
    coef(1.0)
{

}

Attack::Attack(string n,
               string t,
               int mp,
               Range rng,
               double c):
    Skill(n, t, mp, rng),
    coef(c)

{

}

Attack::~Attack()
{

}

int Attack::call(Entity& user, Entity& target)
{
    int hit = rand() % 10;
    int deg;
    float critcoef;
    HitEffect he;

    payMp(user);

    if(hit == 0)
    {
        critcoef = 0;
        he = miss;
    }

    else if(hit == 9)
    {
        critcoef = 2;
        he = critical;
    }

    else
    {
        critcoef = 1;
        he = normal;
    }

    deg = Attack::effect(user, target, critcoef);

    setSummary(he, user.getName(), target.getName(),deg);

    return deg;
}

vector <int> Attack::call(Entity& user, vector<Entity> targets)
{
    int hit = rand() % 10;
    vector <int> degs(0);
    vector<string> targetNames;
    float critcoef;
    HitEffect he;

    payMp(user);

    if(hit == 0)
    {
        critcoef = 0;
        he = miss;
    }

    else if(hit == 9)
    {
        critcoef = 2;
        he = critical;
    }

    else
    {
        critcoef = 1;
        he = normal;
    }

    for (unsigned i=0 ; i<targets.size(); i++)
    {
        targetNames.push_back(targets.at(i).getName());
        degs.push_back(Attack::effect(user, targets.at(i), critcoef));
    }



    setSummary(he, user.getName(), targetNames, degs);

    return degs;
}

int Attack::effect(Entity& user, Entity& target, float critcoef)
{
    int deg;
    if (target.getDef() <= 0)
    {
        deg = int(user.getAtt()*user.getLvl()*coef*double(critcoef));
    }

    else
    {
        deg = int((user.getAtt()*user.getLvl()*coef*double(critcoef)) / (target.getDef()));
    }

    if (deg > target.getHp()) deg = target.getHp();

    target.takeDamage(deg);

    return deg;

}

void Attack::setSummary(HitEffect he, string user, string target, int deg)
{
    stringstream sstr;
    if(coef == 1.0)
        sstr << user << " attaque " << target << " !<br>";
    else
        sstr << user << " utilise " << name << " sur " << target << " !<br>";
    if (he == miss)
        sstr << "Mais échoué ! ";

    else
    {
        if (he == critical)
            sstr << "COUP CRITIQUE !<br>";
        sstr << target << " perd " << deg << " PVs !";
    }

    summary = sstr.str();
}

void Attack::setSummary(HitEffect he, string user, vector<string> targets, vector<int> degs)
{
    stringstream sstr;
    sstr << user << " utilise " << name << " !<br>";
    if (he == miss)
        sstr << "Mais échoué ! ";

    else
    {
        if (he == critical)
            sstr << "COUP CRITIQUE !<br>";

        for(unsigned i=0 ; i<targets.size() ; i++)
            sstr << targets.at(i) << " perd " << degs.at(i) << " PVs !";
    }

    summary = sstr.str();
}


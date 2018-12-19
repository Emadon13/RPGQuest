#include "attack.h"

using namespace std;

Attack::Attack():
    Skill("Attaque", "L'attaque de base", "../ressources/sprites/skills/eclate-roc.txt",0, one_enemy),
    coef(1.0)
{

}

Attack::Attack(string n,
               string t,
               string s,
               int mp,
               Range rng,
               float c):
    Skill(n, t, s, mp, rng),
    coef(c)

{

}

Attack::~Attack()
{

}

vector <int> Attack::call(Entity* user, vector<Entity*> targets)
{
    int hit = rand() % 10;
    vector <int> degs(0);
    vector<string> targetNames;

    payMp(user);

    if(hit == 0)
    {
        hitEffect = miss;
    }

    else if(hit == 9)
    {
        hitEffect = critical;
    }

    else
    {
        hitEffect = normal;
    }

    for (unsigned i=0 ; i<targets.size(); i++)
    {
        targetNames.push_back(targets.at(i)->getName());
        degs.push_back(Attack::effect(user, targets.at(i)));
    }



    setSummary(user->getName(), targetNames, degs);
    return degs;
}

int Attack::effect(Entity* user, Entity* target)
{
    int totalAtt, totalDef, deg;

    if (hitEffect == 0)
        return 0;

    else
    {
        totalAtt = int(user->getAtt()*user->getLvl()*coef*user->getBuffs()->getCoef(buffAttack));
        totalDef = int(target->getDef()*target->getBuffs()->getCoef(buffDefense));

        if(totalDef <= 0)
            deg = totalAtt;
        else
            deg = totalAtt/totalDef;

        if (deg > target->getHp())
            deg = target->getHp();

        target->takeDamage(deg);
    }
    return deg;
}

void Attack::setSummary(string user, vector<string> targets, vector<int> degs)
{
    stringstream sstr;
    if((fabs(coef - float(1.0)) < float(0.001)))
    {
        sstr << user << " attaque ";
        if(targets.size() == 1)
            sstr << targets.at(0);
    }

    else
    {
        sstr << user << " utilise " << name;
        if(targets.size() == 1)
            sstr << " sur " << targets.at(0);
    }

    sstr << " !<br>";

    if (hitEffect == miss)
        sstr << "Mais échoué ! ";

    else
    {
        if (hitEffect == critical)
            sstr << "COUP CRITIQUE !<br>";

        for(unsigned i=0 ; i<targets.size() ; i++)
            sstr << targets.at(i) << " perd " << degs.at(i) << " PVs !";
    }

    summary = sstr.str();
}


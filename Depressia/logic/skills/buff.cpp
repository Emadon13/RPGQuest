#include "buff.h"

using namespace std;
Buff::Buff():
    Skill("Armure",
          "Augmente la défense.",
          "",
          2,
          self)
{
    wayToBuff[0] = noBuff;
    wayToBuff[0] = buffUp;
    wayToBuff[0] = noBuff;
}

Buff::Buff(string n,
           string t,
           string s,
           int mp,
           Range rng,
           WayToBuff att,
           WayToBuff def,
           WayToBuff spd):

    Skill(n,t,s,mp,rng)
{
    wayToBuff[0] = att;
    wayToBuff[1] = def;
    wayToBuff[2] = spd;
}

Buff::~Buff()
{

}
vector<int> Buff::call(Entity* user, std::vector<Entity*> targets)
{
    payMp(user);
    vector<string> targetNames;

    for (unsigned i=0 ; i<targets.size() ; i++)
    {
        effect(targets.at(i));
        targetNames.push_back(targets.at(i)->getName());
    }
    setSummary(user->getName(), targetNames);

    return vector<int>(0);
}

int Buff::effect(Entity* target)
{
    if(wayToBuff[0]==buffUp)
        target->getBuffs()->buff(buffAttack);
    else if(wayToBuff[0]==buffDown)
        target->getBuffs()->debuff(buffAttack);

    if(wayToBuff[1]==buffUp)
        target->getBuffs()->buff(buffDefense);
    else if(wayToBuff[1]==buffDown)
        target->getBuffs()->debuff(buffDefense);

    if(wayToBuff[2]==buffUp)
        target->getBuffs()->buff(buffSpeed);
    else if(wayToBuff[2]==buffDown)
        target->getBuffs()->debuff(buffSpeed);

    return 0;
}


void Buff::setSummary(string user, vector<string> targets)
{
    stringstream sstr;
    sstr << user << " utilise " << name << " !<br>";
    for (unsigned i=0 ; i<targets.size() ; i++)
        for (unsigned j=0 ; j<BuffStats::nbStats ; j++)
        {
            if(wayToBuff[j]!=noBuff)
            {
                if(j==0)
                    sstr << "L'attaque de " << targets[i];
                else if(j==1)
                    sstr << "La defense de " << targets[i];
                else if(j==2)
                    sstr << "La vitesse de " << targets[i];

                if(wayToBuff[j]==buffUp)
                    sstr << " a augmentée ! ";
                else if(wayToBuff[j]==buffDown)
                    sstr << " a diminuée ! ";

            }
        }
    summary = sstr.str();
}

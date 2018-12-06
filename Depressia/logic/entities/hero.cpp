#include "hero.h"

using namespace std;

Hero::Hero():
    xp(0),
    base_hp(100),
    base_mp(20),
    base_att(10),
    base_def(10),
    base_spd(10)

{
    Entity("toto",
           1,
           int(base_hp*(lvl/max_lvl)),
           int(base_mp*(lvl/max_lvl)),
           int(base_att*(lvl/max_lvl)),
           int(base_def*(lvl/max_lvl)),
           int(base_spd*(lvl/max_lvl)),
           "",
           "",
           vector<Skill*>(0));

    calculateLevel();

}

Hero::Hero(string n,
           int l,
           int b_hp,
           int b_mp,
           int b_att,
           int b_def,
           int b_spd,
           string spr,
           string bi,
           vector<Skill*> s,
           string stl[max_lvl]):
    xp(0),
    base_hp(b_hp),
    base_mp(b_mp),
    base_att(b_att),
    base_def(b_def),
    base_spd(b_spd)

{

    for(int i=0 ; i<max_lvl ; i++)
        skillsToLearn[i] = stl[i];

    Entity(n,
           l,
           int(base_hp*(lvl/max_lvl)),
           int(base_mp*(lvl/max_lvl)),
           int(base_att*(lvl/max_lvl)),
           int(base_def*(lvl/max_lvl)),
           int(base_spd*(lvl/max_lvl)),
           spr,
           bi,
           vector<Skill*>(s));

    calculateLevel();

}

int Hero::getXp()
{
    return xp;
}

bool Hero::addXp(int i)
{
    xp += i;
    if(xp>=next_level)
    {
        lvl++;
        calculateLevel();
        return true;
    }

    return false;
}


void Hero::calculateLevel()
{

    hpMax = int(base_hp*0.1*lvl) ;
    mpMax = int(base_mp*0.1*lvl) ;
    att = int(base_att*0.1*lvl) ;
    def = int(base_def*0.1*lvl) ;
    spd = int(base_spd*0.1*lvl) ;
    next_level = lvl*lvl*10;
}


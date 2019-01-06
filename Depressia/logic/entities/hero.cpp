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
           "",
           "",
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
           std::string sn,
           std::string sd,
           std::string sa,
           std::string ss,
           std::string sk,
           string bi,
           vector<Skill*> s,
           string stl[max_lvl],
           string path):

    Entity(n, l, 1, 1, 1, 1, 1, sn, sd, sa, ss, sk, bi, vector<Skill*>(s)),
    xp(0),
    base_hp(b_hp),
    base_mp(b_mp),
    base_att(b_att),
    base_def(b_def),
    base_spd(b_spd),
    saveLink(path)
{
    for(int i=0 ; i<max_lvl ; i++)
        skillsToLearn[i] = stl[i];

    calculateLevel();
}

int Hero::getXp()
{
    return xp;
}

int Hero::getNextLevel()
{
    return next_level;
}

SpriteLoop* Hero::getSpriteKilled()
{
    return dynamic_cast<SpriteLoop*>(sprites[4]);
}

string Hero::getSaveLink()
{
    return saveLink;
}

bool Hero::addXp(int i)
{
    bool hasEvolve = false;
    xp += i;
    while(xp>=next_level)
    {
        lvl++;
        calculateLevel();
        hasEvolve = true;
    }

    return hasEvolve;
}


void Hero::calculateLevel()
{

    hpMax = int(base_hp*0.1*lvl) ;
    mpMax = int(base_mp*0.1*lvl) ;
    hp = hpMax;
    mp = mpMax;
    att = int(base_att*0.1*lvl) ;
    def = int(base_def*0.1*lvl) ;
    spd = int(base_spd*0.1*lvl) ;

    if(skillsToLearn[lvl] != "")
        skills.push_back(SkillLoader::generate(skillsToLearn[lvl]));

    next_level = lvl*lvl*10;
}


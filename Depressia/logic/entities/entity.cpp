#include "entity.h"
#include <string>

using namespace std;

Entity::Entity() :
    name("RandomMOB"),
    lvl(1),
    hpMax(2),
    mpMax(0),
    hp(hpMax),
    mp(mpMax),
    att(1),
    def(1),
    spd(1),
    skills(0),
    attack(new Attack()),
    sprite(""),
    battleIcon("")
{
}

Entity::Entity(string m_name,
               int m_lvl,
               int m_hpMax,
               int m_mpMax,
               int m_att,
               int m_def,
               int m_spd,
               string s,
               string bi,
               vector<Skill*> m_skills):
    name(m_name),
    lvl(m_lvl),
    hpMax(m_hpMax),
    mpMax(m_mpMax),
    hp(m_hpMax),
    mp(m_mpMax),
    att(m_att),
    def(m_def),
    spd(m_spd),
    skills(m_skills),
    attack(new Attack()),
    sprite(s),
    battleIcon(bi)
{
}


Entity::~Entity()
{}


string Entity::getName()
{
    return name;
}

int Entity::getLvl()
{
    return lvl;
}


int Entity::getHp()
{
    return hp;
}

int Entity::getMp()
{
    return mp;
}

int Entity::getHpMax()
{
    return hpMax;
}

int Entity::getMpMax()
{
    return mpMax;
}

int Entity::getAtt()
{
    return att;
}

int Entity::getDef()
{
    return def;
}

int Entity::getSpd()
{
    return spd;
}

Skill Entity::getSkill(int i)
{
    if(skills.at(unsigned (i)) != NULL)
        return *(skills.at(unsigned(i)));

    else
    {
        cout << "ERREUR : Le " << i << "-ième sort de " << name << " n'existe pas" << endl;
        return Skill();
    }
}

int Entity::getSkillsSize()
{
    return int(skills.size());
}

void Entity::takeDamage(int deg)
{
    hp -= deg;
    if (hp < 0) hp = 0;
    else if (hp > hpMax) hp = hpMax;
}

void Entity::loseMp(int m)
{
    mp-=m;
    if (mp < 0) mp = 0;
    else if (mp > mpMax) mp = mpMax;
}

void Entity::restaureHp(int hpHeal)
{
    hp += hpHeal;
    if (hp < 0) hp = 0;
    else if (hp > hpMax) hp = hpMax;
}

void Entity::restaureMp(const int mpHeal)
{
    mp += mpHeal;
    if (mp < 0) mp = mpMax;
}

string Entity::hitOpponent(Entity& target)
{
    Attack* a = dynamic_cast<Attack*>(attack);
    a->call(*this, target);
    return a->getSummary();
}

bool Entity::isAlive()
{
    return (hp == 0);
}

std::string Entity::getSprite()
{
    return sprite;
    /*
    vector<string> spriteElements =  SpriteLoader::generate(sprite);
    string nn, nw, nh, ns, dn, dw, dh, ds, an, aw, ah, as, sn, sw, sh, ss, kn, kw, kh, ks;
    nn = spriteElements.at(0);
    nw = spriteElements.at(1);
    nh = spriteElements.at(2);
    ns = spriteElements.at(3);
    dn = spriteElements.at(4);
    dw = spriteElements.at(5);
    dh = spriteElements.at(6);
    ds = spriteElements.at(7);
    an = spriteElements.at(8);
    aw = spriteElements.at(9);
    ah = spriteElements.at(10);
    as = spriteElements.at(11);
    sn = spriteElements.at(12);
    sw = spriteElements.at(13);
    sh = spriteElements.at(14);
    ss = spriteElements.at(15);
    kn = spriteElements.at(16);
    kw = spriteElements.at(17);
    kh = spriteElements.at(18);
    ks = spriteElements.at(19);

    return new Sprite(int(stoi(nn)), int(stoi(nw)), int(stoi(nh)), ns,
                      int(stoi(dn)), int(stoi(dw)), int(stoi(dh)), ds,
                      int(stoi(an)), int(stoi(aw)), int(stoi(ah)), as,
                      int(stoi(sn)), int(stoi(sw)), int(stoi(sh)), ss,
                      int(stoi(kn)), int(stoi(kw)), int(stoi(kh)), ks);
*/
}

QPixmap Entity::getBattleIcon()
{
    return QPixmapLoader::generate(battleIcon);
}

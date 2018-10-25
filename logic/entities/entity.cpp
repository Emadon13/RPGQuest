#include "entity.h"
#include <QString>

Entity::Entity() :
	name("RandomMOB"),
	lvl(1),
	hpMax(2),
	mpMax(0),
	hp(2),
	mp(0),
	att(1),
	def(1),
	spd(1),
	skills(0)
{}

<<<<<<< HEAD
Entity::Entity(std::string m_name,
               int m_lvl,
               int m_hpMax,
               int m_mpMax,
               int m_hp,
               int m_mp,
               int m_att,
               int m_def,
               int m_spd,
               std::vector<Skill> m_skills)
{
    name = m_name;
=======
Entity::Entity(QString m_name, int m_lvl, int m_hpMax, int m_mpMax, int m_hp, int m_mp, int m_att, int m_def, int m_spd, QVector<Skill> m_skills)
{
    QString name;
>>>>>>> parent of 5f3c68b... entity loader
	lvl = m_lvl;
	hpMax = m_hpMax;
	mpMax = m_mpMax;
	hp = m_hp;
	mp = m_mp;
	att = m_att;
	def = m_def;
	spd = m_spd;
	skills = m_skills;
}


Entity::~Entity()
{}


QString Entity::getName() const
{
	return name;
}

int Entity::getLvl() const
{
	return lvl;
}


int Entity::getHp() const
{
	return hp;
}

int Entity::getMp() const
{
	return mp;
}

int Entity::getAtt()  const
{
	return att;
}

int Entity::getDef() const
{
	return def;
}

int Entity::getSpd() const
{
	return spd; 
}

void Entity::takeDamage(const int deg)
{
	hp -= deg;
	if (hp < 0) hp = 0;
	else if (hp > hpMax) hp = hpMax;
}

void Entity::restaureHp(const int hpHeal)
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

int Entity::hitOpponent(Entity& target)
{
	int deg;

	if (target.getDef() <= 0)
	{
        deg = int (att*lvl);
	}

	else
	{
        deg = int ((att*lvl) / (target.getDef()));
	}

	if (deg > target.getHp()) deg = target.getHp();

	target.takeDamage(deg);
	return deg;
}

int Entity::hitOpponent(Entity& target, const double coef)
{
	int deg;

	if (target.getDef() <= 0)
	{
        deg = int (att*lvl*coef);
	}

	else
	{
        deg = int ((att*lvl*coef) / (target.getDef()));
	}
	
	if (deg > target.getHp()) deg = target.getHp();

	target.takeDamage(deg);
	return deg;
}

bool Entity::isAlive() const
{
	return (hp == 0);
}

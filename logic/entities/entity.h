#ifndef ENTITY_H
#define ENTITY_H

<<<<<<< HEAD
=======

#include <QString>
#include <QVector>
>>>>>>> parent of 5f3c68b... entity loader
#include "logic/skills/skill.h"


class Entity
{
public:
    Entity();
    Entity(QString m_name,
    int m_lvl,
    int m_hpMax,
    int m_mpMax,
    int m_hp,
    int m_mp,
    int m_att,
    int m_def,
    int m_spd,
    std::vector<Skill>m_skills);
    ~Entity();

    QString getName() const;
    int getLvl() const;
    int getHp() const;
    int getMp() const;
    int getAtt() const;
    int getDef() const;
    int getSpd() const;

    void takeDamage(const int deg);
    void restaureHp(const int hpHeal);
    void restaureMp(const int mpHeal);
    int hitOpponent(Entity& target);
    int hitOpponent(Entity& target, const double coef);

    bool isAlive() const;





private:

    QString name;
    int lvl;
    int hpMax;
    int mpMax;
    int hp;
    int mp;
    int att;
    int def;
    int spd;
    std::vector<Skill>skills;



};

#endif // ENTITY_H

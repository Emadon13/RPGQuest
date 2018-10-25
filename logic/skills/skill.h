#ifndef SKILL_H
#define SKILL_H


#include<QString>
#include<QVector>

enum category { powerfull, powerless, heal, drain, recoil, group, all, several };

class Skill
{
public:
    Skill();
    Skill(int m_mpCost);
    ~Skill();
    void call();


protected:
    std::string name;
    std::string description;
    int mpCost;
    QVector <category> categories;

};



#endif // SKILL_H

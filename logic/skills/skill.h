#ifndef SKILL_H
#define SKILL_H


#include <string>
#include <vector>

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
    std::vector <category> categories;

};



#endif // SKILL_H

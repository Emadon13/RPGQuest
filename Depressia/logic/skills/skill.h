#ifndef SKILL_H
#define SKILL_H

#include<string>
#include<vector>
#include "logic/skills/sheet.h"

enum Category { one, group, all, several };

class Entity;
class Skill
{
public:
    Skill();
    Skill(std::string n, std::string t, int m_mpCost, std::vector<Category>);
    ~Skill();

    std::string getName();
    std::string getText();
    int getMpCost();
    Sheet call();


protected:
    std::string name;
    std::string text;
    int mpCost;
    std::vector <Category> categories;

};



#endif // SKILL_H

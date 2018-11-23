#ifndef SKILL_H
#define SKILL_H

#include<string>
#include<vector>

enum Category { powerfull, powerless, heal, drain, recoil, group, all, several };

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
    void call();


protected:
    std::string name;
    std::string text;
    int mpCost;
    std::vector <Category> categories;

};



#endif // SKILL_H

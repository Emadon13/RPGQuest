#pragma once

#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <sstream>
#include <vector>

enum HitEffect {miss, normal, critical};
enum Range { one, group, all, several };

class Entity;
class Skill
{
public:
    Skill();
    Skill(std::string n, std::string t, int m_mpCost, Range);
    virtual ~Skill();

    std::string getName();
    std::string getText();
    int getMpCost();
    std::string getSummary();
    virtual std::vector<int> call(Entity& user, std::vector<Entity*> targets);


protected:
    std::string name;
    std::string text;
    int mpCost;
    Range range;
    std::string summary;

    std::string setSummary(std::string s);
    void payMp(Entity& e);
    int effect(Entity& user, Entity& target);


};



#endif // SKILL_H

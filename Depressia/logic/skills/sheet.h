#ifndef SHEET_H
#define SHEET_H

#include <string>
#include <sstream>
#include <vector>

enum HitEffect {normal, critical, miss};
enum SkillType {attack, recover, drain, recoil};
class Sheet
{
public:
    Sheet();
    Sheet(std::string u,
          std::string sn,
          std::vector<std::string> t,
          bool is,
          std::vector<int> d,
          int a,
          std::vector<HitEffect> he,
          SkillType st);

    std::vector<std::string> toString();

private:
    std::string user;
    std::string skillName;
    std::vector<std::string> targets;
    bool isSkill;
    std::vector<int> damages;
    int aftermath;
    std::vector<HitEffect> hitEffects;
    SkillType skillType;




};

#endif // SHEET_H

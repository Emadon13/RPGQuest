#ifndef SKILLLOADER_H
#define SKILLLOADER_H

#include "loader.h"
#include "logic/skills/skill.h"
#include "logic/skills/attack.h"
#include "logic/skills/recover.h"

class SkillLoader : public Loader
{
public:
    SkillLoader();
    static Skill* generate();
    static Skill* generate(std::string path);

private:
    static Range compareRange(std::string range);

};

#endif // SKILLLOADER_H

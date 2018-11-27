#ifndef SKILLLOADER_H
#define SKILLLOADER_H

#include"loader.h"
#include"logic/skills/skill.h"


class SkillLoader : public Loader
{
public:
    SkillLoader();
    static Skill generate();
    static Skill generate(std::string path);

};

#endif // SKILLLOADER_H

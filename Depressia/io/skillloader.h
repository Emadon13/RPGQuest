#pragma once

#ifndef SKILLLOADER_H
#define SKILLLOADER_H

#include "logic/skills/skill.h"
#include "logic/skills/attack.h"
#include "logic/skills/recover.h"
#include "logic/skills/buff.h"

class SkillLoader
{
public:
    SkillLoader();
    static Skill* generate();
    static Skill* generate(std::string path);

private:
    static Range compareRange(std::string range);
    static WayToBuff compareWayToBuff(std::string wtb);

};

#endif // SKILLLOADER_H

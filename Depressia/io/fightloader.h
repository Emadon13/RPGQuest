#ifndef FIGHTLOADER_H
#define FIGHTLOADER_H

#include "io/entityloader.h"
#include "logic/entities/team.h"

class FightLoader
{
public:
    FightLoader();

    static Fight generate();
    static Fight generate(Team* team, std::string path);
};

#endif // FIGHTLOADER_H

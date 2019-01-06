#ifndef GAMELOADER_H
#define GAMELOADER_H

#include "logic/game.h"

class GameLoader
{
public:
    GameLoader();
    static Game generate();
    static Game generate(std::string path);
};

#endif // GAMELOADER_H

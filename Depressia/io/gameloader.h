#ifndef GAMELOADER_H
#define GAMELOADER_H

#include "logic/game.h"
#include "io/entityloader.h"

class GameLoader
{
public:
    GameLoader();
    static Game generate(std::string path);
    static void save(Game game);
};

#endif // GAMELOADER_H

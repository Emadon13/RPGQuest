#ifndef GAME_H
#define GAME_H

#include"io/maploader.h"


class Game
{
public:
    Game();
    Map getMap();

private:
    Map map;

};

#endif // GAME_H

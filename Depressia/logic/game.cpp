#include "game.h"

Game::Game()
{
    map = MapLoader::generate("../ressources/maps/map.txt");
}

Map Game::getMap()
{
    return map;
}

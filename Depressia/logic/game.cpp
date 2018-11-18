#include "game.h"

Game::Game()
{
    map = MapLoader::generate("../ressources/maps/map.txt");
}

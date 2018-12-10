#ifndef MAPLOADER_H
#define MAPLOADER_H

#include"logic/world/map.h"

class MapLoader
{
public:
    MapLoader();

    static Map generate();
    static Map generate(Team* t, std::string s);
};

#endif // MAPLOADER_H

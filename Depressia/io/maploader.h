#ifndef MAPLOADER_H
#define MAPLOADER_H

#include"io/loader.h"
#include"logic/world/map.h"

class MapLoader : public Loader
{
public:
    MapLoader();

    static Map generate();
    static Map generate(std::string);
};

#endif // MAPLOADER_H

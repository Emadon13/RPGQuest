#pragma once
#ifndef MAPELEMENTLOADER_H
#define MAPELEMENTLOADER_H

#include"io/loader.h"
#include"logic/world/mapelement.h"

class MapElementLoader
{
public:
    MapElementLoader();

    static MapElement generate();
    static MapElement generate(std::string);

};

#endif // MAPELEMENTLOADER_H

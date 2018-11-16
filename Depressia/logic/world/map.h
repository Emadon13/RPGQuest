#ifndef MAP_H
#define MAP_H

#include"logic/world/mapelement.h"


class Map
{
public:
    Map();
    MapElement* getCurrentWindow();

private:
    MapElement* currentWindow;
    MapElement worldMap[100];

};

#endif // MAP_H

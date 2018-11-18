#ifndef MAP_H
#define MAP_H

#include"logic/world/mapelement.h"


class Map
{
public:
    Map();
    Map(std::vector<MapElement> wm, std::vector<unsigned int> r, std::vector<unsigned int> u, std::vector<unsigned int> l, std::vector<unsigned int> d);
    MapElement getCurrentPosition();
    int getNbElements();

    MapElement goRight();
    MapElement goUp();
    MapElement goLeft();
    MapElement goDown();

private:
    unsigned int nbElements;
    unsigned int currentPosition;
    std::vector<MapElement> elements;
    std::vector<unsigned int> rights;
    std::vector<unsigned int> ups;
    std::vector<unsigned int> lefts;
    std::vector<unsigned int> downs;

};

#endif // MAP_H

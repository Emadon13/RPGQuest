#include "map.h"
#include <iostream>

using namespace std;

Map::Map():
    elements(0),
    rights(0),
    ups(0),
    lefts(0),
    downs(0)
{

    MapElement w1("Forêt", "La forêt est calme et sereine...", "../ressources/images/background.png", vector<Event>(0));
    elements.push_back(w1);
    rights.push_back(0);
    ups.push_back(0);
    lefts.push_back(0);
    downs.push_back(0);
    currentPosition = 0;

}


Map::Map(vector<MapElement> wm, vector<unsigned int> r, vector<unsigned int> u, vector<unsigned int> l, vector<unsigned int> d):
    elements(wm),
    rights(r),
    ups(u),
    lefts(l),
    downs(d)
{
    if(elements.empty())
    {
        MapElement w1("Forêt", "La forêt est calme et sereine...", "", vector<Event>(0));
        elements.push_back(w1);
        rights.push_back(0);
        ups.push_back(0);
        lefts.push_back(0);
        downs.push_back(0);
        currentPosition = 0;
    }

    else
        currentPosition = 0;

}


MapElement Map::getCurrentPosition()
{
    if(currentPosition >= elements.size())
        return elements.at(currentPosition);
    else
        cout << "ERREUR : currentPosition a dépasser la taille d'elements" << endl;
        return MapElement();
}

int Map::getNbElements()
{
    return int(nbElements);
}

MapElement Map::goRight()
{
    currentPosition = rights.at(currentPosition);
    return elements.at(currentPosition);
}

MapElement Map::goUp()
{
    currentPosition = ups.at(currentPosition);
    return elements.at(currentPosition);
}

MapElement Map::goLeft()
{
    currentPosition = lefts.at(currentPosition);
    return elements.at(currentPosition);
}

MapElement Map::goDown()
{
    currentPosition = downs.at(currentPosition);
    return elements.at(currentPosition);
}

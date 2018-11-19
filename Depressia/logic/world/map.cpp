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

    elements.push_back("");
    rights.push_back(0);
    ups.push_back(0);
    lefts.push_back(0);
    downs.push_back(0);
    currentPosition = 0;

}


Map::Map(vector<string> wm, vector<unsigned int> r, vector<unsigned int> u, vector<unsigned int> l, vector<unsigned int> d):
    eventHapp(wm.size(), false),
    elements(wm),
    rights(r),
    ups(u),
    lefts(l),
    downs(d)
{
    if(elements.empty())
    {
        elements.push_back("");
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
    if(currentPosition < elements.size())
        return MapElementLoader::generate(elements.at(currentPosition));
    else
        cout << "ERREUR : currentPosition a dépasser la taille d'elements" << endl;
        return MapElement();
}

int Map::getNbElements()
{
    return int(elements.size());
}

MapElement Map::goRight()
{
    currentPosition = rights.at(currentPosition);
    return MapElementLoader::generate(elements.at(currentPosition));
}

MapElement Map::goUp()
{
    currentPosition = ups.at(currentPosition);
    return MapElementLoader::generate(elements.at(currentPosition));
}

MapElement Map::goLeft()
{
    currentPosition = lefts.at(currentPosition);
    return MapElementLoader::generate(elements.at(currentPosition));
}

MapElement Map::goDown()
{
    currentPosition = downs.at(currentPosition);
    return MapElementLoader::generate(elements.at(currentPosition));
}

bool Map::existRight()
{
    return(rights.at(currentPosition) != currentPosition);
}

bool Map::existUp()
{
    return(ups.at(currentPosition) != currentPosition);
}

bool Map::existLeft()
{
    return(lefts.at(currentPosition) != currentPosition);
}

bool Map::existDown()
{
    return(downs.at(currentPosition) != currentPosition);
}

bool Map::isEventHapp()
{
    return eventHapp.at(currentPosition);
}

void Map::setEventHapp()
{
    eventHapp.at(currentPosition) = true;
}

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


Map::Map(Team* t, vector<string> wm, vector<unsigned int> r, vector<unsigned int> u, vector<unsigned int> l, vector<unsigned int> d):
    team(t),
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
    {
        currentPosition = 0;
        updateCurrentElement();
    }
}


MapElement Map::getCurrentPosition()
{
    if(currentPosition < elements.size())
        return currentElement;
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
    updateCurrentElement();
    return currentElement;
}

MapElement Map::goUp()
{
    currentPosition = ups.at(currentPosition);
    updateCurrentElement();
    return currentElement;
}

MapElement Map::goLeft()
{
    currentPosition = lefts.at(currentPosition);
    updateCurrentElement();
    return currentElement;
}

MapElement Map::goDown()
{
    currentPosition = downs.at(currentPosition);
    updateCurrentElement();
    return currentElement;
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

bool Map::isEventHapp(int i)
{
    return eventHapp.at(unsigned(i));
}

void Map::setEventHapp()
{
    if(!currentElement.getEvent()->mustRedo())
        eventHapp.at(currentPosition) = true;
}

void Map::setCurrentPosition(int i)
{
    if(unsigned(i)<elements.size())
    {
        currentPosition = unsigned(i);
        updateCurrentElement();
    }
}

void Map::setEventHapp(int i)
{
    if(unsigned(i) < eventHapp.size())
        eventHapp.at(unsigned(i)) = true;
}

void Map::updateCurrentElement()
{
    currentElement = MapElementLoader::generate(team, elements.at(currentPosition));
}

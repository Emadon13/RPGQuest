#include "mapelement.h"
#include <iostream>

using namespace std;

MapElement::MapElement():
    name("titre nul"),
    text("rien à dire..."),
    image(""),
    events(0)
{

    MapElement *left(this);
    MapElement *up(this);
    MapElement *right(this);
    MapElement *down(this);

    links[0] = left;
    links[1] = up;
    links[2] = right;
    links[3] = down;
}

MapElement::MapElement(string n, string t, string i, vector<Event> e):
    name(n),
    text(t),
    image(i),
    events(e)
{
    MapElement *left(this);
    MapElement *up(this);
    MapElement *right(this);
    MapElement *down(this);

    links[0] = left;
    links[1] = up;
    links[2] = right;
    links[3] = down;
}


string MapElement::getName()
{
    return name;
}

string MapElement::getText()
{
    return text;
}

string MapElement::getImage()
{
    return image;
}

MapElement* MapElement::getLeft()
{
    return links[0];
}

MapElement* MapElement::getUp()
{
    return links[1];
}

MapElement* MapElement::getRight()
{
    return links[2];
}

MapElement* MapElement::getDown()
{
    return links[3];
}

void MapElement::setLeft(MapElement& w)
{
    links[0] = &w;
}

void MapElement::setUp(MapElement& w)
{
    links[1] = &w;
}

void MapElement::setRight(MapElement& w)
{
    links[2] = &w;
}

void MapElement::setDown(MapElement& w)
{
    links[3] = &w;
}

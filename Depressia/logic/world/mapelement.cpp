#include "mapelement.h"
#include <iostream>

using namespace std;

MapElement::MapElement():
    name("titre nul"),
    text("rien à dire..."),
    image(""),
    events(0)
{

}

MapElement::MapElement(string n, string t, string i, vector<Event> e):
    name(n),
    text(t),
    image(i),
    events(e)
{

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


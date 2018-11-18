#include "mapelement.h"
#include <iostream>

using namespace std;

MapElement::MapElement():
    name("titre nul"),
    text("rien à dire..."),
    image(""),
    event()
{

}

MapElement::MapElement(string n, string t, string i, Event e):
    name(n),
    text(t),
    image(i),
    event(e)
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

Event MapElement::getEvent()
{
    return event;
}

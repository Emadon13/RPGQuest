#include "mapelement.h"
#include <iostream>
#include <QObject>

using namespace std;

MapElement::MapElement():
    name("titre nul"),
    text("rien à dire..."),
    image(""),
    event(0)
{

}

MapElement::MapElement(string n, string t, string i, Event* e):
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

Event* MapElement::getEvent()
{
    return event;
}

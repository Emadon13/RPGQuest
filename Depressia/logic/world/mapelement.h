#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include"logic/events/event.h"


class MapElement
{
public:
    MapElement();
    MapElement(std::string n, std::string t, std::string i, std::vector<Event> e);

    std::string getName();
    std::string getText();
    std::string getImage();


private:
    std::string name;
    std::string text;
    std::string image;
    std::vector<Event> events;
};

#endif // MAPELEMENT_H

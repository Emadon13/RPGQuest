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

    MapElement* getLeft();
    MapElement* getUp();
    MapElement* getRight();
    MapElement* getDown();


private:
    std::string name;
    std::string text;
    std::string image;
    std::vector<Event> events;
    MapElement *links[4];

    void setLeft(MapElement& w);
    void setUp(MapElement& w);
    void setRight(MapElement& w);
    void setDown(MapElement& w);
};

#endif // MAPELEMENT_H

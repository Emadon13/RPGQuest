#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include"logic/events/event.h"
#include <QObject>


class MapElement
{

public:
    MapElement();
    MapElement(std::string n, std::string t, std::string i, Event* e);
    ~MapElement();

    std::string getName();
    std::string getText();
    std::string getImage();
    Event* getEvent();


private:
    std::string name;
    std::string text;
    std::string image;
    Event* event;
};

#endif // MAPELEMENT_H

#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include<string>

class MapElement
{
public:
    MapElement();
    MapElement(std::string ti, std::string te, std::string img);

    std::string getTitle();
    std::string getText();

    MapElement* getLeft();
    MapElement* getUp();
    MapElement* getRight();
    MapElement* getDown();

    void setLeft(MapElement& w);
    void setUp(MapElement& w);
    void setRight(MapElement& w);
    void setDown(MapElement& w);

private:
    std::string title;
    std::string text;
    std::string background;

    MapElement *links[4];
};

#endif // MAPELEMENT_H

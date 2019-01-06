#pragma once
#ifndef MAP_H
#define MAP_H

#include"logic/world/mapelement.h"
#include"io/mapelementloader.h"
#include "logic/entities/team.h"


class Map
{
public:
    Map();
    Map(Team* t,std::vector<std::string> wm, std::vector<unsigned int> r, std::vector<unsigned int> u, std::vector<unsigned int> l, std::vector<unsigned int> d);
    MapElement getCurrentPosition();
    int getNbElements();

    MapElement goRight();
    MapElement goUp();
    MapElement goLeft();
    MapElement goDown();

    bool existRight();
    bool existUp();
    bool existLeft();
    bool existDown();

    bool isEventHapp();
    void setEventHapp();

    unsigned int currentPosition;
private:

    MapElement currentElement;
    void updateCurrentElement();

    Team* team;
    std::vector<bool> eventHapp;
    std::vector<std::string> elements;
    std::vector<unsigned int> rights;
    std::vector<unsigned int> ups;
    std::vector<unsigned int> lefts;
    std::vector<unsigned int> downs;

};

#endif // MAP_H

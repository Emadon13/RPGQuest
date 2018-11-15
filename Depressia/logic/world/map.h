#ifndef MAP_H
#define MAP_H

#include"logic/world/window.h"


class Map
{
public:
    Map();
    Window* getCurrentWindow();

    Window w1;
    Window w2;

private:
    Window* currentWindow;
    Window worldMap[2];

};

#endif // MAP_H

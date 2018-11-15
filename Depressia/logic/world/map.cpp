#include "map.h"
#include <iostream>

using namespace std;

Map::Map()
{
    Window w1("Forêt", "La forêt est calme et sereine...", "");
    Window w2("Montagne", "Une falaise escarpée vous bloque le passage", "");
    Window w3("Mer", "Une mer bleutée s'étend à perte de vue","");
    Window w4("Désert", "La chaleur de ce désert arride vous brûle la peau !","");
    Window w5("Château abandonné", "Ce château a du appartenir à un ancien roi");

    worldMap[0] = w1;
    worldMap[1] = w2;
    worldMap[2] = w3;
    worldMap[3] = w4;
    worldMap[4] = w5;

    worldMap[0].setDown(worldMap[1]);

    currentWindow = &worldMap[0];


}

Window* Map::getCurrentWindow()
{
    return currentWindow;
}


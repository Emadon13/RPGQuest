#include "map.h"
#include <iostream>

using namespace std;

Map::Map()
{
    MapElement w1("Forêt", "La forêt est calme et sereine...", "");
    MapElement w2("Montagne", "Une falaise escarpée vous bloque le passage", "");
    MapElement w3("Mer", "Une mer bleutée s'étend à perte de vue","");
    MapElement w4("Désert", "La chaleur de ce désert arride vous brûle la peau !","");
    MapElement w5("Château abandonné", "Ce château a du appartenir à un ancien roi","");

    worldMap[0] = w1;
    worldMap[1] = w2;
    worldMap[2] = w3;
    worldMap[3] = w4;
    worldMap[4] = w5;

    worldMap[0].setDown(worldMap[1]);
    

    currentWindow = &worldMap[0];


}

MapElement* Map::getCurrentWindow()
{
    return currentWindow;
}


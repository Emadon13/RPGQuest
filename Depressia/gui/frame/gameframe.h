#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include "gui/window/gamewindow.h"
#include "logic/world/mapelement.h"


class GameFrame : QObject
{
    Q_OBJECT

public:
    GameFrame(GameWindow *game);

private :

    Map *map;
    MapElement mapElement;
    GameWindow *game;

};

#endif // GAMEFRAME_H

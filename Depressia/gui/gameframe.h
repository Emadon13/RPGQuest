#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include "gamewindow.h"
#include "logic/world/mapelement.h"


class GameFrame : QObject
{
    Q_OBJECT

public:
    GameFrame(GameWindow *game, MapElement mapElement);

private :

    MapElement mapElement;
    GameWindow *game;

};

#endif // GAMEFRAME_H

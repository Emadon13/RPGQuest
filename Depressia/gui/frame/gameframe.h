#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include "gui/window/gamewindow.h"
#include "logic/world/mapelement.h"
#include "gui/frame/teamui.h"

class GameFrame : QObject
{
    Q_OBJECT

public:
    GameFrame(GameWindow *game);

private :

    QPushButton *settings;
    QPushButton * inventory;
    Map *map;
    MapElement mapElement;
    GameWindow *game;

    TeamUI* teamUI[Fight::nb_e];

    Hero *allie;
};

#endif // GAMEFRAME_H

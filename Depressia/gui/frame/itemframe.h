#ifndef ITEMFRAME_H
#define ITEMFRAME_H

#include "gui/window/gamewindow.h"
#include "logic/world/mapelement.h"
#include "gui/frame/teamui.h"

class ItemFrame : QObject
{
    Q_OBJECT

public:
    ItemFrame(GameWindow *game);

private :

    Map *map;
    MapElement mapElement;
    GameWindow *game;

    TeamUI* teamUI[Fight::nb_e];
    QPushButton *settings;
    Hero *allie;

};

#endif // ITEMFRAME_H

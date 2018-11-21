#ifndef ITEMFRAME_H
#define ITEMFRAME_H

#include "gui/window/gamewindow.h"
#include "logic/world/mapelement.h"

class ItemFrame : QObject
{
    Q_OBJECT

public:
    ItemFrame(GameWindow *game);

private :

    Map *map;
    MapElement mapElement;
    GameWindow *game;

};

#endif // ITEMFRAME_H

#ifndef SAVEFRAME_H
#define SAVEFRAME_H

#include "gui/window/gamewindow.h"
#include "logic/world/mapelement.h"
#include "gui/frame/teamui.h"

class SaveFrame : QObject
{
    Q_OBJECT

public:
    SaveFrame(GameWindow *game);

private:

    Map *map;
    MapElement mapElement;
    GameWindow *game;

    TeamUI* teamUI[Fight::nb_e];
    QPushButton *settings;
    QPushButton * inventory;
    Hero *allie;

};

#endif // SAVEFRAME_H

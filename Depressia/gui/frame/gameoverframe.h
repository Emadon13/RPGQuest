#ifndef GAMEOVERFRAME_H
#define GAMEOVERFRAME_H
#include "gui/window/gamewindow.h"
#include "gui/clickable/clickablelabel.h"

class GameOverFrame : QObject
{
    Q_OBJECT

public:
    GameOverFrame(GameWindow *game);

    GameWindow *game;

    ClickableLabel *clicker;
};

#endif // GAMEOVERFRAME_H

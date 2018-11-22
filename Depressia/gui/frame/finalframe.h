#ifndef FINALFRAME_H
#define FINALFRAME_H
#include "gui/window/gamewindow.h"
#include "gui/clickable/clickablelabel.h"

class FinalFrame : QObject
{
    Q_OBJECT

public:
    FinalFrame(GameWindow *game);

    GameWindow *game;

    ClickableLabel *clicker;
};

#endif // FINALFRAME_H

#ifndef TEAMUI_H
#define TEAMUI_H
#include <QObject>
#include <QProgressBar>
#include "gui/window/gamewindow.h"

class TeamUI : QObject
{
    Q_OBJECT

public slots:
    void Update();
    void openCharacterInfo();

public:
    TeamUI(GameWindow *g, Hero *e, int x, int y, int width, int height);

    GameWindow *game;

    Hero *perso;

    int posX;
    int posY;

    int height;
    int width;

    QLabel *image;
    QLabel *level;

    QProgressBar *jaugeHP;
    QProgressBar *jaugeMP;

    ClickableLabel *clicker;
};

#endif // TEAMUI_H

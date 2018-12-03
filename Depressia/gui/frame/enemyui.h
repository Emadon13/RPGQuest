#ifndef ENEMYUI_H
#define ENEMYUI_H
#include <QObject>
#include "gui/window/gamewindow.h"
#include <QProgressBar>


class EnemyUI : QObject
{
   Q_OBJECT

public:
    EnemyUI(GameWindow *g, int x, int y, int width, int height);

    GameWindow *game;

    int posX;
    int posY;

    int height;
    int width;

    QLabel *image;
    QLabel *name;
    QLabel *level;

    QProgressBar *jaugeHP;

    QLabel *boostAttack;
    QLabel *boostDefense;
    QLabel *boostSpeed;

    ClickableLabel *clicker;
};

#endif // ENEMYUI_H
